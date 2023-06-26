#include <glwidget.h>


void glwidget::scale_resize(float a) {
    s21_scale(points, a, n_points);
    update();
}


glwidget::glwidget(QWidget *parent)
    :QOpenGLWidget(parent) {
    backgroundColor = QColor(0, 0, 0);
}

void glwidget::initializeGL() {
    initializeOpenGLFunctions();
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, points);
    qDebug() << "OpenGL initialized";
}

void glwidget::resizeGL(int w, int h) {
    glViewport(0, 0, w, h);
}

void glwidget::paintGL() {
    glEnable(GL_DEPTH_TEST);
    glClearColor(backgroundColor.redF(), backgroundColor.greenF(), backgroundColor.blueF(), backgroundColor.alphaF());
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
    QMatrix4x4 projection;
    QMatrix4x4 modelView;
    if(ortho){
        qDebug() << "ortho";
        projection.ortho(-1, 1, -1, 1, 1, 100);
        modelView.lookAt(QVector3D(2, 2, 2), QVector3D(0, 0, 0), QVector3D(0, 1, 0));
    }else {
        projection.perspective(70.0, (double)width() / height(), 0.1, 100.0);
        modelView.lookAt(QVector3D(2, 2, 4), QVector3D(0, 0, 0), QVector3D(0, 1, 0));
    }
    glMatrixMode(GL_PROJECTION);
    glLoadMatrixf(projection.constData());
    glMatrixMode(GL_MODELVIEW);
    glLoadMatrixf(modelView.constData());
    glPointSize(point_size);
    glLineWidth(line_size);
    glEnableClientState(GL_VERTEX_ARRAY);
    glVertexPointer(3, GL_FLOAT, 0, points);
    // Draw the points
    float r, g, b, a;
    if(point_type != NO) {
        point_color.getRgbF(&r, &g, &b, &a);
        glColor4f(r, g, b, a);
        if(point_type == CIRCLE)
            glEnable(GL_POINT_SMOOTH);
        glDrawArrays(GL_POINTS, 0, n_points);
        glDisable(GL_POINT_SMOOTH);
    }
    if(dotted){
        glLineStipple(3, 0x1111);
        glEnable(GL_LINE_STIPPLE);
    }
    line_color.getRgbF(&r, &g, &b, &a);
    glColor4f(r, g, b, a);
    glDrawElements(GL_LINES, n_faces, GL_UNSIGNED_INT, faces);
    qDebug() << "PaintGL finished";
    glDisable(GL_LINE_STIPPLE);
}

void glwidget::rotate(float alpha, int type, float pos_x, float pos_y, float pos_z){
    s21_rotate(points, n_points, alpha, type, pos_x, pos_y, pos_z);
    update();
}

glwidget::~glwidget()
{
    if (points) {
        free(points);
    }
    if (faces) {
        free(faces);
    }
}


void glwidget::loadModel(const QString& fileName)
{
    QByteArray byteArray = fileName.toLocal8Bit();
    const char* filePath = byteArray.constData();

    if (points) {
        free(points);
        points = NULL;
    }
    if (faces) {
        free(faces);
        faces = NULL;
    }

    // Reset n_vertices and n_indices before parsing the new file
    n_points = 0;
    n_faces = 0;

    char mainInput[512] = {'\0'};
    strncpy(mainInput, filePath, 512);

    int res = s21_parse(mainInput, &points, &faces, &n_points, &n_faces);

    qDebug() << "Finished parsing the OBJ file";
    if (res)
        update();
    else {
        if (points) {
            free(points);
            points = NULL;
        }
        if (faces) {
            free(faces);
            faces = NULL;
        }
        n_points = 0;
        n_faces = 0;
        QMessageBox::warning(this, "Ошибка: некоректные данные",
                             "Ошибка: некоректные данные"
                             "Отредактируйте значения!");
    }
}


void glwidget::movement(float delta, int type){
    s21_movement(points, n_points, delta, type);
    update();
}
