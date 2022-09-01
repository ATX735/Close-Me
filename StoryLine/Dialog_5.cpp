#include "Dialog_5.h"

#include <QDebug>
#include <QKeyEvent>
#include <QPushButton>
#include <QRandomGenerator>
#include <QTimer>

#include "Dialog_6.h"
#include "End_Dlg.h"
#include "GlobalData.h"
#include "Utils.h"
#include "ui_Dialog_5.h"

Dialog_5::Dialog_5(int clicked_button_index, QWidget *parent)
    : DialogTemplate(parent), ui(new Ui::Dialog_5), game_difficulty(clicked_button_index) {
    ui->setupUi(this);
    setFixedSize(800, 600);
    setWindowTitle(tr("A Marvelous Game"));

    ui->movable_PBtn->move(10, 10);
    ui->movable_PBtn->setFocusPolicy(Qt::NoFocus);

    ui->label->setText("Click the button to close me.\nYou got " + QString::number(game_time) + " seconds.");
    ui->label->adjustSize();
    int label_x_coord = this->width() / 2 - ui->label->width() / 2;
    int label_y_coord = this->height() / 2 - ui->label->height() / 2;
    ui->label->move(label_x_coord, label_y_coord);

    // initiate difficulty_update_time variable
    this->difficulty_update_time.insert(1, 720);
    this->difficulty_update_time.insert(2, 600);
    this->difficulty_update_time.insert(3, 400);
    this->difficulty_update_time.insert(4, 20);

    InitGame();
}

Dialog_5::~Dialog_5() { delete ui; }

void Dialog_5::InitGame() {
    // obtain countdown time, millisecond as unit
    int countdown_ms = -1;
    if (this->difficulty_update_time.contains(this->game_difficulty)) {
        countdown_ms = this->difficulty_update_time.find(this->game_difficulty).value();
    } else {
        Utils::DisplayMessageBox(tr("Game difficulty not exist"));
        qApp->exit();
    }

    move_timer = new QTimer;
    move_timer->start(countdown_ms);
    connect(move_timer, &QTimer::timeout, this, &Dialog_5::Handle_MoveTimer_TimeOut);

    game_timer = new QTimer;
    game_timer->start(this->game_time * 1000);
    connect(game_timer, &QTimer::timeout, this, &Dialog_5::Handle_GameTimer_TimeOut);
}

void Dialog_5::StopGame() {
    this->game_timer->stop();
    this->move_timer->stop();
}

QPoint Dialog_5::GetNewCoord() {
    QPoint ret;

    // obtain the position of cursor
    int cursor_x = this->mapFromGlobal(QCursor().pos()).x();
    int cursor_y = this->mapFromGlobal(QCursor().pos()).y();

    // the gap between the cursor and the new coord of the movable button
    int cursor_gap_x = ui->movable_PBtn->width() * 2;
    int cursor_gap_y = ui->movable_PBtn->height() * 8;

    int new_x_bound = this->width() - ui->movable_PBtn->width();
    int new_y_bound = this->height() - ui->movable_PBtn->height();

    // generate new coordinate for the movable button
    while (true) {
        int new_x = QRandomGenerator::global()->bounded(new_x_bound);
        int new_y = QRandomGenerator::global()->bounded(new_y_bound);

        // if new coord is near the cursor, continue to find new coord, until find a proper coord
        if (new_x + ui->movable_PBtn->width() / 2 > cursor_x - cursor_gap_x &&
            new_x + ui->movable_PBtn->width() / 2 < cursor_x + cursor_gap_x &&
            new_y + ui->movable_PBtn->height() / 2 > cursor_y - cursor_gap_y &&
            new_y + ui->movable_PBtn->height() / 2 < cursor_y + cursor_gap_y) {
            continue;
        } else {
            ret.setX(new_x);
            ret.setY(new_y);
            break;
        }
    }

    return ret;
}

void Dialog_5::on_movable_PBtn_clicked() {
    StopGame();
    // successfully exit
    QSharedPointer<End_Dlg> end = QSharedPointer<End_Dlg>(new End_Dlg(this));
    end->exec();
}

void Dialog_5::Handle_MoveTimer_TimeOut() {
    QPoint button_new_coord = GetNewCoord();
    ui->movable_PBtn->move(button_new_coord);
}

void Dialog_5::Handle_GameTimer_TimeOut() {
    StopGame();
    GlobalData::GetInstance().miss_count++;
    Utils::DisplayMessageBox(tr("Game Over! You have fail to close me."));
    this->hide();
    QSharedPointer<Dialog_6> dlg = QSharedPointer<Dialog_6>(new Dialog_6(nullptr));
    dlg->exec();
}
