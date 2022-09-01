#ifndef DIALOG_6_H
#define DIALOG_6_H

#include <QDialog>

#include "WindowTemplates/DialogTemplate.h"

namespace Ui {
class Dialog_6;
}

class Dialog_6 : public DialogTemplate {
    Q_OBJECT

public:
    explicit Dialog_6(QWidget *parent);
    ~Dialog_6();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_6 *ui;
};

#endif  // DIALOG_6_H
