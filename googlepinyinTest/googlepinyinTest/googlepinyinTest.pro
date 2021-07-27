#-------------------------------------------------
#
# Project created by QtCreator 2021-07-27T15:10:03
#
#-------------------------------------------------

QT       += core gui gui-private

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = googlepinyinTest
TEMPLATE = app

DESTDIR = bin
# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

win32:CONFIG(release, debug|release): LIBS += -L$$PWD/keyboardAll/pinyin/ -lgooglepinyin
else:win32:CONFIG(debug, debug|release): LIBS += -L$$PWD/keyboardAll/pinyin/ -lgooglepinyind

INCLUDEPATH += $$PWD/keyboardAll/pinyin
DEPENDPATH += $$PWD/keyboardAll/pinyin

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

CONFIG += c++11

SOURCES += \
        main.cpp \
        mainwindow.cpp \
    keyboardAll/googlepinyin.cpp \
    keyboardAll/inputcontext.cpp \
    keyboardAll/keyboardform.cpp \
    keyboardAll/keyeventdispatcher.cpp \
    keyboardAll/qlineeditallkeyboard.cpp

HEADERS += \
        mainwindow.h \
    keyboardAll/googlepinyin.h \
    keyboardAll/inputcontext.h \
    keyboardAll/keyboardform.h \
    keyboardAll/keyeventdispatcher.h \
    keyboardAll/qlineeditallkeyboard.h

FORMS += \
        mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
