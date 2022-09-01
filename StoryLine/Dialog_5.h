#ifndef DIALOG_5_H
#define DIALOG_5_H

#include <QDialog>
#include <QMap>
#include <QTimer>

#include "WindowTemplates/DialogTemplate.h"
namespace Ui {
class Dialog_5;
}

class Dialog_5 : public DialogTemplate {
    Q_OBJECT

public:
    Dialog_5(int clicked_button_index, QWidget *parent);
    ~Dialog_5();

private slots:
    // contain a way to close the game
    void on_movable_PBtn_clicked();

    // move the movable button when move_timer trigered timeout event
    void Handle_MoveTimer_TimeOut();

    // contain a way to next story
    void Handle_GameTimer_TimeOut();

private:
    Ui::Dialog_5 *ui;

    int game_difficulty;                    // 1 <= game_difficulty <= 4, bigger the number harder the game
    QMap<int, int> difficulty_update_time;  // stores the mapping of difficulty to update time

    QTimer *move_timer, *game_timer;
    int game_time = 30;  // the time that the game will sustain, second as unit

    void InitGame();
    void StopGame();
    QPoint GetNewCoord();
};

#endif  // DIALOG_5_H
