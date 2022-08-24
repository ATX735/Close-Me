#include "Dialog_1.h"

#include <QCloseEvent>
#include <QDebug>

#include "GlobalData.h"
#include "StoryLine/Dialog_2.h"
#include "Utils.h"
#include "ui_Dialog_1.h"

Dialog_1::Dialog_1(QWidget *parent) : DialogTemplate(parent), ui(new Ui::Dialog_1) {
    ui->setupUi(this);

    setWindowTitle(tr("A Dialog"));
    resize(QSize(GlobalData::GetInstance().dialog_width, GlobalData::GetInstance().dialog_height));
    //    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint & ~Qt::WindowContextHelpButtonHint);

    //    QApplication::beep();

    ui->message_label->setText(
        tr("Congratulation! You have find your way to close me. Please click the button below this message and exit the game."));
    ui->message_label->setWordWrap(true);
}

Dialog_1::~Dialog_1() { delete ui; }

void Dialog_1::closeEvent(QCloseEvent *event) {
    Utils::displayMessageBox(tr("I said, click the button below! Not this one!"));
    event->ignore();
}

void Dialog_1::on_pushButton_clicked() {
    QSharedPointer<Dialog_2> dlg = QSharedPointer<Dialog_2>(new Dialog_2(this));
    this->hide();
    dlg->exec();
}
