#include "Utils.h"

#include <Windows.h>
Utils::Utils() {}

void Utils::beepType_1() { Beep(450, 1000); }

void Utils::displayMessageBox(const QString message) {
    QMessageBox msgBox;
    msgBox.setText(message);
    msgBox.exec();
}
