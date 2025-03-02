#include "entrypoint.h"
#include "design.h"
#include "converter.h"
#include <cstdlib>

void runApplication() {
    QWidget *window = new QWidget();
    setupUI(window);

    // Получаем виджеты
    QLineEdit *inputField = getInputField(window);
    QComboBox *fromBaseComboBox = getFromBaseComboBox(window);
    QComboBox *toBaseComboBox = getToBaseComboBox(window);
    QPushButton *convertButton = getConvertButton(window);
    QLineEdit *outputField = getOutputField(window);
    QLabel *errorLabel = getErrorLabel(window);

    // Подключение обработчика кнопки
    QObject::connect(convertButton, &QPushButton::clicked, [=]() {
        // Получаем ввод пользователя
        QString inputText = inputField->text();
        int fromBase = fromBaseComboBox->currentData().toInt();
        int toBase = toBaseComboBox->currentData().toInt();

        char *result = (char *)malloc(100 * sizeof(char));
        if (!result) {
            errorLabel->setText("Ошибка выделения памяти.");
            return;
        }

        // Преобразуем QString в const char*
        const char *input = inputText.toStdString().c_str();

        // Выполняем конвертацию
        const char *error = convertNumber(input, fromBase, toBase, result);

        if (error) {
            errorLabel->setText(error); // Выводим ошибку
            outputField->clear();      // Очищаем поле результата
        } else {
            outputField->setText(result); // Выводим результат
            errorLabel->clear();
        }

        // Освобождаем выделенную память
        free(result);
    });

    window->show();
}
