QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    bool3S.cpp \
    circuito.cpp \
    main.cpp \
    maincircuito.cpp \
    mudarporta.cpp \
    mudarsaida.cpp \
    novo.cpp

HEADERS += \
    bool3S.h \
    circuito.h \
    maincircuito.h \
    mudarporta.h \
    mudarsaida.h \
    novo.h

FORMS += \
    maincircuito.ui \
    mudarporta.ui \
    mudarsaida.ui \
    novo.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
