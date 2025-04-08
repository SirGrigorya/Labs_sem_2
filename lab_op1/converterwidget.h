#ifndef CONVERTERWIDGET_H
#define CONVERTERWIDGET_H

#include <QWidget>
#include <QLineEdit>
#include <QComboBox>
#include <QPushButton>
#include <QLabel>

class ConverterWidget : public QWidget {
    Q_OBJECT
public:
    explicit ConverterWidget(QWidget *parent = nullptr);
    void setupConnections();

private:
    QLineEdit *inputField;
    QComboBox *fromBaseComboBox;
    QComboBox *toBaseComboBox;
    QPushButton *convertButton;
    QLineEdit *outputField;
    QLabel *errorLabel;
};

#endif // CONVERTERWIDGET_H
