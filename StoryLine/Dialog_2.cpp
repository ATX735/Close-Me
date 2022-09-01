
#include "Dialog_2.h"

#include <QCloseEvent>

#include "Dialog_3.h"
#include "End_Dlg.h"
#include "GlobalData.h"
#include "Utils.h"
#include "ui_Dialog_2.h"

Dialog_2::Dialog_2(QWidget *parent) : DialogTemplate(parent), ui(new Ui::Dialog_2) {
    ui->setupUi(this);
    setWindowTitle(tr("An Annoying Dialog"));
    resize(QSize(GlobalData::GetInstance().dialog_width, GlobalData::GetInstance().dialog_height));
    setWindowFlags(windowFlags() & ~Qt::WindowCloseButtonHint & ~Qt::WindowContextHelpButtonHint);

    ui->label->setText(tr("Nah, I'm just joking. You really expect that this little clicking could shut me down?"));
    ui->label->setWordWrap(true);

    ui->No_Ptn->setFocusPolicy(Qt::NoFocus);
    ui->Yes_Ptn->setFocusPolicy(Qt::NoFocus);
}

Dialog_2::~Dialog_2() { delete ui; }

void Dialog_2::on_No_Ptn_clicked() {
    GlobalData::GetInstance().miss_count++;
    QSharedPointer<Dialog_3> dlg = QSharedPointer<Dialog_3>(new Dialog_3(nullptr));
    this->hide();
    dlg->exec();
}

void Dialog_2::on_Yes_Ptn_clicked() {
    this->yes_ptn_click_count++;

    if (this->yes_ptn_click_count <= 1)
        Utils::DisplayMessageBox(tr("Too Young Too Simple."));
    else if (this->yes_ptn_click_count <= 2)
        Utils::DisplayMessageBox(tr("Don't make the same mistake twice, even 14-year-old child knew that."));
    else if (this->yes_ptn_click_count <= 100) {
        QString message = "";
        for (int i = 1; i <= this->yes_ptn_click_count; ++i) message += tr("Wrong Answer! ");
        Utils::DisplayMessageBox(message);
    } else {
        // successfully exit
        QSharedPointer<End_Dlg> end = QSharedPointer<End_Dlg>(new End_Dlg(this, GlobalData::GetInstance().end_text_1));
        end->exec();
    }
}
