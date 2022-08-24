#define min(a, b) ((a) < (b) ? (a) : (b))
#define max(a, b) ((a) > (b) ? (a) : (b))

#include "Dialog_3.h"

#include <QDebug>
#include <QMouseEvent>
#include <QPainter>
#include <QResizeEvent>
#include <QScreen>

#include "GlobalData.h"
#include "Utils.h"
#include "ui_Dialog_3.h"

Dialog_3::Dialog_3(QWidget* parent) : DialogTemplate(parent), ui(new Ui::Dialog_3) {
    ui->setupUi(this);

    // get screen size
    QScreen* screen = QGuiApplication::primaryScreen();
    QRect mm = screen->availableGeometry();
    int screen_width = mm.width();
    int screen_height = mm.height();

    resize(this->dialog_initial_width, this->dialog_initial_height);

    ui->label->setText(tr("Exactly. However, there is a way to close me, \nI'm going to give you 30 seconds to find it."));
    ui->label->adjustSize();
    int label_x_coord = this->dialog_initial_width / 2 - ui->label->width() / 2;
    int label_y_coord = this->dialog_initial_height / 2 - ui->label->height() / 2;
    ui->weird_1_Ptn->setGeometry(label_x_coord, label_y_coord, ui->label->width(), ui->label->height());

    ui->weird_1_Ptn->adjustSize();
    int weird_1_Ptn_x_coord =
        label_x_coord + 800 > screen_width - ui->weird_1_Ptn->width() ? label_x_coord + 800 : screen_width - 300;
    ui->weird_1_Ptn->setGeometry(weird_1_Ptn_x_coord, label_y_coord, 50, 10);
    ui->weird_1_Ptn->adjustSize();

    ui->weird_2_Ptn->setGeometry(label_x_coord, screen_height - 200, 50, 10);
    ui->weird_2_Ptn->adjustSize();
}

Dialog_3::~Dialog_3() { delete ui; }

void Dialog_3::resizeEvent(QResizeEvent* event) {
    if (!this->is_weird_1_Ptn_clicked && event->oldSize().height() >= this->dialog_initial_height) {
        event->ignore();
        resize(event->size().width(), this->dialog_initial_height);
    }
}

void Dialog_3::on_weird_1_Ptn_clicked() {
    this->is_weird_1_Ptn_clicked = true;
    Utils::displayMessageBox(
        tr("Since you have found this button, why not stretch the dialog further and "
           "see what is under this dialog."));
}

void Dialog_3::on_weird_2_Ptn_clicked() { Utils::displayMessageBox(tr("Just click the text label up there")); }
