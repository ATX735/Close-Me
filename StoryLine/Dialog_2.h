#ifndef DIALOG_2_H
#define DIALOG_2_H

#include <QDialog>

#include "WindowTemplates/DialogTemplate.h"

namespace Ui {
class Dialog_2;
}

class Dialog_2 : public DialogTemplate {
    Q_OBJECT

public:
    explicit Dialog_2(QWidget *parent);
    ~Dialog_2();

private slots:
    void on_No_Ptn_clicked();  // contain the process to next dialog

    void on_Yes_Ptn_clicked();  // contain a way to close the game

private:
    Ui::Dialog_2 *ui;
    int yes_ptn_click_count = 0;  // record how many time player click the "Yes" button
};

#endif  // DIALOG_2_H
