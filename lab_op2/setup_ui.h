#ifndef SETUP_UI_H
#define SETUP_UI_H

#include "mainwindow.h"
#include <qboxlayout.h>

void setupUi(MainWindow* window);

void setupFileLayout(MainWindow* window, QHBoxLayout* fileLayout);
void setupInputLayout(MainWindow* window, QHBoxLayout* inputLayout);
void setupButtonLayout(MainWindow* window, QHBoxLayout* buttonLayout);
void setupTableWidget(MainWindow* window);
void setupStatLayout(MainWindow* window, QHBoxLayout* statLayout);

#endif // SETUP_UI_H
