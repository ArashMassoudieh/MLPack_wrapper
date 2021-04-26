QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

CONFIG += c++11

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += include/
INCLUDEPATH += ../qcustomplot/

LIBS += /usr/lib/x86_64-linux-gnu/libmlpack.so
QMAKE_CXXFLAGS+= -fopenmp
QMAKE_LFLAGS +=  -fopenmp
LIBS += -lgomp -lpthread -larmadillo -lboost_serialization

SOURCES += \
    ANN_Regress.cpp \
    main.cpp \
    mainwindow.cpp \
    mlpack_wrapper.cpp

HEADERS += \
    ANN_Regress.h \
    mainwindow.h \
    mainwindow.h \
    mlpack_wrapper.h

FORMS += \
    mainwindow.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
