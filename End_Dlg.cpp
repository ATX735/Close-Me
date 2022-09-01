#include "End_Dlg.h"

#include <QCloseEvent>

#include "GlobalData.h"
#include "ui_End_Dlg.h"

End_Dlg::End_Dlg(QWidget *parent, const QString message) : QDialog(parent), ui(new Ui::End_Dlg) {
    ui->setupUi(this);

    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    resize(QSize(360, 240));

    ui->message_label->setText(message);
    ui->message_label->setWordWrap(true);
}

End_Dlg::~End_Dlg() { delete ui; }

void End_Dlg::on_close_Ptn_clicked() { qApp->quit(); }

void End_Dlg::closeEvent(QCloseEvent *event) { qApp->quit(); }
