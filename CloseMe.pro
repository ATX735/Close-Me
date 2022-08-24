#-------------------------------------------------
#
# Project created by QtCreator 2022-08-21T10:11:01
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CloseMe
TEMPLATE = app
TRANSLATIONS = Chinese_Translation.ts
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
    Utils.cpp \
    WindowTemplates/DialogTemplate.cpp \
    StoryLine/Dialog_1.cpp \
    End_Dlg.cpp \
    Start_Window.cpp \
    StoryLine/Dialog_2.cpp \
    GlobalData.cpp \
    StoryLine/Dialog_3.cpp

HEADERS += \
    Utils.h \
    WindowTemplates/DialogTemplate.h \
    End_Dlg.h \
    Start_Window.h \
    StoryLine/Dialog_1.h \
    StoryLine/Dialog_2.h \
    GlobalData.h \
    StoryLine/Dialog_3.h

FORMS += \
    WindowTemplates/DialogTemplate.ui \
    StoryLine/Dialog_1.ui \
    End_Dlg.ui \
    Start_Window.ui \
    StoryLine/Dialog_2.ui \
    StoryLine/Dialog_3.ui



# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES += \
    resource.qrc
