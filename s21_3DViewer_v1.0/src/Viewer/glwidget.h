#ifndef GLWIDGET_H
#define GLWIDGET_H

#define GL_SILENCE_DEPRECATION

#include <QtOpenGL>
#include <QOpenGLWidget>
#include <QOpenGLFunctions>
#include <QOpenGLExtraFunctions>
#include <QMatrix4x4>
#include <QOpenGLShaderProgram>
#include <QMessageBox>

enum LINE_TYPE{
  SOLID = 0,
  DOTTED = 1
};

enum POINT_TYPE{
    NO = 0,
    CIRCLE = 1,
    SQUART = 2
};

extern "C"{
#include "c_libs/parse.h"
}

class glwidget : public QOpenGLWidget, protected QOpenGLExtraFunctions
{
    Q_OBJECT

public:
    explicit glwidget(QWidget *parent = nullptr);
    ~glwidget();

    void loadModel(const QString& fileName);
    QColor getBackgroundColor() const { return backgroundColor; }
    void setBackgroundColor(const QColor &color) { backgroundColor = color; }
    void scale_resize(float a);
    void rotate(float alpha, int type, float pos_x, float pos_y, float pos_z);
    void movement(float delta, int type);

    bool ortho;
    bool dotted;

    int point_type = NO;

    QColor point_color = Qt::white;
    QColor line_color = Qt::white;

    float point_size = 1;
    float line_size = 1;

    int n_points= 0;
    int n_faces = 0;



protected:
    void initializeGL() override;
    void paintGL() override;
    void resizeGL(int width, int height) override;

private:
    float scaleFactor;
    QColor backgroundColor;
    float *points = NULL;
    unsigned int *faces = NULL;
};

#endif // GLWIDGET_H
