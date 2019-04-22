#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QImage>
#include <QPushButton>
#include <QGraphicsScene>
#include <QGraphicsView>
#include <camera.h>
#include <ray.h>
#include<iostream>
#include <sphere.h>
#include <squareplane.h>
#include <glm/gtc/type_ptr.hpp>
#include <scene.h>
#include <QFileDialog>
#include "pointlight.h"
#include "lambertmaterial.h"
#include "blinnphongmaterial.h"
#include "specularreflectionmaterial.h"
#include "speculartransmissionmaterial.h"
#include "arealight.h"
#include "disc.h"
#include "ambientocclusion.h"

namespace Ui {
class MainWindow;
}

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    explicit MainWindow(QWidget *parent = 0);
    ~MainWindow();

    void DisplayQImage(QImage &i);
    void RenderTest0();
    void RenderTest1();
    void RenderTest2();
    void RenderTest3();
    void RenderScene();

    void RenderCornellBox();
    void RenderCornellBox2();
    void RenderReflectionRefraction();

    void RenderAreaLightTest();
    void RenderOcclusion();
    void RenderCornellBoxWithAmbient();
    void RenderCornellBox2WithAreaLight();

    void SaveImage();
    Camera m_camera;
    Scene m_scene;

private slots:
    void renderImg();

private:
    Ui::MainWindow *ui;
    QPushButton *m_button;

    QGraphicsScene m_graphics_scene;
    QGraphicsView *m_graphics_view;
    QImage m_renderedImg;
};

#endif // MAINWINDOW_H
