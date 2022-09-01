#include "Dialog_6.h"

#include "End_Dlg.h"
#include "ui_Dialog_6.h"

Dialog_6::Dialog_6(QWidget *parent) : DialogTemplate(parent), ui(new Ui::Dialog_6) { ui->setupUi(this); }

Dialog_6::~Dialog_6() { delete ui; }

void Dialog_6::on_pushButton_clicked() {
    // successfully exit
    QSharedPointer<End_Dlg> end = QSharedPointer<End_Dlg>(new End_Dlg(this));
    end->exec();
}
