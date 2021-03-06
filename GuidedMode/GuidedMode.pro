#-------------------------------------------------
#
# Project created by QtCreator 2019-01-28T19:11:02
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = GuidedMode
TEMPLATE = app

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
        sGuidedMode.cpp \
    sSettingDialog.cpp \
    cGloabalParam.cpp \
    Tools/sThread.cpp \
    sChartWidget.cpp \
    sCoreComputation.cpp

HEADERS += \
        sGuidedMode.h \
    sSettingDialog.h \
    cGloabalParam.h \
    Tools/sThread.h \
    sChartWidget.h \
    sCoreComputation.h

FORMS += \
        sGuidedMode.ui \
    sSettingDialog.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

win32: LIBS += -L$$PWD/../../../Lib/Armadillo/lib/ -llibarmadillo.dll

INCLUDEPATH += $$PWD/../../../Lib/Armadillo/include
DEPENDPATH += $$PWD/../../../Lib/Armadillo/include

include(D:/Lib/Qwt-6.1.4/features/qwt.prf)

RESOURCES += \
    defaultresource.qrc
