#ifndef START_WINDOW_H
#define START_WINDOW_H

#include <QMainWindow>

namespace Ui {
class Start_Window;
}

class Start_Window : public QMainWindow {
    Q_OBJECT

public:
    explicit Start_Window(QWidget *parent = nullptr);
    ~Start_Window();

private slots:
    void on_start_Ptn_clicked();

    void on_quit_Ptn_clicked();

    void on_English_Action_triggered();

    void on_Chinese_Action_triggered();

    void on_actionI_Need_Help_triggered();

private:
    Ui::Start_Window *ui;

    int close_counter = 0;
    int quit_limit = 30;

    // include a way to close the game
    void closeEvent(QCloseEvent *event) override;
};

#endif  // START_WINDOW_H
