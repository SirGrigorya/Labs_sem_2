#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include "Facade/Facade.h"

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
    void move_scene();
    void scale_scene();
    void rotate_scene();

    void on_ButtonChooseFile_clicked();

    void on_ButtonLoadData_clicked();

    void on_ButtonNormalize_clicked();

    void on_ButtonArrowUp_clicked();

    void on_ButtonArrowLeft_clicked();

    void on_ButtonArrowDown_clicked();

    void on_ButtonArrowRight_clicked();

    void on_ButtonPlusScale_clicked();

    void on_ButtonMinusScale_clicked();

    void on_ButtonMoveUp_clicked();

    void on_ButtonMoveLeft_clicked();

    void on_ButtonMoveRight_clicked();

    void on_ButtonMoveDown_clicked();

private:
    QPicture* _picture;
    Ui::MainWindow *ui;
    Facade* _facade;
    void setDefaultNormalizeParams();
    NormalizationParameters getNormalizeParams();
};
#endif // MAINWINDOW_H
