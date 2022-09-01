#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

#include "Dialog_3.h"

#include <End_Dlg.h>

#include <QDebug>
#include <QMouseEvent>
#include <QPainter>
#include <QResizeEvent>
#include <QScreen>

#include "Dialog_4.h"
#include "GlobalData.h"
#include "Utils.h"
#include "ui_Dialog_3.h"

Dialog_3::Dialog_3(QWidget* parent) : DialogTemplate(parent), ui(new Ui::Dialog_3) {
    ui->setupUi(this);

    QString win_title = "You have missed " + QString::number(GlobalData::GetInstance().miss_count) + " chances to close me";
    setWindowTitle(win_title);
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint);  // disable close window

    // obtain player screen size
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect mm = screen->availableGeometry();
    int screen_width = mm.width();
    int screen_height = mm.height();

    resize(this->dialog_initial_width, this->dialog_initial_height);

    // setup ui
    QString label_text =
        "Exactly. However, there is a way to close me, which is hiding \nin this dialog. I'm going to give you " +
        QString::number(countdown) + " seconds to find it.";
    ui->label->setText(label_text);
    ui->label->adjustSize();
    int label_x_coord = this->dialog_initial_width / 2 - ui->label->width() / 2;
    int label_y_coord = this->dialog_initial_height / 2 - ui->label->height() / 2;
    ui->label->setGeometry(label_x_coord, label_y_coord, ui->label->width(), ui->label->height());
    ui->label->installEventFilter(this);

    ui->weird_1_Ptn->adjustSize();
    int weird_1_Ptn_x_coord = screen_width - 300;
    ui->weird_1_Ptn->move(weird_1_Ptn_x_coord, label_y_coord);
    ui->weird_1_Ptn->adjustSize();
    ui->weird_1_Ptn->setFocusPolicy(Qt::NoFocus);

    ui->weird_2_Ptn->move(label_x_coord, screen_height - 200);
    ui->weird_2_Ptn->adjustSize();
    ui->weird_2_Ptn->setFocusPolicy(Qt::NoFocus);
    connect(ui->weird_2_Ptn, &QPushButton::clicked, this, &Dialog_3::handle_weird_2_Ptn_clicked1);

    // setup timer, start countdown
    timer = new QTimer;
    timer->start(this->countdown * 1000);
    connect(timer, SIGNAL(timeout()), this, SLOT(Handle_TimeOut()));
}

Dialog_3::~Dialog_3() { delete ui; }

bool Dialog_3::eventFilter(QObject* obj, QEvent* event) {
    if (obj == ui->label) {
        if (event->type() == QEvent::MouseButtonPress) {
            QMouseEvent* mouseEvent = static_cast<QMouseEvent*>(event);

            if (this->is_timeout && mouseEvent->button() == Qt::LeftButton) {
                Handle_label_clicked();
                return true;
            } else {
                return false;
            }
        } else {
            return false;
        }
    } else {
        // pass the event on to the parent class
        return DialogTemplate::eventFilter(obj, event);
    }
}

void Dialog_3::resizeEvent(QResizeEvent* event) {
    if (!this->is_weird_1_Ptn_clicked && (event->oldSize().height() >= this->dialog_initial_height)) {
        resize(event->size().width(), this->dialog_initial_height);
        if (this->width() > ui->weird_1_Ptn->pos().x()) this->timer->stop();
    }
}

void Dialog_3::on_weird_1_Ptn_clicked() {
    this->is_weird_1_Ptn_clicked = true;
    Utils::DisplayMessageBox(
        tr("Since you have found this button, why not stretch the dialog further and "
           "see what is at bottom of the dialog."));
}

void Dialog_3::handle_weird_2_Ptn_clicked1() {
    // successfully exit
    QSharedPointer<End_Dlg> end = QSharedPointer<End_Dlg>(new End_Dlg(this));
    end->exec();
}

void Dialog_3::handle_weird_2_Ptn_clicked2() { Utils::DisplayMessageBox(tr("Just click the text up there")); }

void Dialog_3::Handle_label_clicked() {
    GlobalData::GetInstance().miss_count++;
    QSharedPointer<Dialog_4> dlg = QSharedPointer<Dialog_4>(new Dialog_4(nullptr));
    this->hide();
    dlg->exec();
}

void Dialog_3::Handle_TimeOut() {
    this->timer->stop();
    this->is_timeout = true;
    disconnect(ui->weird_2_Ptn, &QPushButton::clicked, this, &Dialog_3::handle_weird_2_Ptn_clicked1);
    connect(ui->weird_2_Ptn, &QPushButton::clicked, this, &Dialog_3::handle_weird_2_Ptn_clicked2);
    Utils::DisplayMessageBox(
        tr("Time up. I have to admit that I overestimate your intelligence. \nWhy not try to resize the dialog and see what you "
           "can find. "
           "I recommend you search from the right side first."));
}
