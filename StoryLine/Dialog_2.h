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
    explicit Dialog_2(QWidget *parent = nullptr);
    ~Dialog_2();

private slots:
    void on_No_Ptn_clicked();

    void on_Yes_Ptn_clicked();  // include a way to close the game

private:
    Ui::Dialog_2 *ui;
    int yes_ptn_click_count = 0;  // record how many time player click the "Yes" button

    void closeEvent(QCloseEvent *event);
};

#endif  // DIALOG_2_H
