/********************************************************************************
** Form generated from reading UI file 'MainWindow.ui'
**
** Created by: Qt User Interface Compiler version 6.7.2
**
** WARNING! All changes made in this file will be lost when recompiling UI file!
********************************************************************************/

#ifndef UI_MAINWINDOW_H
#define UI_MAINWINDOW_H

#include <QtCore/QVariant>
#include <QtWidgets/QApplication>
#include <QtWidgets/QGroupBox>
#include <QtWidgets/QLabel>
#include <QtWidgets/QLineEdit>
#include <QtWidgets/QMainWindow>
#include <QtWidgets/QPushButton>
#include <QtWidgets/QWidget>

QT_BEGIN_NAMESPACE

class Ui_MainWindow
{
public:
    QWidget *centralwidget;
    QGroupBox *groupBox;
    QLabel *label;
    QPushButton *ButtonChooseFile;
    QPushButton *ButtonLoadData;
    QLabel *label_4;
    QGroupBox *groupBox_3;
    QLabel *label_7;
    QLineEdit *InputNormalizeMin;
    QLabel *label_3;
    QLabel *label_5;
    QLineEdit *InputNormalizeMax;
    QPushButton *ButtonNormalize;
    QLabel *label_8;
    QLabel *label_9;
    QLineEdit *InputNormalizeYStep;
    QLineEdit *InputNormalizeXStep;
    QGroupBox *groupBox_5;
    QLabel *label_draw;
    QLabel *ErrorLabel;
    QGroupBox *groupBox_2;
    QPushButton *ButtonArrowUp;
    QPushButton *ButtonArrowLeft;
    QPushButton *ButtonArrowRight;
    QPushButton *ButtonArrowDown;
    QPushButton *ButtonPlusScale;
    QPushButton *ButtonMinusScale;
    QLabel *label_6;
    QGroupBox *groupBox_4;
    QPushButton *ButtonMoveUp;
    QPushButton *ButtonMoveLeft;
    QPushButton *ButtonMoveRight;
    QPushButton *ButtonMoveDown;
    QLabel *label_10;

    void setupUi(QMainWindow *MainWindow)
    {
        if (MainWindow->objectName().isEmpty())
            MainWindow->setObjectName("MainWindow");
        MainWindow->resize(1250, 700);
        QSizePolicy sizePolicy(QSizePolicy::Policy::Fixed, QSizePolicy::Policy::Fixed);
        sizePolicy.setHorizontalStretch(0);
        sizePolicy.setVerticalStretch(0);
        sizePolicy.setHeightForWidth(MainWindow->sizePolicy().hasHeightForWidth());
        MainWindow->setSizePolicy(sizePolicy);
        MainWindow->setMinimumSize(QSize(1250, 700));
        MainWindow->setMaximumSize(QSize(1250, 700));
        MainWindow->setStyleSheet(QString::fromUtf8("QMainWindow {\n"
"	background-color: #2F3A56;\n"
"}"));
        centralwidget = new QWidget(MainWindow);
        centralwidget->setObjectName("centralwidget");
        groupBox = new QGroupBox(centralwidget);
        groupBox->setObjectName("groupBox");
        groupBox->setGeometry(QRect(10, 5, 300, 120));
        groupBox->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	background-color: #406D96;\n"
"	border: 0px;\n"
"	border-radius: 5px;\n"
"}"));
        groupBox->setFlat(true);
        label = new QLabel(groupBox);
        label->setObjectName("label");
        label->setGeometry(QRect(10, 30, 230, 20));
        QFont font;
        font.setFamilies({QString::fromUtf8("Noto Sans")});
        font.setBold(true);
        label->setFont(font);
        label->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font-size: 13px;\n"
"	color: #FFF;\n"
"}"));
        ButtonChooseFile = new QPushButton(groupBox);
        ButtonChooseFile->setObjectName("ButtonChooseFile");
        ButtonChooseFile->setGeometry(QRect(260, 30, 20, 20));
        ButtonChooseFile->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #fff;\n"
"	background-color: #E2474B;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	background-color: #b5505d;\n"
"}"));
        ButtonChooseFile->setFlat(false);
        ButtonLoadData = new QPushButton(groupBox);
        ButtonLoadData->setObjectName("ButtonLoadData");
        ButtonLoadData->setGeometry(QRect(80, 70, 140, 25));
        QFont font1;
        font1.setFamilies({QString::fromUtf8("Noto Sans")});
        font1.setPointSize(10);
        font1.setBold(true);
        ButtonLoadData->setFont(font1);
        ButtonLoadData->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #fff;\n"
"	background-color: #E2474B;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	color: #fff;\n"
"	background-color: #b5505d;\n"
"	border-radius: 5px;\n"
"}"));
        label_4 = new QLabel(groupBox);
        label_4->setObjectName("label_4");
        label_4->setGeometry(QRect(80, 0, 140, 16));
        label_4->setFont(font);
        label_4->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font-size: 14px;\n"
"	color: #FFF;\n"
"}"));
        label_4->setAlignment(Qt::AlignCenter);
        groupBox_3 = new QGroupBox(centralwidget);
        groupBox_3->setObjectName("groupBox_3");
        groupBox_3->setGeometry(QRect(10, 140, 300, 161));
        groupBox_3->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	background-color: #406D96;\n"
"	border: 0px;\n"
"	border-radius: 5px;\n"
"}"));
        label_7 = new QLabel(groupBox_3);
        label_7->setObjectName("label_7");
        label_7->setGeometry(QRect(60, 0, 180, 18));
        label_7->setFont(font);
        label_7->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font-size: 14px;\n"
"	color: #FFF;\n"
"}"));
        label_7->setAlignment(Qt::AlignCenter);
        InputNormalizeMin = new QLineEdit(groupBox_3);
        InputNormalizeMin->setObjectName("InputNormalizeMin");
        InputNormalizeMin->setGeometry(QRect(120, 25, 120, 20));
        InputNormalizeMin->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border-radius: 3px;\n"
"	background-color: #D8E8E8;\n"
"	selection-background-color: #A8D0DA;\n"
"	padding: 0 4px;\n"
"	font-family: Noto Sans;\n"
"	font-weight: bold;\n"
"	font-size: 12px;\n"
"}"));
        label_3 = new QLabel(groupBox_3);
        label_3->setObjectName("label_3");
        label_3->setGeometry(QRect(30, 25, 75, 20));
        label_3->setFont(font);
        label_3->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font-size: 12px;\n"
"	color: #FFF;\n"
"}"));
        label_3->setAlignment(Qt::AlignCenter);
        label_5 = new QLabel(groupBox_3);
        label_5->setObjectName("label_5");
        label_5->setGeometry(QRect(30, 50, 75, 20));
        label_5->setFont(font);
        label_5->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font-size: 12px;\n"
"	color: #FFF;\n"
"}"));
        label_5->setAlignment(Qt::AlignCenter);
        InputNormalizeMax = new QLineEdit(groupBox_3);
        InputNormalizeMax->setObjectName("InputNormalizeMax");
        InputNormalizeMax->setGeometry(QRect(120, 50, 120, 20));
        InputNormalizeMax->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border-radius: 3px;\n"
"	background-color: #D8E8E8;\n"
"	selection-background-color: #A8D0DA;\n"
"	padding: 0 4px;\n"
"	font-family: Noto Sans;\n"
"	font-weight: bold;\n"
"	font-size: 12px;\n"
"}"));
        ButtonNormalize = new QPushButton(groupBox_3);
        ButtonNormalize->setObjectName("ButtonNormalize");
        ButtonNormalize->setGeometry(QRect(110, 130, 100, 25));
        ButtonNormalize->setFont(font1);
        ButtonNormalize->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #fff;\n"
"	background-color: #E2474B;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	color: #fff;\n"
"	background-color: #b5505d;\n"
"	border-radius: 5px;\n"
"}"));
        label_8 = new QLabel(groupBox_3);
        label_8->setObjectName("label_8");
        label_8->setGeometry(QRect(30, 75, 75, 20));
        label_8->setFont(font);
        label_8->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font-size: 12px;\n"
"	color: #FFF;\n"
"}"));
        label_8->setAlignment(Qt::AlignCenter);
        label_9 = new QLabel(groupBox_3);
        label_9->setObjectName("label_9");
        label_9->setGeometry(QRect(30, 100, 75, 20));
        label_9->setFont(font);
        label_9->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font-size: 12px;\n"
"	color: #FFF;\n"
"}"));
        label_9->setAlignment(Qt::AlignCenter);
        InputNormalizeYStep = new QLineEdit(groupBox_3);
        InputNormalizeYStep->setObjectName("InputNormalizeYStep");
        InputNormalizeYStep->setGeometry(QRect(120, 100, 120, 20));
        InputNormalizeYStep->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border-radius: 3px;\n"
"	background-color: #D8E8E8;\n"
"	selection-background-color: #A8D0DA;\n"
"	padding: 0 4px;\n"
"	font-family: Noto Sans;\n"
"	font-weight: bold;\n"
"	font-size: 12px;\n"
"}"));
        InputNormalizeXStep = new QLineEdit(groupBox_3);
        InputNormalizeXStep->setObjectName("InputNormalizeXStep");
        InputNormalizeXStep->setGeometry(QRect(120, 75, 120, 20));
        InputNormalizeXStep->setStyleSheet(QString::fromUtf8("QLineEdit {\n"
"	border-radius: 3px;\n"
"	background-color: #D8E8E8;\n"
"	selection-background-color: #A8D0DA;\n"
"	padding: 0 4px;\n"
"	font-family: Noto Sans;\n"
"	font-weight: bold;\n"
"	font-size: 12px;\n"
"}"));
        groupBox_5 = new QGroupBox(centralwidget);
        groupBox_5->setObjectName("groupBox_5");
        groupBox_5->setGeometry(QRect(320, 5, 920, 691));
        groupBox_5->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	background-color: #D8E8E8;\n"
"	border-radius: 5px;\n"
"}"));
        label_draw = new QLabel(groupBox_5);
        label_draw->setObjectName("label_draw");
        label_draw->setGeometry(QRect(10, 10, 900, 650));
        ErrorLabel = new QLabel(groupBox_5);
        ErrorLabel->setObjectName("ErrorLabel");
        ErrorLabel->setGeometry(QRect(40, 10, 641, 16));
        ErrorLabel->setStyleSheet(QString::fromUtf8("QLabel\n"
"{\n"
"	color:red;\n"
"}"));
        groupBox_2 = new QGroupBox(centralwidget);
        groupBox_2->setObjectName("groupBox_2");
        groupBox_2->setGeometry(QRect(10, 315, 300, 115));
        groupBox_2->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	background-color: #406D96;\n"
"	border: 0px;\n"
"	border-radius: 5px;\n"
"}"));
        ButtonArrowUp = new QPushButton(groupBox_2);
        ButtonArrowUp->setObjectName("ButtonArrowUp");
        ButtonArrowUp->setGeometry(QRect(138, 35, 25, 25));
        ButtonArrowUp->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #fff;\n"
"	background-color: #E2474B;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	color: #fff;\n"
"	background-color: #b5505d;\n"
"	border-radius: 5px;\n"
"}"));
        ButtonArrowLeft = new QPushButton(groupBox_2);
        ButtonArrowLeft->setObjectName("ButtonArrowLeft");
        ButtonArrowLeft->setGeometry(QRect(108, 65, 25, 25));
        ButtonArrowLeft->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #fff;\n"
"	background-color: #E2474B;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	color: #fff;\n"
"	background-color: #b5505d;\n"
"	border-radius: 5px;\n"
"}"));
        ButtonArrowRight = new QPushButton(groupBox_2);
        ButtonArrowRight->setObjectName("ButtonArrowRight");
        ButtonArrowRight->setGeometry(QRect(168, 65, 25, 25));
        ButtonArrowRight->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #fff;\n"
"	background-color: #E2474B;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	color: #fff;\n"
"	background-color: #b5505d;\n"
"	border-radius: 5px;\n"
"}"));
        ButtonArrowDown = new QPushButton(groupBox_2);
        ButtonArrowDown->setObjectName("ButtonArrowDown");
        ButtonArrowDown->setGeometry(QRect(138, 65, 25, 25));
        ButtonArrowDown->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #fff;\n"
"	background-color: #E2474B;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	color: #fff;\n"
"	background-color: #b5505d;\n"
"	border-radius: 5px;\n"
"}"));
        ButtonPlusScale = new QPushButton(groupBox_2);
        ButtonPlusScale->setObjectName("ButtonPlusScale");
        ButtonPlusScale->setGeometry(QRect(208, 35, 25, 25));
        ButtonPlusScale->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #fff;\n"
"	background-color: #E2474B;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	color: #fff;\n"
"	background-color: #b5505d;\n"
"	border-radius: 5px;\n"
"}"));
        ButtonMinusScale = new QPushButton(groupBox_2);
        ButtonMinusScale->setObjectName("ButtonMinusScale");
        ButtonMinusScale->setGeometry(QRect(208, 65, 25, 25));
        ButtonMinusScale->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #fff;\n"
"	background-color: #E2474B;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	color: #fff;\n"
"	background-color: #b5505d;\n"
"	border-radius: 5px;\n"
"}"));
        label_6 = new QLabel(groupBox_2);
        label_6->setObjectName("label_6");
        label_6->setGeometry(QRect(80, 0, 140, 18));
        label_6->setFont(font);
        label_6->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font-size: 14px;\n"
"	color: #FFF;\n"
"}"));
        label_6->setAlignment(Qt::AlignCenter);
        groupBox_4 = new QGroupBox(centralwidget);
        groupBox_4->setObjectName("groupBox_4");
        groupBox_4->setGeometry(QRect(10, 445, 300, 115));
        groupBox_4->setStyleSheet(QString::fromUtf8("QGroupBox {\n"
"	background-color: #406D96;\n"
"	border: 0px;\n"
"	border-radius: 5px;\n"
"}"));
        ButtonMoveUp = new QPushButton(groupBox_4);
        ButtonMoveUp->setObjectName("ButtonMoveUp");
        ButtonMoveUp->setGeometry(QRect(138, 35, 25, 25));
        ButtonMoveUp->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #fff;\n"
"	background-color: #E2474B;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	color: #fff;\n"
"	background-color: #b5505d;\n"
"	border-radius: 5px;\n"
"}"));
        ButtonMoveLeft = new QPushButton(groupBox_4);
        ButtonMoveLeft->setObjectName("ButtonMoveLeft");
        ButtonMoveLeft->setGeometry(QRect(108, 65, 25, 25));
        ButtonMoveLeft->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #fff;\n"
"	background-color: #E2474B;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	color: #fff;\n"
"	background-color: #b5505d;\n"
"	border-radius: 5px;\n"
"}"));
        ButtonMoveRight = new QPushButton(groupBox_4);
        ButtonMoveRight->setObjectName("ButtonMoveRight");
        ButtonMoveRight->setGeometry(QRect(168, 65, 25, 25));
        ButtonMoveRight->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #fff;\n"
"	background-color: #E2474B;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	color: #fff;\n"
"	background-color: #b5505d;\n"
"	border-radius: 5px;\n"
"}"));
        ButtonMoveDown = new QPushButton(groupBox_4);
        ButtonMoveDown->setObjectName("ButtonMoveDown");
        ButtonMoveDown->setGeometry(QRect(138, 65, 25, 25));
        ButtonMoveDown->setStyleSheet(QString::fromUtf8("QPushButton {\n"
"	color: #fff;\n"
"	background-color: #E2474B;\n"
"	border-radius: 5px;\n"
"}\n"
"\n"
"QPushButton:hover {\n"
"	color: #fff;\n"
"	background-color: #b5505d;\n"
"	border-radius: 5px;\n"
"}"));
        label_10 = new QLabel(groupBox_4);
        label_10->setObjectName("label_10");
        label_10->setGeometry(QRect(80, 0, 140, 18));
        label_10->setFont(font);
        label_10->setStyleSheet(QString::fromUtf8("QLabel {\n"
"	font-size: 14px;\n"
"	color: #FFF;\n"
"}"));
        label_10->setAlignment(Qt::AlignCenter);
        MainWindow->setCentralWidget(centralwidget);

        retranslateUi(MainWindow);

        QMetaObject::connectSlotsByName(MainWindow);
    } // setupUi

    void retranslateUi(QMainWindow *MainWindow)
    {
        MainWindow->setWindowTitle(QCoreApplication::translate("MainWindow", "MainWindow", nullptr));
        groupBox->setTitle(QString());
        label->setText(QCoreApplication::translate("MainWindow", "\320\244\320\260\320\271\320\273: \320\236\321\202\321\201\321\203\321\201\321\202\320\262\321\203\320\265\321\202", nullptr));
        ButtonChooseFile->setText(QCoreApplication::translate("MainWindow", "...", nullptr));
        ButtonLoadData->setText(QCoreApplication::translate("MainWindow", "\320\227\320\260\320\263\321\200\321\203\320\267\320\270\321\202\321\214 \320\264\320\260\320\275\320\275\321\213\320\265", nullptr));
        label_4->setText(QCoreApplication::translate("MainWindow", "\320\236\321\202\320\272\321\200\321\213\321\202\320\270\320\265 \321\204\320\260\320\271\320\273\320\260", nullptr));
        groupBox_3->setTitle(QString());
        label_7->setText(QCoreApplication::translate("MainWindow", "\320\235\320\276\321\200\320\274\320\270\321\200\320\276\320\262\320\272\320\260 \320\267\320\275\320\260\321\207\320\265\320\275\320\270\320\271", nullptr));
        label_3->setText(QCoreApplication::translate("MainWindow", "\320\234\320\270\320\275\320\270\320\274\321\203\320\274:", nullptr));
        label_5->setText(QCoreApplication::translate("MainWindow", "\320\234\320\260\320\272\321\201\320\270\320\274\321\203\320\274:", nullptr));
        ButtonNormalize->setText(QCoreApplication::translate("MainWindow", "\320\237\321\200\320\270\320\274\320\265\320\275\320\270\321\202\321\214", nullptr));
        label_8->setText(QCoreApplication::translate("MainWindow", "\320\250\320\260\320\263 X:", nullptr));
        label_9->setText(QCoreApplication::translate("MainWindow", "\320\250\320\260\320\263 Y:", nullptr));
        groupBox_5->setTitle(QString());
        label_draw->setText(QString());
        ErrorLabel->setText(QString());
        groupBox_2->setTitle(QString());
        ButtonArrowUp->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        ButtonArrowLeft->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
        ButtonArrowRight->setText(QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
        ButtonArrowDown->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        ButtonPlusScale->setText(QCoreApplication::translate("MainWindow", "+", nullptr));
        ButtonMinusScale->setText(QCoreApplication::translate("MainWindow", "-", nullptr));
        label_6->setText(QCoreApplication::translate("MainWindow", "\320\222\321\200\320\260\321\211\320\265\320\275\320\270\320\265", nullptr));
        groupBox_4->setTitle(QString());
        ButtonMoveUp->setText(QCoreApplication::translate("MainWindow", "\342\206\221", nullptr));
        ButtonMoveLeft->setText(QCoreApplication::translate("MainWindow", "\342\206\220", nullptr));
        ButtonMoveRight->setText(QCoreApplication::translate("MainWindow", "\342\206\222", nullptr));
        ButtonMoveDown->setText(QCoreApplication::translate("MainWindow", "\342\206\223", nullptr));
        label_10->setText(QCoreApplication::translate("MainWindow", "\320\237\320\265\321\200\320\265\320\274\320\265\321\211\320\265\320\275\320\270\320\265", nullptr));
    } // retranslateUi

};

namespace Ui {
    class MainWindow: public Ui_MainWindow {};
} // namespace Ui

QT_END_NAMESPACE

#endif // UI_MAINWINDOW_H
