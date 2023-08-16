#ifndef PCH_H
#define PCH_H

// для использования старых, небезопасных функций, например sprintf()
#define _CRT_SECURE_NO_WARNINGS

// использование математических констант, современный стиль
#include <corecrt_math_defines.h>

#include <iostream>  // этот файл делает доступными инженерные функции  
#include <iomanip>   // для манипуляторов вывода setw(), setprecision()
#include <Windows.h> // для использования функций WinAPI
#include <conio.h>
#include <vector>
#include <sstream>   // для объекта ostringstream

using namespace std;

// объявление символической константы - кодовой страницы
#define CODE_PAGE 1251

// для единообразия кодируем также команду очистки консоли
#define Cls() system("cls")


#endif //PCH_H
