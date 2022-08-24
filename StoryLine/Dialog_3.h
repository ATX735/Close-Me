#ifndef DIALOG_3_H
#define DIALOG_3_H

#define EDGE_MARGIN 20

#include <QDialog>

#include "WindowTemplates/DialogTemplate.h"

namespace Ui {
class Dialog_3;
}

class Dialog_3 : public DialogTemplate {
    Q_OBJECT

public:
    explicit Dialog_3(QWidget *parent = nullptr);
    ~Dialog_3();

private slots:
    void on_weird_1_Ptn_clicked();

    void on_weird_2_Ptn_clicked();

private:
    Ui::Dialog_3 *ui;
    int dialog_initial_width = 800;
    int dialog_initial_height = 300;

    bool is_weird_1_Ptn_clicked = false;

    void resizeEvent(QResizeEvent *size);
};

#endif  // DIALOG_3_H
