QT       += core gui sql

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

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
    addbook.cpp \
    administrator.cpp \
    adminlogin.cpp \
    borrow.cpp \
    changepassword.cpp \
    deletebook.cpp \
    deleteuser.cpp \
    editbookinfo.cpp \
    editperinfo.cpp \
    error.cpp \
    findout.cpp \
    first.cpp \
    histroy.cpp \
    homepage.cpp \
    main.cpp \
    perinfo.cpp \
    reserve.cpp \
    reward.cpp \
    search.cpp \
    sendback.cpp \
    signup.cpp

HEADERS += \
    addbook.h \
    administrator.h \
    adminlogin.h \
    borrow.h \
    changepassword.h \
    deletebook.h \
    deleteuser.h \
    editbookinfo.h \
    editperinfo.h \
    error.h \
    findout.h \
    first.h \
    histroy.h \
    homepage.h \
    perinfo.h \
    reserve.h \
    reward.h \
    search.h \
    sendback.h \
    signup.h

FORMS += \
    addbook.ui \
    administrator.ui \
    adminlogin.ui \
    borrow.ui \
    changepassword.ui \
    deletebook.ui \
    deleteuser.ui \
    editbookinfo.ui \
    editperinfo.ui \
    error.ui \
    findout.ui \
    first.ui \
    histroy.ui \
    homepage.ui \
    perinfo.ui \
    reserve.ui \
    reward.ui \
    search.ui \
    sendback.ui \
    signup.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target

RESOURCES +=
