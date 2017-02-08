QT += qml quick

CONFIG += c++11

SOURCES += \
    source/board.cpp \
    source/boardobject.cpp \
    source/bullet.cpp \
    source/computer.cpp \
    source/enemy.cpp \
    source/main.cpp \
    source/player.cpp \
    source/tank.cpp

RESOURCES += qml/qml.qrc

# Additional import path used to resolve QML modules in Qt Creator's code model
QML_IMPORT_PATH =

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    source/board.h \
    source/boardobject.h \
    source/bullet.h \
    source/computer.h \
    source/enemy.h \
    source/enums.h \
    source/player.h \
    source/tank.h

release {
    QT_NO_DEBUG_OUTPUT
}

DISTFILES += \
    qml/images/enemy.png \
    qml/images/player.png \
    qml/main.qml \
    qml/Page1.qml

