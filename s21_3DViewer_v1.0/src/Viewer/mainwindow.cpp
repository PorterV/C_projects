#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "glwidget.h"


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    setWindowTitle("3D_Viewer");
    glWidget = this->findChild<glwidget *>("openGLWidget");
    loadSetting();
    Q_ASSERT(glWidget);

}


MainWindow::~MainWindow()
{
    if(gif)
        free(gif);
    saveSetting();
    delete ui;
}


void MainWindow::saveSetting() {
    QSettings settings(QApplication::applicationDirPath() + "/user_settings",
                       QSettings::NativeFormat);
    settings.setValue("lineType", glWidget->dotted);
    settings.setValue("lineSize", glWidget->line_size);

    settings.setValue("pointType", glWidget->point_type);
    settings.setValue("pointSize", glWidget->point_size);

    settings.setValue("colorPoint", glWidget->point_color);
    settings.setValue("colorBack", glWidget->getBackgroundColor());
    settings.setValue("colorLine", glWidget->line_color);

    settings.setValue("ortho", glWidget->ortho);
}

void MainWindow::loadSetting() {
    QSettings settings(QApplication::applicationDirPath() + "/user_settings",
                       QSettings::NativeFormat);

    glWidget->dotted = settings.value("lineType").toInt();
    ui->ortho->setCurrentIndex(glWidget->dotted);
    glWidget->line_size = settings.value("lineSize").toFloat();
    ui->line_size->setValue(glWidget->line_size);
    glWidget->point_type = settings.value("pointType").toInt();
    ui->point_type->setCurrentIndex(glWidget->point_type);
    glWidget->point_size = settings.value("pointSize").toFloat();
    ui->point_size->setValue(glWidget->point_size);
    glWidget->setBackgroundColor(settings.value("colorBack").value<QColor>());
    background_color.setColor(QPalette::Window, glWidget->getBackgroundColor());
    ui->background_color->setAutoFillBackground(true);
    ui->background_color->setPalette(background_color);
    ui->background_color->show();
    glWidget->line_color = settings.value("colorLine").value<QColor>();
    line_color.setColor(QPalette::Window, glWidget->line_color);
    ui->line_color->setAutoFillBackground(true);
    ui->line_color->setPalette(line_color);
    ui->line_color->show();
    glWidget->point_color = settings.value("colorPoint").value<QColor>();
    point_color.setColor(QPalette::Window, glWidget->point_color);
    ui->point_color->setAutoFillBackground(true);
    ui->point_color->setPalette(point_color);
    ui->point_color->show();
    glWidget->ortho = settings.value("ortho").toInt();
    glWidget->update();
}


void MainWindow::on_pushButton_clicked()
{
    QString fileFilter = "OBJ Files (*.obj)";
    QString fileName= QFileDialog::getOpenFileName(this, "Choose File","./", fileFilter);


    if(fileName.isEmpty())
        return;

    qDebug() << "Selected file:" << fileName;
    QFileInfo fileInfo(fileName);
    QString absoluteFilePath = fileInfo.absoluteFilePath();
    qDebug() << "Absolute file path:" << absoluteFilePath;
    glWidget->ortho = ui->ortho->currentIndex();
    glWidget->loadModel(absoluteFilePath);
    ui->info->clear();
    ui->info->append(fileInfo.fileName());
    ui->info->append("Dottes: " + QString::number(glWidget->n_points));
    ui->info->append("Lines: " + QString::number(glWidget->n_faces));
    ui->scale->setValue(50);
    ui->x_rotate->setValue(0);
    ui->y_rotate->setValue(0);
    ui->z_rotate->setValue(0);
    ui->x_move->setValue(0);
    ui->y_move->setValue(0);
    ui->z_move->setValue(0);
    pos_now = 50;
    x_pos_now = 0;
    y_pos_now = 0;
    z_pos_now = 0;
    x_angle_now = 0;
    y_angle_now = 0;
    z_angle_now = 0;
}


void MainWindow::on_scale_sliderMoved(int position)
{
    float pos = position;
    glWidget->scale_resize((pos / pos_now));
    pos_now = position;
}



void MainWindow::on_x_rotate_sliderMoved(int position)
{
    float pos = position;
    float alpha = ((pos-x_angle_now) / 180.0) * M_PI;
    glWidget->rotate(alpha, X, x_pos_now, y_pos_now, z_pos_now);
    x_angle_now = position;
}


void MainWindow::on_y_rotate_sliderMoved(int position)
{
    float pos = position;
    float alpha = ((pos-y_angle_now) / 180.0) * M_PI;
    glWidget->rotate(alpha, Y, x_pos_now, y_pos_now, z_pos_now);
    y_angle_now = position;
}


void MainWindow::on_z_rotate_sliderMoved(int position)
{
    float pos = position;
    float alpha = ((pos-z_angle_now) / 180.0) * M_PI;
    glWidget->rotate(alpha, Z, x_pos_now, y_pos_now, z_pos_now);
    z_angle_now = position;
}


void MainWindow::on_x_move_sliderMoved(int position)
{
    float pos = position;
    glWidget->movement((x_pos_now-pos)*0.1, X);
    x_pos_now = position;
}


void MainWindow::on_z_move_sliderMoved(int position)
{
    float pos = position;
    glWidget->movement((y_pos_now-pos)*0.1, Y);
    y_pos_now = position;
}


void MainWindow::on_y_move_sliderMoved(int position)
{
    float pos = position;
    glWidget->movement((z_pos_now-pos)*0.1, Z);
    z_pos_now = position;
}


void MainWindow::on_choose_color_line_clicked()
{
    glWidget->line_color = QColorDialog::getColor(Qt::white, this );
    line_color.setColor(QPalette::Window, glWidget->line_color);
    if(glWidget->line_color.isValid() )
    {
        ui->line_color->setAutoFillBackground(true);
        ui->line_color->setPalette(line_color);
        ui->line_color->show();
    }
}


void MainWindow::on_choose_color_point_clicked()
{
    glWidget->point_color = QColorDialog::getColor(Qt::white, this );
    point_color.setColor(QPalette::Window, glWidget->point_color);
    if(glWidget->point_color.isValid() )
    {
        ui->point_color->setAutoFillBackground(true);
        ui->point_color->setPalette(point_color);
        ui->point_color->show();
    }
}


void MainWindow::on_choose_color_background_clicked()
{
    QColor tmp = QColorDialog::getColor(Qt::white, this );
    background_color.setColor(QPalette::Window, tmp);
    if(tmp.isValid() )
    {
        glWidget->setBackgroundColor(tmp);
        ui->background_color->setAutoFillBackground(true);
        ui->background_color->setPalette(background_color);
        ui->background_color->show();
    }
}


void MainWindow::on_point_size_valueChanged(double arg1)
{
    glWidget->point_size = arg1;
    glWidget->update();
}


void MainWindow::on_line_size_valueChanged(double arg1)
{
    glWidget->line_size = arg1;
    glWidget->update();
}



void MainWindow::on_point_type_currentIndexChanged(int index)
{
    glWidget->point_type = index;
    glWidget->update();
}


void MainWindow::on_ortho_currentIndexChanged(int index)
{
    glWidget->ortho = index;
    glWidget->update();
}


void MainWindow::on_line_type_currentIndexChanged(int index)
{
    glWidget->dotted = index;
    glWidget->update();
}


void MainWindow::on_screenshot_clicked()
{
    QTimer::singleShot(1000, this, &MainWindow::screenshot);

}

void MainWindow::screenshot() {
    QPixmap qpx_pixmap = ui->openGLWidget->screen()->grabWindow(ui->openGLWidget->winId());
    save_screenshot(qpx_pixmap);
}

void MainWindow::save_screenshot(QPixmap originalPixmap) {
    const QString format = ui->format->currentText();
    QString initialPath = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    if (initialPath.isEmpty())
        initialPath = QDir::currentPath();
    initialPath += tr("/untitled.") + format;

    QFileDialog fileDialog(this, tr("Save As"), initialPath);
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setDirectory(initialPath);
    fileDialog.selectMimeTypeFilter("image/" + format);
    fileDialog.setDefaultSuffix(format);
    if (fileDialog.exec() != QDialog::Accepted)
        return;
    const QString fileName = fileDialog.selectedFiles().first();
    if (!originalPixmap.save(fileName)) {
        QMessageBox::warning(this, tr("Save Error"), tr("The image could not be saved to \"%1\".")
                                                         .arg(QDir::toNativeSeparators(fileName)));
    }
}

void MainWindow::on_gif_clicked()
{
    gif_start();
}

void MainWindow::gif_save(){
    const QString format = "gif";
    QString initialPath = QStandardPaths::writableLocation(QStandardPaths::PicturesLocation);
    if (initialPath.isEmpty())
        initialPath = QDir::currentPath();
    initialPath += tr("/untitled.") + format;

    QFileDialog fileDialog(this, tr("Save As"), initialPath);
    fileDialog.setAcceptMode(QFileDialog::AcceptSave);
    fileDialog.setFileMode(QFileDialog::AnyFile);
    fileDialog.setDirectory(initialPath);
    fileDialog.selectMimeTypeFilter("image/" + format);
    fileDialog.setDefaultSuffix(format);
    if (fileDialog.exec() != QDialog::Accepted)
        return;
    const QString fileName = fileDialog.selectedFiles().first();
    if (!(gif->save(fileName))) {
        QMessageBox::warning(this, tr("Save Error"), tr("The image could not be saved to \"%1\".")
                                                         .arg(QDir::toNativeSeparators(fileName)));
    }
}

void MainWindow::gif_start(){
    if(gif){
        free(gif);
    }
    gif = new QGifImage;
    gif->setDefaultDelay(100);
    frame_counter = 0;

    int del = ui->seconds->time().second() * 10;
    connect( &start, SIGNAL(timeout()), SLOT( make_gif()));
    start.start(del);
}

void MainWindow::make_gif(){
    if (frame_counter < 100){
        frame_counter++;
        gif->addFrame(ui->openGLWidget->screen()->grabWindow(ui->openGLWidget->winId()).toImage());
    } else {
        start.stop();
        gif_save();
    }
}
