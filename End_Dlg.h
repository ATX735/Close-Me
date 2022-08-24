#ifndef END_DLG_H
#define END_DLG_H

#include <QDialog>

#include "GlobalData.h"
#include "WindowTemplates/DialogTemplate.h"

namespace Ui {
class End_Dlg;
}

class End_Dlg : public QDialog {
    Q_OBJECT

public:
    End_Dlg(QWidget *parent = nullptr, const QString message = GlobalData::GetInstance().end_text_default);
    ~End_Dlg();

private slots:
    void on_close_Ptn_clicked();

private:
    Ui::End_Dlg *ui;
    void closeEvent(QCloseEvent *event);
};

#endif  // END_DLG_H
