QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets core gui printsupport

CONFIG += c++17

# You can make your code fail to compile if it uses deprecated APIs.
# In order to do so, uncomment the following line.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

INCLUDEPATH += include/
INCLUDEPATH += ../qcustomplot/
INCLUDEPATH += ../Utilities/
#LIBS += /usr/lib/x86_64-linux-gnu/libmlpack.so
LIBS += /usr/local/lib/libmlpack.so
QMAKE_CXXFLAGS+= -fopenmp
QMAKE_LFLAGS +=  -fopenmp
LIBS += -lgomp -lpthread -larmadillo -lboost_serialization
DEFINES += _arma

SOURCES += \
    ../../../../home/arash/Projects/qcustomplot/qcustomplot.cpp \
    ../Utilities/DistributionNUnif.cpp \
    ../Utilities/Matrix.cpp \
    ../Utilities/Matrix_arma.cpp \
    ../Utilities/Matrix_arma_sp.cpp \
    ../Utilities/NormalDist.cpp \
    ../Utilities/QuickSort.cpp \
    ../Utilities/Utilities.cpp \
    ../Utilities/Vector.cpp \
    ../Utilities/Vector_arma.cpp \
    customplotwidget.cpp \
    main.cpp \
    mainwindow.cpp \
    mlpack_wrapper.cpp \
    plotter.cpp \
    testfunc.cpp

HEADERS += \
    ../../../../home/arash/Projects/qcustomplot/qcustomplot.h \
    ../Utilities/BTC.h \
    ../Utilities/BTCSet.h \
    ../Utilities/BTC.hpp \
    ../Utilities/BTCSet.hpp \
    ../Utilities/Matrix.h \
    ../Utilities/Matrix_arma.h \
    ../Utilities/Matrix_arma_sp.h \
    ../Utilities/NormalDist.h \
    ../Utilities/QuickSort.h \
    ../Utilities/Utilities.h \
    ../Utilities/Vector.h \
    ../Utilities/Vector_arma.h \
    customplotwidget.h \
    mainwindow.h \
    mlpack_wrapper.h \
    plotter.h \
    testfunc.h

FORMS += \
    customplotwidget.ui \
    mainwindow.ui \
    plotter.ui \
    plotterwidget.ui

# Default rules for deployment.
qnx: target.path = /tmp/$${TARGET}/bin
else: unix:!android: target.path = /opt/$${TARGET}/bin
!isEmpty(target.path): INSTALLS += target
