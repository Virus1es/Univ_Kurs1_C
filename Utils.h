#pragma once

// коды функциональных клавиш
// перечисление, задающее новый тип данных - набор констант
// enum »м¤“ипа { список констант };
enum FKeys { 
	K_F1 = 59,
	K_F2,
	K_F3,
	K_F4,
	K_F5,
	K_F6,
	K_F7,
	K_F8,
	K_F9,
	K_F10
};

// процедура подготовки консоли к работе приложения
void init(const wchar_t title[] = L"Заголовок приложения");

// получение кода нажатой клавиши
int getKey(const char prompt[] = "\nНажмите любую клавишу для продолжения. . . ");

// генерация случайного числа
int    getRand(int low, int high);
double getRand(double low, double high);

// задание цвета консоли
void setColor(short color);

// ввод целого числа
int getInt();

// вывод сообщения "В разработке" 
void showUnderConstruction(short width, short mainColor, short infoColor);

// вывод произвольного текстового сообщения
void showMessage(const char msg[], short msgColor, short mainColor);
