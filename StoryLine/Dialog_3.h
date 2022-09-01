#ifndef DIALOG_3_H
#define DIALOG_3_H

#define EDGE_MARGIN 20

#include <QDialog>
#include <QTimer>

#include "WindowTemplates/DialogTemplate.h"

namespace Ui {
class Dialog_3;
}

class Dialog_3 : public DialogTemplate {
    Q_OBJECT

public:
    explicit Dialog_3(QWidget *parent);
    ~Dialog_3();

private:
    Ui::Dialog_3 *ui;
    int dialog_initial_width = 800;
    int dialog_initial_height = 300;

    QTimer *timer;
    int countdown = 20;  // timer countdown seconds
    bool is_timeout = false;

    bool is_weird_1_Ptn_clicked = false;

    bool eventFilter(QObject *obj, QEvent *event) override;

    void resizeEvent(QResizeEvent *size) override;

private slots:
    void on_weird_1_Ptn_clicked();

    void Handle_TimeOut();

    // contain a way to close the game
    void handle_weird_2_Ptn_clicked1();

    void handle_weird_2_Ptn_clicked2();

    // contain a way to next story
    void Handle_label_clicked();
};

#endif  // DIALOG_3_H
