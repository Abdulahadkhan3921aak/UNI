QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

# Replace "icon_filename" with the actual filename of your icon file
RESOURCES += resources.qrc


win32 {
    RC_FILE = icon.rc
}


SOURCES += \
    main.cpp \
    mainwindow.cpp \
    phonebook.cpp \


HEADERS += \
    mainwindow.h \
    phonebook.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
