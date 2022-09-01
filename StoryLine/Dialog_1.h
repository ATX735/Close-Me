#ifndef DIALOG_1_H
#define DIALOG_1_H

#include <QDialog>

#include "WindowTemplates/DialogTemplate.h"

namespace Ui {
class Dialog_1;
}

class Dialog_1 : public DialogTemplate {
    Q_OBJECT

public:
    explicit Dialog_1(QWidget *parent);
    ~Dialog_1();

private slots:
    void on_pushButton_clicked();

private:
    Ui::Dialog_1 *ui;
    void closeEvent(QCloseEvent *event) override;
};

#endif  // DIALOG_1_H
