#include "MainWindow.h"
#include "ui_MainWindow.h"
#include "qfiledialog.h"
#include <QStandardItemModel>
#include <QMessageBox>
#include <QGraphicsOpacityEffect>
#include <QPicture>
#include <QPainter>

#include "Figure2D.h"
#include "Execute.h"

#include "Point3D.h"

static QString fileSource = "";

static float rotX = 0.0;
static float rotY = 0.0;
static float rotZ = 0.0;
static float scale = 5.0;


MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    clear();
}

MainWindow::~MainWindow()
{
    delete ui;
}


void MainWindow::clear()
{
    rotX = 0.0;
    rotY = 0.0;
    rotZ = 0.0;
    scale = 5.0;
    fileSource = "";
    setError(0);
    ui->InputNormalizeMin->setText("0.0");
    ui->InputNormalizeMax->setText("30.0");
}

void MainWindow::on_ButtonLoadData_clicked()
{
    if(!fileSource.length())
        return;
    float min, max;
    if(getNormalizeValues(min, max))
    {
        operation_t operation;
        operation.type = OP_LOAD_DATA_FROM_FILE;
        operation.fileName = fileSource.toStdString();
        operation.minRange = min;
        operation.maxRange = max;

        result_t *result = executeOperation(&operation);

        if(result->error == NO_ERROR)
            reloadPicture();

        setError(result->error);
        delete result;
    }
}

void MainWindow::setError(int num)
{
    QString errorText = "";
    ui->LabelFileError->setText("");
    ui->LabelNormalizeError->setText("");
    switch(num)
    {
        case FILE_NOT_OPENED:
            errorText = "Невозможно открыть файл!";
            ui->LabelFileError->setText(errorText);
        break;
        case FILE_NOT_READED:
            errorText = "Невозможно прочитать файл!";
            ui->LabelFileError->setText(errorText);
        break;
        case NORMALIZE_NOT_FLOAT:
        errorText = "Неверное значение!";
        ui->LabelNormalizeError->setText(errorText);
        break;
        case NORMALIZE_WRONG:
        errorText = "Неверный порядок значений!";
        ui->LabelNormalizeError->setText(errorText);
        break;
    }

}

void MainWindow::on_ButtonChooseFile_clicked()
{
    QString file = QFileDialog::getOpenFileName(this, "Open File", "", "Таблица CSV (*.csv)");
    if(!file.length())
        return;

    fileSource = file;
    ui->label->setText("Файл: " + fileSource.right(fileSource.lastIndexOf('/') - 4));
}

void MainWindow::reloadPicture()
{
    operation_t operation;
    operation.type = OP_GET_FIGURE;
    operation.rotX = rotX;
    operation.rotY = rotY;
    operation.rotZ = rotZ;
    operation.scale = scale;

    result_t * result = executeOperation(&operation);

    redrawPicture(result->figure);
    delete result;
}

bool MainWindow::getNormalizeValues(float &min, float &max)
{
    bool status = true;
    bool statusMin, statusMax;
    min = ui->InputNormalizeMin->text().toFloat(&statusMin);
    max = ui->InputNormalizeMax->text().toFloat(&statusMax);

    if(!statusMin || !statusMax)
    {
        status = false;
        setError(NORMALIZE_NOT_FLOAT);
    }
    else if(min >= max)
    {
        status = false;
        setError(NORMALIZE_WRONG);
    }

    return status;
}

void MainWindow::redrawPicture(Figure2D &figure)
{
    QPicture picture;
    picture.setBoundingRect(QRect(QPoint(0, 0), QPoint(ui->label_draw->size().width(), ui->label_draw->size().height())));
    QPainter painter;
    painter.begin(&picture);

    float baseX = ui->label_draw->size().width() / 2;
    float baseY = ui->label_draw->size().height() / 2;


    Point3D point = Point3D(-15.0, -15.0, 0.0);
    point = transformPoint3D(point, -rotX, -rotY, -rotZ, scale);

    baseX = baseX + point.X;
    baseY = baseY + point.Y;

    QPen pen;
    painter.setPen(pen);
    drawFigure2D(painter, figure, baseX, baseY);

    painter.end();
    ui->label_draw->setPicture(picture);
}

void MainWindow::drawFigure2D(QPainter &painter, Figure2D &figure, float baseX, float baseY)
{
    int vericesCount = figure.count();
    for(int i = 0; i < vericesCount - 1; i++)
    {
        for(int j = i + 1; j < vericesCount; j++)
        {
            if(figure.edges[i][j])
            {
                painter.drawLine(baseX + figure.verices[i].X,
                                 baseY + figure.verices[i].Y,
                                 baseX + figure.verices[j].X,
                                 baseY + figure.verices[j].Y);
            }
        }
    }
}

void MainWindow::on_ButtonArrowDown_clicked()
{
    rotX += 10.0;
    if(rotX >= 360.0)
        rotX -= 360.0;

    reloadPicture();
}



void MainWindow::on_ButtonArrowRight_clicked()
{
    rotY += 10.0;
    if(rotY >= 360.0)
        rotY -= 360.0;

    reloadPicture();
}

void MainWindow::on_ButtonArrowUp_clicked()
{
    rotX -= 10.0;
    if(rotX < 0.0)
        rotX += 360.0;

    reloadPicture();
}

void MainWindow::on_ButtonArrowLeft_clicked()
{
    rotY -= 10.0;
    if(rotY < 0.0)
        rotY += 360.0;

    reloadPicture();
}

void MainWindow::on_ButtonCenter_clicked()
{
    scale = 5.0;
    rotX = 0.0;
    rotY = 0.0;
    rotZ = 0.0;

    reloadPicture();
}

void MainWindow::on_ButtonPlusScale_clicked()
{
    scale += 5.0;

    reloadPicture();
}

void MainWindow::on_ButtonMinusScale_clicked()
{
    if(scale <= 5.0)
        scale -= 1.0;
    else
        scale -= 5.0;

    reloadPicture();
}

void MainWindow::on_ButtonNormalize_clicked()
{
    on_ButtonLoadData_clicked();
}
