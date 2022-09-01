#ifndef DIALOG_4_H
#define DIALOG_4_H

#include <QDialog>

#include "WindowTemplates/DialogTemplate.h"

namespace Ui {
class Dialog_4;
}

class Dialog_4 : public DialogTemplate {
    Q_OBJECT

public:
    explicit Dialog_4(QWidget *parent);
    ~Dialog_4();

private slots:
    void on_choice1_PBtn_clicked();

    void on_choice2_PBtn_clicked();

    void on_choice3_PBtn_clicked();

    void on_choice4_PBtn_clicked();

private:
    Ui::Dialog_4 *ui;

    void StartGame(int clicked_button_index);
};

#endif  // DIALOG_4_H
