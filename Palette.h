#pragma once
#include "Colors.h"

// перечисление, задающее новый тип данных - набор констант
// enum »м€“ипа { список констант };

// палитра приложени€ - задаем перечислением
enum Palette {
    mainColor = GRAY_ON_LTBLACK,   // основной цвет вывода
    resultColor = WHITE_ON_LTBLACK, // цвет вывода результатов
    infoColor = BLACK_ON_LTCYAN,    // цвет вывода информационных сообщений
    acctColor = RED_ON_WHITE,       // цвет активных клавиш в навигационной строке
    hintColor = BLACK_ON_WHITE,     // цвет по€сн€ющего текста в навигационной строке  
    errColor = WHITE_ON_RED,        // цвет вывода сообщени€ об ошибке
    resColor = LTCYAN_ON_LTBLACK,   // вывод элементов массивов
    titleColor = WHITE_ON_LTBLACK,  // вывод заголовка массива
    consColor = GRAY_ON_BLACK       // цвет консоли
};