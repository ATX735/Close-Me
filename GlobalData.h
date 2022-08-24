#ifndef GLOBALDATA_H
#define GLOBALDATA_H
#include <QApplication>

// use for indicate the UI language
enum class Language { English, Chinese };

// This is a singleton class, which stores the global data.
class GlobalData {
public:
    GlobalData(GlobalData&) = delete;
    GlobalData& operator=(const GlobalData&) = delete;

    static GlobalData& GetInstance() {
        static GlobalData instance;
        return instance;
    }

    Language current_language = Language::English;  // indicate the current UI language

    QApplication* app = nullptr;  // use this pointer to ultimately exit the program
    int miss_count = 0;           // the chances that player has miss, representing how many times player has missed

    // size of the story dialog
    int dialog_width = 400;
    int dialog_height = 200;

    // end window label text
    QString end_text_default = QObject::tr("Congratulation! You lucky fucker have found a way to close me. Have a great day!");
    QString end_text_1 =
        QObject::tr("You're such a relentless idiot. Congratulation! You have found a way to close me. Have a great day!");

private:
    GlobalData();
};

#endif  // GLOBALDATA_H
