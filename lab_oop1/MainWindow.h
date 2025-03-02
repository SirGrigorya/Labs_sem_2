#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QVector>
#include "shape.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void onAddButtonClicked();
    void onDeleteButtonClicked();
    void updateShapesList();

private:
    Ui::MainWindow *ui;
    QVector<Shape*> shapes;
};
#endif
