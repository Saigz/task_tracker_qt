QT       += core gui \
    quick

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
    Database/database.cpp \
    UI/w_deck/NewCell/newcell.cpp \
    UI/w_deck/NewTab/newtab.cpp \
    UI/w_createdeck/createdeck.cpp \
    UI/w_deck/deck.cpp \
    UI/w_decklist/decklist.cpp \
    UI/w_login/loginwindow.cpp \
    UI/w_reg/registration.cpp \
    main.cpp

HEADERS += \
    UI/w_deck/NewCell/newcell.h \
    UI/w_deck/NewTab/newtab.h \
    nlohmann/json.hpp \
    Database/database.h \
    UI/w_createdeck/createdeck.h \
    UI/w_deck/deck.h \
    UI/w_decklist/decklist.h \
    UI/w_login/loginwindow.h \
    UI/w_reg/registration.h

FORMS += \
    UI/w_cell/cell.ui \
    UI/w_deck/NewCell/newcell.ui \
    UI/w_deck/NewTab/newtab.ui \
    UI/w_createdeck/createdeck.ui \
    UI/w_deck/deck.ui \
    UI/w_decklist/decklist.ui \
    UI/w_login/loginwindow.ui \
    UI/w_reg/registration.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

DISTFILES += \
    text.txt

RESOURCES += \
    other/resource.qrc

RC_FILE += "other/test.rc"
