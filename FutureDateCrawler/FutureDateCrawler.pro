#-------------------------------------------------
#
# Project created by QtCreator 2015-09-04T00:01:47
#
#-------------------------------------------------

QT       += core
QT       += network
QT       -= gui

TARGET = FutureDateCrawler
CONFIG   += console
CONFIG   -= app_bundle

TEMPLATE = app


SOURCES += main.cpp \
    futuredata.cpp \
    networker.cpp

HEADERS += \
    futuredata.h \
    networker.h
