QT       += core gui printsupport

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    credit.cpp \
    creditcalc.cpp \
    main.cpp \
    mainwindow.cc\
    qcustomplot.cpp \
    s21_controller.cpp \
    s21_model.cpp \
    stack.cpp

HEADERS += \
    credit.h \
    creditcalc.h \
    mainwindow.h\
    qcustomplot.h \
    s21_controller.h \
    s21_model.h \
    stack.h

FORMS += \
    creditcalc.ui \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
