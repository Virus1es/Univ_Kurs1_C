#pragma once

// ���� �������������� ������
// ������������, �������� ����� ��� ������ - ����� ��������
// enum �줓��� { ������ �������� };
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

// ��������� ���������� ������� � ������ ����������
void init(const wchar_t title[] = L"��������� ����������");

// ��������� ���� ������� �������
int getKey(const char prompt[] = "\n������� ����� ������� ��� �����������. . . ");

// ��������� ���������� �����
int    getRand(int low, int high);
double getRand(double low, double high);

// ������� ����� �������
void setColor(short color);

// ���� ������ �����
int getInt();

// ����� ��������� "� ����������" 
void showUnderConstruction(short width, short mainColor, short infoColor);

// ����� ������������� ���������� ���������
void showMessage(const char msg[], short msgColor, short mainColor);
