#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QImage>
#include <QMainWindow>
#include "glwidget.h"
#include <QFileDialog>
#include <QDebug>
#include <QColorDialog>
#include <QShortcut>
#include <QColorDialog>
#include <QTimer>
#include "qgifimage.h"

extern "C"{
#include <string.h>
}

enum rotation{
    X = 1,
    Y = 2,
    Z = 3
};

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


private slots:
    void on_pushButton_clicked();

    void on_scale_sliderMoved(int position);

    void on_x_rotate_sliderMoved(int position);

    void on_y_rotate_sliderMoved(int position);

    void on_z_rotate_sliderMoved(int position);

    void on_x_move_sliderMoved(int position);

    void on_z_move_sliderMoved(int position);

    void on_y_move_sliderMoved(int position);

    void on_choose_color_line_clicked();

    void on_choose_color_point_clicked();

    void on_choose_color_background_clicked();

    void on_point_size_valueChanged(double arg1);

    void on_line_size_valueChanged(double arg1);

    void on_point_type_currentIndexChanged(int index);

    void on_ortho_currentIndexChanged(int index);

    void on_line_type_currentIndexChanged(int index);

    void on_screenshot_clicked();

    void screenshot();

    void save_screenshot(QPixmap originalPixmap);

    void on_gif_clicked();

    void gif_start();

    void make_gif();

    void gif_save();

private:

    int frame_counter;
    void saveSetting();
    void loadSetting();
    Ui::MainWindow *ui;
    glwidget *glWidget;
    int pos_now = 50;
    float x_pos_now = 0;
    float y_pos_now = 0;
    float z_pos_now = 0;
    int x_angle_now = 0;
    int y_angle_now = 0;
    int z_angle_now = 0;
    QPalette point_color;
    QPalette line_color;
    QPalette background_color;
    QGifImage *gif;
    QTimer start;
};
#endif // MAINWINDOW_H
