QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17
# LIBS += -lmsgpack

INCLUDEPATH += /usr/local/include/msgpack
INCLUDEPATH += /usr/local/include

# The following define makes your compiler emit warnings if you use
# any Qt feature that has been marked deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += \
    addfriend.cpp \
    bbsnewpost.cpp \
    chatface.cpp \
    chatmessage.cpp \
    client.cpp \
    come_message.cpp \
    common.cpp \
    controller.cpp \
    contactitem.cpp \
    creategroup.cpp \
    emojiwidget.cpp \
    feverrpc/feverrpc-client.cpp \
    feverrpc/feverrpc-factory.cpp \
    feverrpc/feverrpc-server.cpp \
    feverrpc/feverrpc.cpp \
    feverrpc/utils.cpp \
    friendrequest.cpp \
    main.cpp \
    mainwindow.cpp \
    widget.cpp

HEADERS += \
    addfriend.h \
    bbsnewpost.h \
    chatface.h \
    chatmessage.h \
    client.h \
    come_message.h \
    common.h \
    controller.h \
    contactitem.h \
    creategroup.h \
    emojiwidget.h \
    feverrpc/feverrpc-client.hpp \
    feverrpc/feverrpc-factory.hpp \
    feverrpc/feverrpc-server.hpp \
    feverrpc/feverrpc.hpp \
    feverrpc/utils.hpp \
    friendrequest.h \
    info_code.h \
    mainwindow.h \
    widget.h

FORMS += \
    addfriend.ui \
    bbsnewpost.ui \
    chatface.ui \
    come_message.ui \
    contactitem.ui \
    creategroup.ui \
    emoji.ui \
    emojiwidget.ui \
    friendrequest.ui \
    mainwindow.ui \
    widget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    Chatface.qml \
    ChatfaceForm.ui.qml \
    image/arrow down.png \
    image/arrow-right.png

RESOURCES += \
    image.qrc
