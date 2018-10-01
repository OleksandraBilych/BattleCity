QT += qml quick

CONFIG += c++11
CONFIG(release, debug|release):DEFINES += QT_NO_DEBUG_OUTPUT

SOURCES += \
    main.cpp \
    tank.cpp \
    player.cpp \
    enemy.cpp \
    boardobject.cpp \
    bullet.cpp \
    board.cpp \
    cell.cpp \
    bulletAI.cpp \
    mainAI.cpp \
    tankAI.cpp \
    objectscleaner.cpp \
    wall.cpp \
    playersbase.cpp \
    globalvariables.cpp

RESOURCES += qml.qrc

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

HEADERS += \
    tank.h \
    enums.h \
    player.h \
    enemy.h \
    boardobject.h \
    bullet.h \
    board.h \
    cell.h \
    cell.h \
    player.h \
    board.h \
    bulletAI.h \
    mainAI.h \
    tankAI.h \
    objectscleaner.h \
    wall.h \
    playersbase.h \
    constants.h \
    globalvariables.h \
    globalvariables.h
