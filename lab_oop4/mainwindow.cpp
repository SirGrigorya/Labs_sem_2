#include "MainWindow.h"
#include "ui_MainWindow.h"
#include <QFileDialog>
#include "SceneDrawer/QtSceneDrawer.h"
#include "Facade/FacadeOperationResult.h"
#include "FileReader/FileReader.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    setDefaultNormalizeParams();

    double width = ui->label_draw->width();
    double height = ui->label_draw->height();

    _picture = new QPicture;
    _picture->setBoundingRect(QRect(QPoint(0, 0), QPoint(width, height)));

    _facade = new Facade(new FileReader, new QtSceneDrawer(_picture));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::move_scene()
{
    QPushButton* button = (QPushButton*)sender();
    float x_move = 0;
    float y_move = 0;
    QString command = button->text();
    if (command == "up")
    {
        y_move = -3;
    }
    else if (command == "down")
    {
        y_move = 3;
    }
    else if (command == "left")
    {
        x_move = -3;
    }
    else if (command == "right")
    {
        x_move = 3;
    }
    _facade->moveScene(x_move, y_move, 0);
    _facade->drawScene();
    ui->label->setPicture(*_picture);
}

void MainWindow::scale_scene()
{
    QPushButton* button = (QPushButton*)sender();
    float scale = 1;
    QString command = button->text();
    if (command == "+")
    {
        scale += 0.1;
    }
    else if (command == "-")
    {
        scale -= 0.1;
    }
    _facade->scaleScene(scale, scale, 0);
    _facade->drawScene();
    ui->label->setPicture(*_picture);
}

void MainWindow::rotate_scene()
{
    QPushButton* button = (QPushButton*)sender();
    double x_rotate = 0;
    double y_rotate = 0;
    QString command = button->text();
    if (command == "up")
    {
        x_rotate = 3;
    }
    else if (command == "down")
    {
        x_rotate = -3;
    }
    else if (command == "left")
    {
        y_rotate = -3;
    }
    else if (command == "right")
    {
        y_rotate = 3;
    }
    _facade->rotateScene(x_rotate, y_rotate, 1);
    _facade->drawScene();
    ui->label->setPicture(*_picture);
}

void MainWindow::on_ButtonChooseFile_clicked()
{
    QString filename = QFileDialog::getOpenFileName(this, "Choose CSV file", "", "CSV Files(*.csv)");
    _facade->setFilePath(filename.toStdString());

    ui->label->setText("Файл: " + filename.right(filename.length() - filename.lastIndexOf('/') - 1));
    ui->ErrorLabel->clear();
}

void MainWindow::setDefaultNormalizeParams()
{
    ui->InputNormalizeMin->setText("0.0");
    ui->InputNormalizeMax->setText("30.0");
    ui->InputNormalizeXStep->setText("1.0");
    ui->InputNormalizeYStep->setText("1.0");
}

NormalizationParameters MainWindow::getNormalizeParams()
{
    return NormalizationParameters(ui->InputNormalizeMin->text().toFloat(),
                                   ui->InputNormalizeMax->text().toFloat(),
                                   ui->InputNormalizeXStep->text().toFloat(),
                                   ui->InputNormalizeYStep->text().toFloat());
}

void MainWindow::on_ButtonLoadData_clicked()
{
    FacadeOperationResult result;
    NormalizationParameters params = getNormalizeParams();
    result = _facade->loadScene(params);
    if (!result.isSuccess())
    {
        ui->ErrorLabel->setText(QString::fromStdString(result.getErrorMessage()));
        return;
    }
    _facade->drawScene();
    ui->label_draw->setPicture(*_picture);
}

void MainWindow::on_ButtonNormalize_clicked()
{
    on_ButtonLoadData_clicked();
}

void MainWindow::on_ButtonArrowUp_clicked()
{
    _facade->rotateScene(5.0, 0.0, 1);
    _facade->drawScene();
    ui->label_draw->setPicture(*_picture);
}

void MainWindow::on_ButtonArrowLeft_clicked()
{
    _facade->rotateScene(0.0, -5.0, 1);
    _facade->drawScene();
    ui->label_draw->setPicture(*_picture);
}

void MainWindow::on_ButtonArrowDown_clicked()
{
    _facade->rotateScene(-5.0, 0.0, 1);
    _facade->drawScene();
    ui->label_draw->setPicture(*_picture);
}

void MainWindow::on_ButtonArrowRight_clicked()
{
    _facade->rotateScene(0.0, 5.0, 1);
    _facade->drawScene();
    ui->label_draw->setPicture(*_picture);
}

void MainWindow::on_ButtonPlusScale_clicked()
{
    _facade->scaleScene(1.1, 1.1, 0);
    _facade->drawScene();
    ui->label_draw->setPicture(*_picture);
}

void MainWindow::on_ButtonMinusScale_clicked()
{
    _facade->scaleScene(0.9, 0.9, 0);
    _facade->drawScene();
    ui->label_draw->setPicture(*_picture);
}

void MainWindow::on_ButtonMoveUp_clicked()
{
    _facade->moveScene(0.0, -5.0, 0);
    _facade->drawScene();
    ui->label_draw->setPicture(*_picture);
}

void MainWindow::on_ButtonMoveLeft_clicked()
{
    _facade->moveScene(-5.0, 0.0, 0);
    _facade->drawScene();
    ui->label_draw->setPicture(*_picture);
}

void MainWindow::on_ButtonMoveRight_clicked()
{
    _facade->moveScene(5.0, 0.0, 0);
    _facade->drawScene();
    ui->label_draw->setPicture(*_picture);
}

void MainWindow::on_ButtonMoveDown_clicked()
{
    _facade->moveScene(0.0, 5.0, 0);
    _facade->drawScene();
    ui->label_draw->setPicture(*_picture);
}
