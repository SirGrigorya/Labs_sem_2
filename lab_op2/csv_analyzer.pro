QT += core gui widgets

CONFIG += c++17

TARGET = csv_analyzer
TEMPLATE = app

SOURCES += \
    main.cpp \
    mainwindow.cpp \
    logic.c \
    entry.c

HEADERS += \
    mainwindow.h \
    logic.h \
    entry.h

# Для Windows может потребоваться
win32 {
    LIBS += -luser32
}

# Настройки компилятора
QMAKE_CXXFLAGS += -Wall -Wextra -Werror
QMAKE_CFLAGS += -Wall -Wextra -Werror

# Отключаем автоматическое создание ui_* файлов
FORMS =

# Отключаем мета-объектный компилятор для чистого C
CONFIG += no_moc
