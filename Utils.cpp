#include "Utils.h"

#include <Windows.h>
Utils::Utils() {}

void Utils::BeepType_1() { Beep(450, 1000); }

void Utils::DisplayMessageBox(const QString message) {
    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.exec();
}

char* Utils::QstringToCharArray(const QString str) {
    QByteArray ba = str.toLatin1();
    char* ca = ba.data();
    return ca;
}
