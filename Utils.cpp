#include "pch.h"
#include "Utils.h"
#include "Colors.h"
#include "Palette.h"

// ��������� ���������� ���������� - ����������� ����������
// ��������� � ������������ ���������� (�������� - singleton),
// ������� ��������� - ������ ���� ��������� ����
static HANDLE h = GetStdHandle(STD_OUTPUT_HANDLE);

// �������� �����
// typedef ������ �������� ����� ��������;
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


// ��������� ���� ������� �������
int getKey(const char prompt[])
{
	cout << prompt;

	int key = _getch();
	if (key == 0 || key == 224) key = _getch();

    return key;
} // getKey


// ��������� ���������� �����
int getRand(int low, int high)
{
	return low + rand() % (high - low + 1);
} // getRand


double getRand(double low, double high)
{
	return low + (high - low) * rand() / RAND_MAX;
} // getRand


// ������� ����� �������
void setColor(short color)
{
	SetConsoleTextAttribute(h, color);
} // SetColor


// ���� ������ �����
int getInt()
{
	int value;
	while(true) {
		// ���������� ����
		cout << "? ";
		cin >> value;

		// ���� ����� �����, ����� �� ����� � �� �������
		if (!cin.fail()) break;

		// ���� ��� �� ����� - ����� ��������� ������,
		// ������ ������ �����
		cin.clear();
		cin.ignore(cin.rdbuf()->in_avail(), '\n');
	} // while

	return value;
} // GetInt


// ����� ��������� "������� � ����������"
void showUnderConstruction(short width, short mainColor, short infoColor)
{
	ostringstream oss;
	oss << "\n\n\n\n" << left
		<< "\t" << setw(width) << " " << "\n"
		<< "\t" << setw(width) << "    [����������]" << "\n"
		<< "\t" << setw(width) << "    ������� � ����������" << "\n"
		<< "\t" << setw(width) << " " << "\n"
		<< "\t" << setw(width) << "    ������� ����� ������� ��� �����������..." << "\n"
		<< "\t" << setw(width) << " " << "\n"
		<< "\t" << setw(width) << " " << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n" << right;
	showMessage(oss.str().c_str(), infoColor, mainColor);
}

// ����� ���������
void showMessage(const char msg[], short msgColor, short mainColor)
{
	setColor(msgColor);
	cout << left << msg << right;
	setColor(mainColor);
}