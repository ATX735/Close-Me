#include "Start_Window.h"

#include <QCloseEvent>
#include <QDebug>
#include <QSharedPointer>

#include "End_Dlg.h"
#include "GlobalData.h"
#include "StoryLine/Dialog_1.h"
#include "Utils.h"
#include "ui_Start_Window.h"

Start_Window::Start_Window(QWidget *parent) : QMainWindow(parent), ui(new Ui::Start_Window) {
    ui->setupUi(this);
    setWindowTitle("Close Me");
    setWindowFlags(windowFlags() & ~Qt::WindowMinimizeButtonHint & ~Qt::WindowMinMaxButtonsHint);

    //应用QSS文件到本窗口，所有以本窗口为祖先的窗口都会自动应用此QSS
    QFile qss(":/QSS/QSS/global_style.qss");
    if (qss.open(QIODevice::ReadOnly)) {
        QString styleSheet = qss.readAll();
        setStyleSheet(styleSheet);
    }
}

Start_Window::~Start_Window() { delete ui; }

void Start_Window::closeEvent(QCloseEvent *event) {
    event->ignore();
    this->close_counter++;

    if (this->close_counter <= 1)
        Utils::displayMessageBox(tr("Oops~ The game has already started :)"));
    else if (this->close_counter <= 4)
        Utils::displayMessageBox(tr("Please stop, it won't work :("));
    else if (this->close_counter <= 5)
        Utils::displayMessageBox(tr("Hey! I said stop!"));
    else if (this->close_counter <= 10)
        Utils::displayMessageBox(tr("Whatever~ Do what you like. Idiot!"));
    else if (this->close_counter == this->quit_limit - 1)
        Utils::displayMessageBox(tr("God damn it!"));

    if (this->close_counter >= this->quit_limit) {
        // successfully exit
        QSharedPointer<End_Dlg> end = QSharedPointer<End_Dlg>(new End_Dlg(this));
        end->exec();
    }
}

void Start_Window::on_start_Ptn_clicked() {
    GlobalData::GetInstance().miss_count++;
    QSharedPointer<Dialog_1> dlg = QSharedPointer<Dialog_1>(new Dialog_1(this));
    this->hide();
    dlg->exec();
}

void Start_Window::on_quit_Ptn_clicked() { Utils::displayMessageBox(tr("Only the coward will click this button!")); }

void Start_Window::on_English_Action_triggered() {
    ui->English_Action->setChecked(true);
    ui->Chinese_Action->setChecked(false);
    GlobalData::GetInstance().current_language = Language::English;
}

void Start_Window::on_Chinese_Action_triggered() {
    ui->English_Action->setChecked(false);
    ui->Chinese_Action->setChecked(true);
    GlobalData::GetInstance().current_language = Language::Chinese;

    Utils::displayMessageBox(u8"懒得翻译");
}
