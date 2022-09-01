#ifndef UTILS_H
#define UTILS_H
#include <QMessageBox>
class Utils {
public:
    Utils();

    // generate a beep sound
    static void BeepType_1();

    // display a message box, param: message is the message you want to display
    static void DisplayMessageBox(const QString message);

    // convert QString to char array
    static char* QstringToCharArray(const QString str);
};

#endif  // UTILS_H
