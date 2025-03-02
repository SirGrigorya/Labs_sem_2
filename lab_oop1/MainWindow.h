#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTextEdit>
#include <QMenuBar>
#include <QInputDialog>
#include <QMessageBox>
#include "ShapeContainer.h"

class MainWindow : public QMainWindow {
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

private slots:
    void addCircle();
    void addRectangle();
    void addTriangle();
    void addConvexPolygon();
    void showFigures();
    void showAreas();
    void showTotalArea();
    void sortFigures();
    void deleteFigure();
    void deleteFiguresByArea();

private:
    QTextEdit *textEdit;
    MemoryManager memoryManager; // Используем MemoryManager для управления памятью

    void updateTextEdit();
};

#endif // MAINWINDOW_H
