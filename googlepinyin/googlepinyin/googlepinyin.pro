#-------------------------------------------------
#
# Project created by QtCreator 2017-10-26T16:11:08
#
#-------------------------------------------------

QT       -= gui

DESTDIR = bin

TARGET = googlepinyin
TEMPLATE = lib
CONFIG += staticlib

CONFIG(debug, debug|release) {
     mac: TARGET = $$join(TARGET,,,_debug)
     win32: TARGET = $$join(TARGET,,,d)
}

SOURCES += \
    dictbuilder.cpp \
    dictlist.cpp \
    dicttrie.cpp \
    lpicache.cpp \
    matrixsearch.cpp \
    mystdlib.cpp \
    ngram.cpp \
    pinyinime.cpp \
    searchutility.cpp \
    spellingtable.cpp \
    spellingtrie.cpp \
    splparser.cpp \
    sync.cpp \
    userdict.cpp \
    utf16char.cpp \
    utf16reader.cpp

HEADERS += \
    atomdictbase.h \
    dictbuilder.h \
    dictdef.h \
    dictlist.h \
    dicttrie.h \
    lpicache.h \
    matrixsearch.h \
    mystdlib.h \
    ngram.h \
    pinyinime.h \
    searchutility.h \
    spellingtable.h \
    spellingtrie.h \
    splparser.h \
    sync.h \
    userdict.h \
    utf16char.h \
    utf16reader.h
