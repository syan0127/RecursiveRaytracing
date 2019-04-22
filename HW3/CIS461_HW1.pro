#-------------------------------------------------
#
# Project created by QtCreator 2019-01-24T12:01:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CIS461_HW1
TEMPLATE = app

INCLUDEPATH += include

# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

HEADERS += \
        mainwindow.h \
    ray.h \
    globalincludes.h \
    camera.h \
    intersection.h \
    transform.h \
    primitive.h \
    shape.h \
    scene.h \
    sphere.h \
    squareplane.h \
    camera.h \
    globalincludes.h \
    intersection.h \
    mainwindow.h \
    primitive.h \
    ray.h \
    scene.h \
    shape.h \
    sphere.h \
    squareplane.h \
    transform.h \
    light.h \
    pointlight.h \
    material.h \
    lambertmaterial.h \
    blinnphongmaterial.h \
    specularreflectionmaterial.h \
    speculartransmissionmaterial.h \
    arealight.h \
    disc.h \
    sampler.h \
    utils.h \
    warpfunctions.h \
    enums.h \
    ambientocclusion.h \
    enums.h

FORMS += \
        mainwindow.ui

CONFIG += c++11
INCLUDEPATH += $$PWD
DEPENDPATH += $$ PWD

SOURCES += \
    camera.cpp \
    intersection.cpp \
    main.cpp \
    mainwindow.cpp \
    primitive.cpp \
    ray.cpp \
    scene.cpp \
    shape.cpp \
    sphere.cpp \
    squareplane.cpp \
    transform.cpp \
    light.cpp \
    pointlight.cpp \
    material.cpp \
    lambertmaterial.cpp \
    blinnphongmaterial.cpp \
    specularreflectionmaterial.cpp \
    speculartransmissionmaterial.cpp \
    arealight.cpp \
    disc.cpp \
    sampler.cpp \
    utils.cpp \
    warpfunctions.cpp \
    ambientocclusion.cpp
