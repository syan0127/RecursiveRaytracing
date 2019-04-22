#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    m_button = new QPushButton("Render", this);
    m_button->setGeometry(QRect(QPoint(160, 435), QSize(104, 51)));
//    m_camera = Camera(Point3f(5.5),
//                      Point3f(0, 0, 0),
//                      Vector3f(0, 1, 0),
//                      45.f, 0.1f, 1000.f, 400, 400);


    m_camera = Camera(Point3f(0, 0.5, 12),
                      Point3f(0, 0, 0),
                      Vector3f(0, 1, 0),
                      50.f, 0.1f, 1000.f, 400, 400);
    connect(m_button, SIGNAL (released()), this, SLOT (renderImg()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::DisplayQImage(QImage &i)
{
    QPixmap pixmap(QPixmap::fromImage(i));
    m_graphics_scene.addPixmap(pixmap);
    m_graphics_scene.setSceneRect(pixmap.rect());
    ui->graphicsView->setScene(&m_graphics_scene);
}

//function that fills up m_renderImg to the first test image (ray casting)
void MainWindow::RenderTest0()
{
    QImage image (400, 400, QImage::Format_RGB32);

    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            Point2f pixel(x, y);
            Ray ray = m_camera.rayCast(pixel);
            Vector3f rgb = (ray.m_direction + glm::vec3(1, 1, 1)) * 0.5f;
            rgb *= 255.f;
            image.setPixel(x, y, QColor(rgb.x, rgb.y, rgb.z).rgb());
        }
    };
    m_renderedImg = image;
}

//function that fills up m_renderImg to the second test image
//(untransformed sphere)
void MainWindow::RenderTest1()
{
    QImage image (400, 400, QImage::Format_RGB32);

    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            Point2f pixel(x, y);
            Shape *s = new Sphere();
            Ray ray = m_camera.rayCast(pixel);
            Intersection i;
            bool intersecting = s->getIntersection(ray, &i);
            if (intersecting) {
                Vector3f color = i.m_normal;
                color = glm::vec3(color + glm::vec3(1, 1, 1)) * 0.5f;
                image.setPixel(x, y, QColor(color.x * 255,
                                            color.y * 255,
                                            color.z * 255).rgb());
            }
        }
    };

    m_renderedImg = image;
}

//function that fills up m_renderImg to the third test image
//(untransformed square plane)
void MainWindow::RenderTest2()
{
    QImage image (400, 400, QImage::Format_RGB32);

    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            Point2f pixel(x, y);
            Shape *s = new SquarePlane();
//            Shape *s = new Disc();
            s->m_transform = Transform(glm::vec3(0),
                                                    glm::vec3(-90, 0, 0),
                                                    glm::vec3(10, 10, 1));
            Ray ray = m_camera.rayCast(pixel);
            Intersection i;
            bool intersecting = s->getIntersection(ray, &i);
            if (intersecting) {
                Vector3f color = i.m_normal;
                color = glm::vec3(color + glm::vec3(1, 1, 1)) * 0.5f;
                image.setPixel(x, y, QColor(color.x * 255,
                                            color.y * 255,
                                            color.z * 255).rgb());
            }
        }
    };

    m_renderedImg = image;
}

//function that fills up m_renderImg to the fourth test image
//(transformed sphere + transformed square plane)
void MainWindow::RenderTest3()
{
    QImage image (400, 400, QImage::Format_RGB32);
    Shape *s1 = new Sphere();
    s1->m_transform = Transform(glm::vec3(-1, 1, 0),
                                glm::vec3(0),
                                glm::vec3(2, 4, 2));

    Primitive *p1 = new Primitive(s1);

    Shape *sp = new SquarePlane();
    sp->m_transform = Transform(glm::vec3(0, 0, -5),
                                glm::vec3(0, 30, 0),
                                glm::vec3(10, 10, 1));
    Primitive *p2 = new Primitive(sp);

    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p1)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p2)));

    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            Point2f pixel(x, y);
            Ray ray = m_camera.rayCast(pixel);
            Intersection i;
            bool intersecting = m_scene.getIntersection(ray, & i);
            if (intersecting) {
                Vector3f color = i.m_normal;
                color = glm::vec3(color + glm::vec3(1, 1, 1)) * 0.5f;
                image.setPixel(x, y, QColor(color.x * 255,
                                            color.y * 255,
                                            color.z * 255).rgb());
            }
        }
    };

    m_renderedImg = image;
}

//function that fills up m_renderImg to the final image
void MainWindow::RenderScene()
{
    QImage image (400, 400, QImage::Format_RGB32);
    Shape *s1 = new Sphere();
    s1->m_transform = Transform(glm::vec3(0, 0, 1),
                                glm::vec3(0, 0, 45),
                                glm::vec3(2, 1, 1));

    Primitive *p1 = new Primitive(s1);
    Shape *s2 = new Sphere();
    s2->m_transform = Transform(glm::vec3(0.25, 0, 0),
                                glm::vec3(0, 0, 0),
                                glm::vec3(0.5, 0.5, 5));
    Primitive *p2 = new Primitive(s2);

    Shape *sp = new SquarePlane();
    sp->m_transform = Transform(glm::vec3(0, -0.5, 0),
                               glm::vec3(90, 0, 0),
                               glm::vec3(5, 5, 1));
    Primitive *p3 = new Primitive(sp);

    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p1)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p2)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p3)));

    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            Point2f pixel(x, y);
            Ray ray = m_camera.rayCast(pixel);
            Intersection i;
            bool intersecting = m_scene.getIntersection(ray, & i);
            if (intersecting) {
                Vector3f color = i.m_normal;
                color = glm::vec3(color + glm::vec3(1, 1, 1)) * 0.5f;
                image.setPixel(x, y, QColor(color.x * 255, color.y * 255, color.z * 255).rgb());
            }
        }
    };

    m_renderedImg = image;
}

//function that renders cornell_box.json
void MainWindow::RenderCornellBox()
{
    QImage image (400, 400, QImage::Format_RGB32);

    Shape *back_wall = new SquarePlane();
    back_wall->m_transform = Transform(glm::vec3(0, 0, -5),
                                        glm::vec3(0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_back_wall = new Primitive(back_wall,
                                           new LambertMaterial(Color3f(1)));


    Shape *right_wall = new SquarePlane();
    right_wall->m_transform = Transform(glm::vec3(5, 0, 0),
                                        glm::vec3(0, -90, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_right_wall =
            new Primitive(right_wall,
                          new LambertMaterial(Color3f(0, 1, 0)));

    Shape *left_wall = new SquarePlane();
    left_wall->m_transform = Transform(glm::vec3(-5, 0, 0),
                                        glm::vec3(0, 90, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_left_wall =
            new Primitive(left_wall,
                          new LambertMaterial(Color3f(1, 0, 0)));

    Shape *ceiling = new SquarePlane();
    ceiling->m_transform = Transform(glm::vec3(0, 5, 0),
                                        glm::vec3(90, 0, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_ceiling = new Primitive(ceiling,
                                         new LambertMaterial(Color3f(1)));

    Shape *floor = new SquarePlane();
    floor->m_transform = Transform(glm::vec3(0, -5, 0),
                                        glm::vec3(-90, 0, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_floor = new Primitive(floor,
                                       new LambertMaterial(Color3f(1)));
    p_floor->m_name = QString("Floor");

    Shape *shiny_sphere = new Sphere();
    shiny_sphere->m_transform = Transform(glm::vec3(-2, -5, 0),
                                        glm::vec3(0),
                                        glm::vec3(5, 5, 5));
    Primitive *p_shiny_sphere =
            new Primitive(shiny_sphere,
                          new LambertMaterial(Color3f(0.75, 0, 0.75)));

    Shape *transparent_sphere1 = new Sphere();
    transparent_sphere1->m_transform = Transform(glm::vec3(-3, 0, 2),
                                        glm::vec3(0),
                                        glm::vec3(4, 4, 4));
    Primitive *p_transparent_sphere1 =
            new Primitive(transparent_sphere1,
                          new LambertMaterial(Color3f(1)));

    Shape *in_transparent_sphere1 = new Sphere();
    in_transparent_sphere1->m_transform = Transform(glm::vec3(-3, 0, 2),
                                        glm::vec3(0),
                                        glm::vec3(2.5, 2.5, 2.5));
    Primitive *p_in_transparent_sphere1 =
            new Primitive(in_transparent_sphere1,
                          new LambertMaterial(Color3f(1)));

    Shape *trans_sphere_g = new Sphere();
    trans_sphere_g->m_transform = Transform(glm::vec3(3, -2, -3),
                                        glm::vec3(0),
                                        glm::vec3(4, 4, 4));
    Primitive *p_trans_sphere_g =
            new Primitive(trans_sphere_g,
                          new LambertMaterial(Color3f(0.15, 1, 0.15)));

    Shape *in_opaque1 = new Sphere();
    in_opaque1->m_transform = Transform(glm::vec3(3, -2, -3),
                                        glm::vec3(0),
                                        glm::vec3(1, 1, 1));
    Primitive *p_in_opaque1 = new Primitive(in_opaque1,
                                            new LambertMaterial(Color3f(1)));

    Shape *reflective_sphere_b1 = new Sphere();
    reflective_sphere_b1->m_transform = Transform(glm::vec3(-3, 3.5, -3),
                                        glm::vec3(0),
                                        glm::vec3(3, 3, 3));
    Primitive *p_reflective_sphere_b =
            new Primitive(reflective_sphere_b1,
                          new LambertMaterial(Color3f(0.25, 0.5, 1)));

    Shape *transparent_sphere3 = new Sphere();
    transparent_sphere3->m_transform = Transform(glm::vec3(3, 3.5, -3),
                                        glm::vec3(0),
                                        glm::vec3(3, 3, 3));
    Primitive *p_transparent_sphere3 =
            new Primitive(transparent_sphere3,
                          new LambertMaterial(Color3f(1)));

    Shape *refelctive_sphere_b2 = new Sphere();
    refelctive_sphere_b2->m_transform = Transform(glm::vec3(3, 3.5, -3),
                                        glm::vec3(0),
                                        glm::vec3(1, 1, 1));
    Primitive *p_refelctive_sphere_b2 =
            new Primitive(refelctive_sphere_b2,
                          new LambertMaterial(Color3f(0.25, 0.25, 1)));

    Shape *yellow_sphere = new Sphere();
    yellow_sphere->m_transform = Transform(glm::vec3(0),
                                        glm::vec3(0),
                                        glm::vec3(2, 2, 2));
    Primitive *p_yellow_sphere =
            new Primitive(yellow_sphere, new LambertMaterial(Color3f(1, 1, 0.25)));

    Light *light_source = new PointLight();
    light_source->m_transform = Transform(glm::vec3(0, 4.9, 0),
                                          glm::vec3(45, 0, 0),
                                          glm::vec3(0.5, 0.5, 0.5));
    light_source->m_color = Color3f(1);
    Primitive *p_light_source = new Primitive(light_source,
                                              new LambertMaterial(Color3f(1)));

    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_back_wall)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_right_wall)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_left_wall)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_ceiling)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_floor)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_shiny_sphere)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_transparent_sphere1)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_in_transparent_sphere1)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_trans_sphere_g)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_in_opaque1)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_reflective_sphere_b)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_transparent_sphere3)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_refelctive_sphere_b2)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_yellow_sphere)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_light_source)));

    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {

            Point2f pixel(x, y);
            Ray ray = m_camera.rayCast(pixel);
            Intersection i = Intersection();
            bool intersecting = m_scene.getIntersection(ray, &i);
            if (intersecting) {
                if (i.p_objectHit->m_shape_ptr != nullptr) {
                    Vector3f color =
                            i.p_objectHit->m_material_ptr->getScatteredColor(ray,
                                                                             5,
                                                                             &i,
                                                                             &m_scene);

                    image.setPixel(x, y, QColor(color.x * 255,
                                                color.y * 255,
                                                color.z * 255).rgb());
                }
            }
        }
    };

    m_renderedImg = image;
}

//function that renders cornell_box_2lights_simple.json
void MainWindow::RenderCornellBox2()
{
    QImage image (400, 400, QImage::Format_RGB32);

    Shape *back_wall = new SquarePlane();
    back_wall->m_transform = Transform(glm::vec3(0, 0, -5),
                                        glm::vec3(0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_back_wall =
            new Primitive(back_wall,
                          new LambertMaterial(Color3f(1)));

    Shape *right_wall = new SquarePlane();
    right_wall->m_transform = Transform(glm::vec3(5, 0, 0),
                                        glm::vec3(0, -90, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_right_wall =
            new Primitive(right_wall,
                          new LambertMaterial(Color3f(0, 1, 0)));

    Shape *left_wall = new SquarePlane();
    left_wall->m_transform = Transform(glm::vec3(-5, 0, 0),
                                        glm::vec3(0, 90, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_left_wall =
            new Primitive(left_wall,
                          new LambertMaterial(Color3f(1, 0, 0)));

    Shape *ceiling = new SquarePlane();
    ceiling->m_transform = Transform(glm::vec3(0, 5, 0),
                                        glm::vec3(90, 0, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_ceiling = new Primitive(ceiling,
                                         new LambertMaterial(Color3f(1)));

    Shape *floor = new SquarePlane();
    floor->m_transform = Transform(glm::vec3(0, -5, 0),
                                        glm::vec3(-90, 0, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_floor = new Primitive(floor, new LambertMaterial(Color3f(1)));

    Shape *shiny_sphere = new Sphere();
    shiny_sphere->m_transform = Transform(glm::vec3(-2, -5, 0),
                                        glm::vec3(0),
                                        glm::vec3(5, 5, 5));
    Primitive *p_shiny_sphere =
            new Primitive(shiny_sphere,
                          new LambertMaterial(Color3f(0.75, 0, 0.75)));

    Shape *transparent_sphere1 = new Sphere();
    transparent_sphere1->m_transform = Transform(glm::vec3(-3, 0, 2),
                                        glm::vec3(0),
                                        glm::vec3(4, 4, 4));
    Primitive *p_transparent_sphere1 =
            new Primitive(transparent_sphere1,
                          new LambertMaterial(Color3f(1)));

    Shape *in_transparent_sphere1 = new Sphere();
    in_transparent_sphere1->m_transform = Transform(glm::vec3(-3, 0, 2),
                                        glm::vec3(0),
                                        glm::vec3(2.5, 2.5, 2.5));
    Primitive *p_in_transparent_sphere1 =
            new Primitive(in_transparent_sphere1,
                          new LambertMaterial(Color3f(1)));

    Shape *transparent_sphere_g = new Sphere();
    transparent_sphere_g->m_transform = Transform(glm::vec3(3, -2, -3),
                                        glm::vec3(0),
                                        glm::vec3(4, 4, 4));
    Primitive *p_transparent_sphere_g =
            new Primitive(transparent_sphere_g,
                          new LambertMaterial(Color3f(0.15, 1, 0.15)));

    Shape *in_opaque1 = new Sphere();
    in_opaque1->m_transform = Transform(glm::vec3(3, -2, -3),
                                        glm::vec3(0),
                                        glm::vec3(1, 1, 1));
    Primitive *p_in_opaque1 = new Primitive(in_opaque1,
                                            new LambertMaterial(Color3f(1)));

    Shape *reflective_sphere_b1 = new Sphere();
    reflective_sphere_b1->m_transform = Transform(glm::vec3(-3, 3.5, -3),
                                        glm::vec3(0),
                                        glm::vec3(3, 3, 3));
    Primitive *p_reflective_sphere_b =
            new Primitive(reflective_sphere_b1,
                          new LambertMaterial(Color3f(0.25, 0.5, 1)));

    Shape *transparent_sphere3 = new Sphere();
    transparent_sphere3->m_transform = Transform(glm::vec3(3, 3.5, -3),
                                        glm::vec3(0),
                                        glm::vec3(3, 3, 3));
    Primitive *p_transparent_sphere3 =
            new Primitive(transparent_sphere3, new LambertMaterial(Color3f(1)));

    Shape *refelctive_sphere_b2 = new Sphere();
    refelctive_sphere_b2->m_transform = Transform(glm::vec3(3, 3.5, -3),
                                        glm::vec3(0),
                                        glm::vec3(1, 1, 1));
    Primitive *p_refelctive_sphere_b2 =
            new Primitive(refelctive_sphere_b2,
                          new LambertMaterial(Color3f(0.25, 0.5, 1)));

    Shape *yellow_sphere = new Sphere();
    yellow_sphere->m_transform = Transform(glm::vec3(0),
                                        glm::vec3(0),
                                        glm::vec3(2, 2, 2));
    Primitive *p_yellow_sphere =
            new Primitive(yellow_sphere,
                          new LambertMaterial(Color3f(1, 1, 0.25)));

    Light *light_source = new PointLight();
    light_source->m_transform = Transform(glm::vec3(-2, 4.9, 0),
                                          glm::vec3(45, 0, 0),
                                          glm::vec3(0.5, 0.5, 0.5));
    light_source->m_color = glm::normalize(Color3f(1.0, 0.25, 0.25));
    Primitive *p_light_source = new Primitive(light_source,
                                              new LambertMaterial(Color3f(1)));


    Light *light_source2 = new PointLight();
    light_source2->m_transform = Transform(glm::vec3(2, 4.9, 0),
                                          glm::vec3(45, 0, 0),
                                          glm::vec3(0.5, 0.5, 0.5));
    light_source2->m_color = glm::normalize(Color3f(0.25, 1.0, 0.25));
    Primitive *p_light_source2 = new Primitive(light_source2, new
                                               LambertMaterial(Color3f(1)));

    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_back_wall)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_right_wall)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_left_wall)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_ceiling)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_floor)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_shiny_sphere)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_transparent_sphere1)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_in_transparent_sphere1)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_transparent_sphere_g)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_in_opaque1)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_reflective_sphere_b)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_transparent_sphere3)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_refelctive_sphere_b2)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_yellow_sphere)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_light_source)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_light_source2)));


    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            Point2f pixel(x, y);
            Ray ray = m_camera.rayCast(pixel);
            Intersection i = Intersection();
            bool intersecting = m_scene.getIntersection(ray, &i);
            if (intersecting) {
                if (i.p_objectHit->m_shape_ptr != nullptr) {
                    Vector3f color = i.p_objectHit->m_material_ptr->getScatteredColor(ray,
                                                                                      5,
                                                                                      &i,
                                                                                      &m_scene);
                    image.setPixel(x, y, QColor(color.x * 255,
                                                color.y * 255,
                                                color.z * 255).rgb());
                }
            }
        }
    };

    m_renderedImg = image;
}

//function that renders reflection_refraction.json
void MainWindow::RenderReflectionRefraction()
{
    QImage image (400, 400, QImage::Format_RGB32);

    Shape *back_wall = new SquarePlane();
    back_wall->m_transform = Transform(glm::vec3(0, 0, -5),
                                        glm::vec3(0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_back_wall = new Primitive(back_wall,
                                           new LambertMaterial(Color3f(1)));
    p_back_wall->m_name = QString("Back");

    Shape *right_wall = new SquarePlane();
    right_wall->m_transform = Transform(glm::vec3(5, 0, 0),
                                        glm::vec3(0, -90, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_right_wall = new Primitive(right_wall,
                                            new LambertMaterial(Color3f(0, 1, 0)));
    p_right_wall->m_name = QString("Right");

    Shape *left_wall = new SquarePlane();
    left_wall->m_transform = Transform(glm::vec3(-5, 0, 0),
                                        glm::vec3(0, 90, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_left_wall = new Primitive(left_wall,
                                           new LambertMaterial(Color3f(1, 0, 0)));
    p_left_wall->m_name = QString("Left");

    Shape *ceiling = new SquarePlane();
    ceiling->m_transform = Transform(glm::vec3(0, 5, 0),
                                        glm::vec3(90, 0, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_ceiling = new Primitive(ceiling,
                                         new LambertMaterial(Color3f(1)));
    p_ceiling->m_name = QString("Ceiling");

    Shape *floor = new SquarePlane();
    floor->m_transform = Transform(glm::vec3(0, -5, 0),
                                        glm::vec3(-90, 0, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_floor = new Primitive(floor,
                                       new LambertMaterial(Color3f(1)));
    p_floor->m_name = QString("Floor");

    Shape *shiny_sphere = new Sphere();
    shiny_sphere->m_transform = Transform(glm::vec3(-2, -5, 0),
                                        glm::vec3(0),
                                        glm::vec3(5, 5, 5));
    Primitive *p_shiny_sphere =
            new Primitive(shiny_sphere,
                          new BlinnPhongMaterial(Color3f(0.75, 0, 0.75),
                                                 10.0f,
                                                 Color3f(1, 0, 0)));
    p_shiny_sphere->m_name = QString("Shiny Sphere");

    Shape *transparent_sphere1 = new Sphere();
    transparent_sphere1->m_transform = Transform(glm::vec3(-3, 0, 2),
                                        glm::vec3(0),
                                        glm::vec3(4, 4, 4));
    Primitive *p_transparent_sphere1 =
            new Primitive(transparent_sphere1,
                          new SpecularTransmissionMaterial(Color3f(1),
                                                           1.33,
                                                           1.0f,
                                                           Color3f(1, 1, 1)));
    p_transparent_sphere1->m_name = QString("Transparent Sphere 1");

    Shape *in_transparent_sphere1 = new Sphere();
    in_transparent_sphere1->m_transform = Transform(glm::vec3(-3, 0, 2),
                                        glm::vec3(0),
                                        glm::vec3(2.5, 2.5, 2.5));
    Primitive *p_in_transparent_sphere1 =
            new Primitive(in_transparent_sphere1,
                          new SpecularTransmissionMaterial(Color3f(1),
                                                           1.0f,
                                                           1.33,
                                                           Color3f(1, 1, 1)));
    p_in_transparent_sphere1->m_name = QString("In Transparent Sphere 1");

    Shape *transparent_sphere_g = new Sphere();
    transparent_sphere_g->m_transform = Transform(glm::vec3(3, -2, -3),
                                        glm::vec3(0),
                                        glm::vec3(4, 4, 4));
    Primitive *p_transparent_sphere_g =
            new Primitive(transparent_sphere_g,
                          new SpecularTransmissionMaterial(Color3f(0, 1, 0),
                                                           1.33,
                                                           1.0f,
                                                           Color3f(1, 1, 1)));
    p_transparent_sphere_g->m_name = QString("Green Trans Sphere");

    Shape *in_opaque1 = new Sphere();
    in_opaque1->m_transform = Transform(glm::vec3(3, -2, -3),
                                        glm::vec3(0),
                                        glm::vec3(1, 1, 1));
    Primitive *p_in_opaque1 = new Primitive(in_opaque1,
                                            new LambertMaterial(Color3f(1)));
    p_in_opaque1->m_name = QString("In Opaque Sphere");

    Shape *reflective_sphere_b1 = new Sphere();
    reflective_sphere_b1->m_transform = Transform(glm::vec3(-3, 3.5, -3),
                                        glm::vec3(0),
                                        glm::vec3(3, 3, 3));
    Primitive *p_reflective_sphere_b =
            new Primitive(reflective_sphere_b1,
                          new SpecularReflectionMaterial(Color3f(0.25, 0.5, 1),
                                                         Color3f(1, 0, 1)));
    p_reflective_sphere_b->m_name = QString("Blue Refelctive Sphere");

    Shape *transparent_sphere3 = new Sphere();
    transparent_sphere3->m_transform = Transform(glm::vec3(3, 3.5, -3),
                                        glm::vec3(0),
                                        glm::vec3(3, 3, 3));
    Primitive *p_transparent_sphere3 =
            new Primitive(transparent_sphere3,
                          new SpecularTransmissionMaterial(Color3f(1),
                                                           1.33,
                                                           1.0f,
                                                           Color3f(1, 1, 1)));
    p_transparent_sphere3->m_name = QString("Trans Sphere 3");

    Shape *refelctive_sphere_b2 = new Sphere();
    refelctive_sphere_b2->m_transform = Transform(glm::vec3(3, 3.5, -3),
                                        glm::vec3(0),
                                        glm::vec3(1, 1, 1));
    Primitive *p_refelctive_sphere_b2 =
            new Primitive(refelctive_sphere_b2,
                          new SpecularReflectionMaterial(Color3f(0.25, 0.5, 1),
                                                         Color3f(1, 0, 1)));
    p_refelctive_sphere_b2->m_name = QString("Blue Reflective Sphere 2");

    Shape *yellow_sphere = new Sphere();
    yellow_sphere->m_transform = Transform(glm::vec3(0),
                                        glm::vec3(0),
                                        glm::vec3(2, 2, 2));
    Primitive *p_yellow_sphere =
            new Primitive(yellow_sphere, new LambertMaterial(Color3f(1, 1, 0.25)));
    p_yellow_sphere->m_name = QString("Yellow sphere");

    Light *light_source = new PointLight();
    light_source->m_transform = Transform(glm::vec3(0, 4, 5),
                                          glm::vec3(0),
                                          glm::vec3(0.5, 0.5, 0.5));
    light_source->m_color = Color3f(1);
    Primitive *p_light_source = new Primitive(light_source,
                                              new LambertMaterial(Color3f(1)));
    p_light_source->m_name = QString("Light source 1");

    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_back_wall)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_right_wall)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_left_wall)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_ceiling)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_floor)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_shiny_sphere)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_transparent_sphere1)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_in_transparent_sphere1)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_transparent_sphere_g)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_in_opaque1)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_reflective_sphere_b)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_transparent_sphere3)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_refelctive_sphere_b2)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_yellow_sphere)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_light_source)));


    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {

            Point2f pixel(x, y);
            Ray ray = m_camera.rayCast(pixel);
            Intersection i = Intersection();
            bool intersecting = m_scene.getIntersection(ray, &i);
            if (intersecting) {
                if (i.p_objectHit->m_shape_ptr != nullptr) {
                    Vector3f color = i.p_objectHit->m_material_ptr->getScatteredColor(ray,
                                                                                      5,
                                                                                      &i,
                                                                                      &m_scene);
                    image.setPixel(x, y, QColor(color.x * 255,
                                                color.y * 255,
                                                color.z * 255).rgb());
                }
            }
        }
    };

    m_renderedImg = image;

}

void MainWindow::RenderAreaLightTest()
{
    QImage image (400, 400, QImage::Format_RGB32);

    Shape *floor = new SquarePlane();
    floor->m_transform = Transform(glm::vec3(0),
                                        glm::vec3(-90, 0, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_floor = new Primitive(floor);
    p_floor->m_name = QString("Floor");


    Shape *sphere = new Sphere();
    sphere->m_transform = Transform(glm::vec3(0, 1, 0),
                                        glm::vec3(0),
                                        glm::vec3(1));
    Primitive *p_sphere = new Primitive(sphere);
    p_sphere->m_name = QString("Sphere");


    Shape *light_plane = new SquarePlane();
    light_plane->m_transform = Transform(glm::vec3(0, 3.5, 0),
                                        glm::vec3(90, 0, 0),
                                        glm::vec3(2, 2, 1));

    Light *light = new AreaLight(64, 1, light_plane);
    light->m_transform = Transform(glm::vec3(0, 3.5, 0),
                                           glm::vec3(90, 0, 0),
                                           glm::vec3(2, 2, 1));

    light->m_color = Color3f(1);
    Primitive *p_light = new Primitive(light, light_plane);
    p_light->m_name = QString("Light");
    p_light->m_light_ptr->m_id = 1;

    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_floor)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_sphere)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_light)));

    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            Point2f pixel(x, y);
            Ray ray = m_camera.rayCast(pixel);
            Intersection i = Intersection();
            bool intersecting = m_scene.getIntersection(ray, &i);
            if (intersecting) {
                if (i.p_objectHit->m_shape_ptr != nullptr) {
                    Color3f color(0);

                    if (i.p_objectHit->m_light_ptr != nullptr) {
                        color = i.p_objectHit->m_light_ptr->m_color;
                    } else {
                        color = i.p_objectHit->m_material_ptr->getScatteredColor(ray,
                                                                                 5,
                                                                                 &i,
                                                                                 &m_scene);
                    }

                    image.setPixel(x, y, QColor(color.x * 255,
                                                color.y * 255,
                                                color.z * 255).rgb());
                }
            }
        }
    };

    m_renderedImg = image;
}

//renders occlusion image (one without the light)
void MainWindow::RenderOcclusion()
{
    QImage image (400, 400, QImage::Format_RGB32);

    Shape *back_wall = new SquarePlane();
    back_wall->m_transform = Transform(glm::vec3(0, 0, -5),
                                        glm::vec3(0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_back_wall = new Primitive(back_wall);

    Shape *right_wall = new SquarePlane();
    right_wall->m_transform = Transform(glm::vec3(5, 0, 0),
                                        glm::vec3(0, -90, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_right_wall = new Primitive(right_wall);

    Shape *left_wall = new SquarePlane();
    left_wall->m_transform = Transform(glm::vec3(-5, 0, 0),
                                        glm::vec3(0, 90, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_left_wall = new Primitive(left_wall);

    Shape *ceiling = new SquarePlane();
    ceiling->m_transform = Transform(glm::vec3(0, 5, 0),
                                        glm::vec3(90, 0, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_ceiling = new Primitive(ceiling);

    Shape *floor = new SquarePlane();
    floor->m_transform = Transform(glm::vec3(0, -5, 0),
                                        glm::vec3(-90, 0, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_floor = new Primitive(floor);
    p_floor->m_name = QString("Floor");

    Shape *shiny_sphere = new Sphere();
    shiny_sphere->m_transform = Transform(glm::vec3(-2, -5, 0),
                                        glm::vec3(0),
                                        glm::vec3(5, 5, 5));
    Primitive *p_shiny_sphere = new Primitive(shiny_sphere);

    Shape *transparent_sphere1 = new Sphere();
    transparent_sphere1->m_transform = Transform(glm::vec3(-3, 0, 2),
                                        glm::vec3(0),
                                        glm::vec3(4, 4, 4));
    Primitive *p_transparent_sphere1 = new Primitive(transparent_sphere1);

    Shape *in_transparent_sphere1 = new Sphere();
    in_transparent_sphere1->m_transform = Transform(glm::vec3(-3, 0, 2),
                                        glm::vec3(0),
                                        glm::vec3(2.5, 2.5, 2.5));
    Primitive *p_in_transparent_sphere1 = new Primitive(in_transparent_sphere1);

    Shape *transparent_sphere_g = new Sphere();
    transparent_sphere_g->m_transform = Transform(glm::vec3(3, -2, -3),
                                        glm::vec3(0),
                                        glm::vec3(4, 4, 4));
    Primitive *p_transparent_sphere_g = new Primitive(transparent_sphere_g);

    Shape *in_opaque1 = new Sphere();
    in_opaque1->m_transform = Transform(glm::vec3(3, -2, -3),
                                        glm::vec3(0),
                                        glm::vec3(1, 1, 1));
    Primitive *p_in_opaque1 = new Primitive(in_opaque1);

    Shape *reflective_sphere_b1 = new Sphere();
    reflective_sphere_b1->m_transform = Transform(glm::vec3(-3, 3.5, -3),
                                        glm::vec3(0),
                                        glm::vec3(3, 3, 3));
    Primitive *p_reflective_sphere_b = new Primitive(reflective_sphere_b1);

    Shape *transparent_sphere3 = new Sphere();
    transparent_sphere3->m_transform = Transform(glm::vec3(3, 3.5, -3),
                                        glm::vec3(0),
                                        glm::vec3(3, 3, 3));
    Primitive *p_transparent_sphere3 = new Primitive(transparent_sphere3);

    Shape *refelctive_sphere_b2 = new Sphere();
    refelctive_sphere_b2->m_transform = Transform(glm::vec3(3, 3.5, -3),
                                        glm::vec3(0),
                                        glm::vec3(1, 1, 1));
    Primitive *p_refelctive_sphere_b2 = new Primitive(refelctive_sphere_b2);

    Shape *yellow_sphere = new Sphere();
    yellow_sphere->m_transform = Transform(glm::vec3(0),
                                        glm::vec3(0),
                                        glm::vec3(2, 2, 2));
    Primitive *p_yellow_sphere = new Primitive(yellow_sphere);
    p_yellow_sphere->m_name = QString("Yellow sphere");

    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_back_wall)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_right_wall)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_left_wall)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_ceiling)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_floor)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_shiny_sphere)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_transparent_sphere1)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_in_transparent_sphere1)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_transparent_sphere_g)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_in_opaque1)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_reflective_sphere_b)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_transparent_sphere3)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_refelctive_sphere_b2)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_yellow_sphere)));

    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {

            Point2f pixel(x, y);
            Ray ray = m_camera.rayCast(pixel);
            Intersection i = Intersection();
            bool intersecting = m_scene.getIntersection(ray, &i);
            if (intersecting) {
                if (i.p_objectHit->m_shape_ptr != nullptr) {

                    AmbientOcclusion ao = AmbientOcclusion(64);
                    Color3f color(0);
                    ao.applyAmbientOcclusion(&i, &m_scene, color);
                    image.setPixel(x, y, QColor(color.x * 255,
                                                color.y * 255,
                                                color.z * 255).rgb());
                }
            }
        }
    };

    m_renderedImg = image;
}

//renders corenllbox with ambient occlusion
void MainWindow::RenderCornellBoxWithAmbient()
{
    QImage image (400, 400, QImage::Format_RGB32);

    Shape *back_wall = new SquarePlane();
    back_wall->m_transform = Transform(glm::vec3(0, 0, -5),
                                        glm::vec3(0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_back_wall = new Primitive(back_wall,
                                           new LambertMaterial(Color3f(1)));


    Shape *right_wall = new SquarePlane();
    right_wall->m_transform = Transform(glm::vec3(5, 0, 0),
                                        glm::vec3(0, -90, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_right_wall =
            new Primitive(right_wall,
                          new LambertMaterial(Color3f(0, 1, 0)));

    Shape *left_wall = new SquarePlane();
    left_wall->m_transform = Transform(glm::vec3(-5, 0, 0),
                                        glm::vec3(0, 90, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_left_wall =
            new Primitive(left_wall,
                          new LambertMaterial(Color3f(1, 0, 0)));

    Shape *ceiling = new SquarePlane();
    ceiling->m_transform = Transform(glm::vec3(0, 5, 0),
                                        glm::vec3(90, 0, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_ceiling = new Primitive(ceiling,
                                         new LambertMaterial(Color3f(1)));

    Shape *floor = new SquarePlane();
    floor->m_transform = Transform(glm::vec3(0, -5, 0),
                                        glm::vec3(-90, 0, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_floor = new Primitive(floor,
                                       new LambertMaterial(Color3f(1)));
    p_floor->m_name = QString("Floor");

    Shape *shiny_sphere = new Sphere();
    shiny_sphere->m_transform = Transform(glm::vec3(-2, -5, 0),
                                        glm::vec3(0),
                                        glm::vec3(5, 5, 5));
    Primitive *p_shiny_sphere =
            new Primitive(shiny_sphere,
                          new LambertMaterial(Color3f(0.75, 0, 0.75)));

    Shape *transparent_sphere1 = new Sphere();
    transparent_sphere1->m_transform = Transform(glm::vec3(-3, 0, 2),
                                        glm::vec3(0),
                                        glm::vec3(4, 4, 4));
    Primitive *p_transparent_sphere1 =
            new Primitive(transparent_sphere1,
                          new LambertMaterial(Color3f(1)));

    Shape *in_transparent_sphere1 = new Sphere();
    in_transparent_sphere1->m_transform = Transform(glm::vec3(-3, 0, 2),
                                        glm::vec3(0),
                                        glm::vec3(2.5, 2.5, 2.5));
    Primitive *p_in_transparent_sphere1 =
            new Primitive(in_transparent_sphere1,
                          new LambertMaterial(Color3f(1)));

    Shape *trans_sphere_g = new Sphere();
    trans_sphere_g->m_transform = Transform(glm::vec3(3, -2, -3),
                                        glm::vec3(0),
                                        glm::vec3(4, 4, 4));
    Primitive *p_trans_sphere_g =
            new Primitive(trans_sphere_g,
                          new LambertMaterial(Color3f(0.15, 1, 0.15)));

    Shape *in_opaque1 = new Sphere();
    in_opaque1->m_transform = Transform(glm::vec3(3, -2, -3),
                                        glm::vec3(0),
                                        glm::vec3(1, 1, 1));
    Primitive *p_in_opaque1 = new Primitive(in_opaque1,
                                            new LambertMaterial(Color3f(1)));

    Shape *reflective_sphere_b1 = new Sphere();
    reflective_sphere_b1->m_transform = Transform(glm::vec3(-3, 3.5, -3),
                                        glm::vec3(0),
                                        glm::vec3(3, 3, 3));
    Primitive *p_reflective_sphere_b =
            new Primitive(reflective_sphere_b1,
                          new LambertMaterial(Color3f(0.25, 0.5, 1)));

    Shape *transparent_sphere3 = new Sphere();
    transparent_sphere3->m_transform = Transform(glm::vec3(3, 3.5, -3),
                                        glm::vec3(0),
                                        glm::vec3(3, 3, 3));
    Primitive *p_transparent_sphere3 =
            new Primitive(transparent_sphere3,
                          new LambertMaterial(Color3f(1)));

    Shape *refelctive_sphere_b2 = new Sphere();
    refelctive_sphere_b2->m_transform = Transform(glm::vec3(3, 3.5, -3),
                                        glm::vec3(0),
                                        glm::vec3(1, 1, 1));
    Primitive *p_refelctive_sphere_b2 =
            new Primitive(refelctive_sphere_b2,
                          new LambertMaterial(Color3f(0.25, 0.25, 1)));

    Shape *yellow_sphere = new Sphere();
    yellow_sphere->m_transform = Transform(glm::vec3(0),
                                        glm::vec3(0),
                                        glm::vec3(2, 2, 2));
    Primitive *p_yellow_sphere =
            new Primitive(yellow_sphere, new LambertMaterial(Color3f(1, 1, 0.25)));

    Light *light_source = new PointLight();
    light_source->m_transform = Transform(glm::vec3(0, 4.9, 0),
                                          glm::vec3(45, 0, 0),
                                          glm::vec3(0.5, 0.5, 0.5));
    light_source->m_color = Color3f(1);
    Primitive *p_light_source = new Primitive(light_source,
                                              new LambertMaterial(Color3f(1)));

    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_back_wall)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_right_wall)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_left_wall)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_ceiling)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_floor)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_shiny_sphere)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_transparent_sphere1)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_in_transparent_sphere1)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_trans_sphere_g)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_in_opaque1)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_reflective_sphere_b)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_transparent_sphere3)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_refelctive_sphere_b2)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_yellow_sphere)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_light_source)));

    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {

            Point2f pixel(x, y);
            Ray ray = m_camera.rayCast(pixel);
            Intersection i = Intersection();
            bool intersecting = m_scene.getIntersection(ray, &i);
            if (intersecting) {
                if (i.p_objectHit->m_shape_ptr != nullptr) {
                    Vector3f color =
                            i.p_objectHit->m_material_ptr->getScatteredColor(ray,
                                                                             5,
                                                                             &i,
                                                                             &m_scene);

                    AmbientOcclusion ao = AmbientOcclusion(64);
                    Color3f ambient(0);
                    ao.applyAmbientOcclusion(&i, &m_scene, ambient);

                    color = color * ambient;

                    image.setPixel(x, y, QColor(color.x * 255,
                                                color.y * 255,
                                                color.z * 255).rgb());

                }
            }
        }
    };

    m_renderedImg = image;
}

void MainWindow::RenderCornellBox2WithAreaLight()
{
    QImage image (400, 400, QImage::Format_RGB32);

    Shape *back_wall = new SquarePlane();
    back_wall->m_transform = Transform(glm::vec3(0, 0, -5),
                                        glm::vec3(0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_back_wall =
            new Primitive(back_wall,
                          new LambertMaterial(Color3f(1)));

    Shape *right_wall = new SquarePlane();
    right_wall->m_transform = Transform(glm::vec3(5, 0, 0),
                                        glm::vec3(0, -90, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_right_wall =
            new Primitive(right_wall,
                          new LambertMaterial(Color3f(0, 1, 0)));

    Shape *left_wall = new SquarePlane();
    left_wall->m_transform = Transform(glm::vec3(-5, 0, 0),
                                        glm::vec3(0, 90, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_left_wall =
            new Primitive(left_wall,
                          new LambertMaterial(Color3f(1, 0, 0)));

    Shape *ceiling = new SquarePlane();
    ceiling->m_transform = Transform(glm::vec3(0, 5, 0),
                                        glm::vec3(90, 0, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_ceiling = new Primitive(ceiling,
                                         new LambertMaterial(Color3f(1)));

    Shape *floor = new SquarePlane();
    floor->m_transform = Transform(glm::vec3(0, -5, 0),
                                        glm::vec3(-90, 0, 0),
                                        glm::vec3(10, 10, 1));
    Primitive *p_floor = new Primitive(floor, new LambertMaterial(Color3f(1)));

    Shape *shiny_sphere = new Sphere();
    shiny_sphere->m_transform = Transform(glm::vec3(-2, -5, 0),
                                        glm::vec3(0),
                                        glm::vec3(5, 5, 5));
    Primitive *p_shiny_sphere =
            new Primitive(shiny_sphere,
                          new LambertMaterial(Color3f(0.75, 0, 0.75)));

    Shape *transparent_sphere1 = new Sphere();
    transparent_sphere1->m_transform = Transform(glm::vec3(-3, 0, 2),
                                        glm::vec3(0),
                                        glm::vec3(4, 4, 4));
    Primitive *p_transparent_sphere1 =
            new Primitive(transparent_sphere1,
                          new LambertMaterial(Color3f(1)));

    Shape *in_transparent_sphere1 = new Sphere();
    in_transparent_sphere1->m_transform = Transform(glm::vec3(-3, 0, 2),
                                        glm::vec3(0),
                                        glm::vec3(2.5, 2.5, 2.5));
    Primitive *p_in_transparent_sphere1 =
            new Primitive(in_transparent_sphere1,
                          new LambertMaterial(Color3f(1)));

    Shape *transparent_sphere_g = new Sphere();
    transparent_sphere_g->m_transform = Transform(glm::vec3(3, -2, -3),
                                        glm::vec3(0),
                                        glm::vec3(4, 4, 4));
    Primitive *p_transparent_sphere_g =
            new Primitive(transparent_sphere_g,
                          new LambertMaterial(Color3f(0.15, 1, 0.15)));

    Shape *in_opaque1 = new Sphere();
    in_opaque1->m_transform = Transform(glm::vec3(3, -2, -3),
                                        glm::vec3(0),
                                        glm::vec3(1, 1, 1));
    Primitive *p_in_opaque1 = new Primitive(in_opaque1,
                                            new LambertMaterial(Color3f(1)));

    Shape *reflective_sphere_b1 = new Sphere();
    reflective_sphere_b1->m_transform = Transform(glm::vec3(-3, 3.5, -3),
                                        glm::vec3(0),
                                        glm::vec3(3, 3, 3));
    Primitive *p_reflective_sphere_b =
            new Primitive(reflective_sphere_b1,
                          new LambertMaterial(Color3f(0.25, 0.5, 1)));

    Shape *transparent_sphere3 = new Sphere();
    transparent_sphere3->m_transform = Transform(glm::vec3(3, 3.5, -3),
                                        glm::vec3(0),
                                        glm::vec3(3, 3, 3));
    Primitive *p_transparent_sphere3 =
            new Primitive(transparent_sphere3, new LambertMaterial(Color3f(1)));

    Shape *refelctive_sphere_b2 = new Sphere();
    refelctive_sphere_b2->m_transform = Transform(glm::vec3(3, 3.5, -3),
                                        glm::vec3(0),
                                        glm::vec3(1, 1, 1));
    Primitive *p_refelctive_sphere_b2 =
            new Primitive(refelctive_sphere_b2,
                          new LambertMaterial(Color3f(0.25, 0.5, 1)));

    Shape *yellow_sphere = new Sphere();
    yellow_sphere->m_transform = Transform(glm::vec3(0),
                                        glm::vec3(0),
                                        glm::vec3(2, 2, 2));
    Primitive *p_yellow_sphere =
            new Primitive(yellow_sphere,
                          new LambertMaterial(Color3f(1, 1, 0.25)));


    Shape *light_plane = new SquarePlane();
    light_plane->m_transform = Transform(glm::vec3(-2, 4.9, 0),
                                         glm::vec3(45, 0, 0),
                                         glm::vec3(0.5, 0.5, 0.5));

    Light *light_source = new AreaLight(25, 1, light_plane);
    light_source->m_transform = Transform(glm::vec3(-2, 4.9, 0),
                                          glm::vec3(45, 0, 0),
                                          glm::vec3(0.5, 0.5, 0.5));
    light_source->m_color = glm::normalize(Color3f(1.0, 0.25, 0.25));

    Primitive *p_light_source = new Primitive(light_source,
                                              light_plane);

    p_light_source->m_light_ptr->m_id = 1;

    Shape *light_plane2 = new SquarePlane();
    light_plane2->m_transform = Transform(glm::vec3(2, 4.9, 0),
                                          glm::vec3(45, 0, 0),
                                          glm::vec3(0.5, 0.5, 0.5));

    Light *light_source2 = new AreaLight(25, 2, light_plane2);
    light_source2->m_transform = Transform(glm::vec3(2, 4.9, 0),
                                          glm::vec3(45, 0, 0),
                                          glm::vec3(0.5, 0.5, 0.5));
    light_source2->m_color = glm::normalize(Color3f(0.25, 1.0, 0.25));

    Primitive *p_light_source2 = new Primitive(light_source2,
                                               light_plane2);

    p_light_source2->m_light_ptr->m_id = 2;

    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_back_wall)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_right_wall)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_left_wall)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_ceiling)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_floor)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_shiny_sphere)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_transparent_sphere1)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_in_transparent_sphere1)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_transparent_sphere_g)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_in_opaque1)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_reflective_sphere_b)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_transparent_sphere3)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_refelctive_sphere_b2)));
    m_scene.m_primitives.push_back(std::unique_ptr<Primitive>(std::move(p_yellow_sphere)));
    m_scene.m_lights.push_back(std::unique_ptr<Primitive>(std::move(p_light_source)));
    m_scene.m_lights.push_back(std::unique_ptr<Primitive>(std::move(p_light_source2)));


    for (int x = 0; x < image.width(); x++) {
        for (int y = 0; y < image.height(); y++) {
            Point2f pixel(x, y);
            Ray ray = m_camera.rayCast(pixel);
            Intersection i = Intersection();
            bool intersecting = m_scene.getIntersection(ray, &i);
            if (intersecting) {
                if (i.p_objectHit->m_shape_ptr != nullptr) {
                    Color3f color(0);
                    if (i.p_objectHit->m_light_ptr != nullptr) {
                        color = i.p_objectHit->m_light_ptr->m_color;
                    } else {
                        color = i.p_objectHit->m_material_ptr->getScatteredColor(ray,
                                                                                 5,
                                                                                 &i,
                                                                                 &m_scene);

                        AmbientOcclusion ao = AmbientOcclusion(50);
                        Color3f ambient(0);
                        ao.applyAmbientOcclusion(&i, &m_scene, ambient);

                        color = color * ambient;

                    }

                    image.setPixel(x, y, QColor(color.x * 255,
                                                color.y * 255,
                                                color.z * 255).rgb());
                }
            }
        }
    };

    m_renderedImg = image;
}

//function that saves the image
void MainWindow::SaveImage()
{
    QString fileName = QFileDialog::getSaveFileName(this, tr("Save Image"),
                                                    QString(),
                                                    tr("Images (*.png)"));
    if (!fileName.isEmpty())
    {
      m_renderedImg.save(fileName);
    }
}

//function that renders the image (currently rendering the last test image)
void MainWindow::renderImg()
{
//    RenderTest0();
//    RenderTest1();
//    RenderTest2();
//    RenderTest3();
//    RenderScene();
//    RenderCornellBox();
//    RenderReflectionRefraction();
//    RenderAreaLightTest();
//    RenderOcclusion();
//    RenderCornellBoxWithAmbient();
    RenderCornellBox2WithAreaLight();
    DisplayQImage(m_renderedImg);
    SaveImage();
    m_button->setEnabled(false);
}

