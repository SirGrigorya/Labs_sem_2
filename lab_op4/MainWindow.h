#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Figure2D.h"

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
    void on_ButtonChooseFile_clicked();

    void on_ButtonLoadData_clicked();

    void on_ButtonArrowUp_clicked();

    void on_ButtonMinusScale_clicked();

    void on_ButtonArrowLeft_clicked();

    void on_ButtonArrowDown_clicked();

    void on_ButtonArrowRight_clicked();

    void on_ButtonCenter_clicked();

    void on_ButtonPlusScale_clicked();

    void on_ButtonNormalize_clicked();

private:
    void clear();
    void setError(int num);


    void redrawPicture(Figure2D &figure);
    void drawFigure2D(QPainter &painter, Figure2D &figure, float baseX, float baseY);
    void reloadPicture();

    bool getNormalizeValues(float &min, float &max);

private:
    Ui::MainWindow *ui;
};

int CheckError(int status);
#endif // MAINWINDOW_H
