#include "pch.h"
#include "Utils.h"
#include "Colors.h"
#include "Palette.h"

// локальная глобальная переменная - статическая переменная
// существуе в единственном экземпляре (синглтон - singleton),
// область видимости - данный файл исходного кода
static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

// синонимы типов
// typedef старое название новое название;
// typedef unsigned char MyByte;
// MyByte x;

void init(const wchar_t title[])
{
	SetConsoleTitle(title);

	SetConsoleOutputCP(CODE_PAGE);
	SetConsoleCP(CODE_PAGE);
	srand(GetTickCount64());
	cout << fixed << setprecision(2);
	
	setColor(mainColor);
	Cls();
} // init


// получение кода нажатой клавиши
int getKey(const char prompt[])
{
	cout << prompt;

	int key = _getch();
	if (key == 0 || key == 224) key = _getch();

    return key;
} // getKey


// генерация случайного числа
int getRand(int low, int high)
{
	return low + rand() % (high - low + 1);
} // getRand


double getRand(double low, double high)
{
	return low + (high - low) * rand() / RAND_MAX;
} // getRand


// задание цвета консоли
void setColor(short color)
{
	SetConsoleTextAttribute(h, color);
} // SetColor


// ввод целого числа
int getInt()
{
	int value;
	while(true) {
		// собственно ввод
		cout << "? ";
		cin >> value;

		// Если ввели число, выход из цикла и из функции
		if (!cin.fail()) break;

		// Если это не число - сброс состояния ошибки,
		// очиска буфера ввода
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail(), '\n');
	} // while

	return value;
} // GetInt


// Вывод сообщения "Функция в разработке"
void showUnderConstruction(short width, short mainColor, short infoColor)
{
	ostringstream oss;
	oss << "\n\n\n\n" << left
		<< "\t" << setw(width) << " " << "\n"
		<< "\t" << setw(width) << "    [Информация]" << "\n"
		<< "\t" << setw(width) << "    Функция в разработке" << "\n"
		<< "\t" << setw(width) << " " << "\n"
		<< "\t" << setw(width) << "    Нажмите любую клавишу для продолжения..." << "\n"
		<< "\t" << setw(width) << " " << "\n"
		<< "\t" << setw(width) << " " << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << right;
	showMessage(oss.str().c_str(), infoColor, mainColor);
}

// вывод сообщения
void showMessage(const char msg[], short msgColor, short mainColor)
{
	setColor(msgColor);
	cout << left << msg << right;
	setColor(mainColor);
}