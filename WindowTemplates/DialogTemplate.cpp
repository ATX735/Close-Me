#include "DialogTemplate.h"

#include <QCloseEvent>

#include "GlobalData.h"
#include "Utils.h"
#include "ui_DialogTemplate.h"

DialogTemplate::DialogTemplate(QWidget *parent) : QDialog(parent), ui(new Ui::DialogTemplate) {
    ui->setupUi(this);
    qApp->installEventFilter(this);  // install the event filter to global qApp to filter event

    setWindowFlags(windowFlags() & ~Qt::WindowContextHelpButtonHint);
    resize(QSize(GlobalData::GetInstance().dialog_width, GlobalData::GetInstance().dialog_height));

    //应用QSS文件到本窗口，所有以本窗口为祖先的窗口都会自动应用此QSS
    QFile qss(":/QSS/QSS/global_style.qss");
    if (qss.open(QIODevice::ReadOnly)) {
        QString styleSheet = qss.readAll();
        setStyleSheet(styleSheet);
    }
}

DialogTemplate::~DialogTemplate() { delete ui; }

void DialogTemplate::closeEvent(QCloseEvent *event) {
    event->ignore();
    Utils::DisplayMessageBox(tr("Nice try. Unfortunately, I know what you know, I'm the devil in your mind. :P"));
}

bool DialogTemplate::eventFilter(QObject *obj, QEvent *event) {
    if (event->type() == QEvent::KeyPress) {
        QKeyEvent *key_event = static_cast<QKeyEvent *>(event);

        // capture Esc, Enter, Space keys, prevent player use keyboard to close the game or triger button click
        if (key_event->key() == Qt::Key_Escape || key_event->key() == Qt::Key_Enter || key_event->key() == Qt::Key_Space)
            return true;
    }

    return QObject::eventFilter(obj, event);  // standard event processing
}
