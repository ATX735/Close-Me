#include "Dialog_4.h"

#include "Dialog_5.h"
#include "GlobalData.h"
#include "Utils.h"
#include "ui_Dialog_4.h"

Dialog_4::Dialog_4(QWidget* parent) : DialogTemplate(parent), ui(new Ui::Dialog_4) {
    ui->setupUi(this);
    QString win_title = "You have missed " + QString::number(GlobalData::GetInstance().miss_count) + " chances to close me";
    setWindowTitle(win_title);

    ui->choice1_PBtn->setFocusPolicy(Qt::NoFocus);
    ui->choice2_PBtn->setFocusPolicy(Qt::NoFocus);
    ui->choice3_PBtn->setFocusPolicy(Qt::NoFocus);
    ui->choice4_PBtn->setFocusPolicy(Qt::NoFocus);

    ui->label->setText(tr(
        "Good boy, you literally do whatever I said, I like that. However, unfortunately you fail to close me in the limited "
        "time. Now we have to play one more game before you could close me. It's classic, I'm sure you will like it. Do you want "
        "to play it? :D"));
}

Dialog_4::~Dialog_4() { delete ui; }

void Dialog_4::on_choice1_PBtn_clicked() {
    Utils::DisplayMessageBox(tr("love you :D"));
    StartGame(1);
}

void Dialog_4::on_choice2_PBtn_clicked() { StartGame(2); }

void Dialog_4::on_choice3_PBtn_clicked() {
    Utils::DisplayMessageBox(tr("Yes you want"));
    StartGame(3);
}

void Dialog_4::on_choice4_PBtn_clicked() {
    Utils::DisplayMessageBox(tr("F you! Enjoy it!"));
    StartGame(4);
}

void Dialog_4::StartGame(int clicked_button_index) {
    this->hide();
    QSharedPointer<Dialog_5> dlg = QSharedPointer<Dialog_5>(new Dialog_5(clicked_button_index, nullptr));
    dlg->exec();
}
