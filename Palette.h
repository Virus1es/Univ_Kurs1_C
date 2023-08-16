#pragma once
#include "Colors.h"

// ������������, �������� ����� ��� ������ - ����� ��������
// enum ������� { ������ �������� };

// ������� ���������� - ������ �������������
enum Palette {
    mainColor = GRAY_ON_LTBLACK,   // �������� ���� ������
    resultColor = WHITE_ON_LTBLACK, // ���� ������ �����������
    infoColor = BLACK_ON_LTCYAN,    // ���� ������ �������������� ���������
    acctColor = RED_ON_WHITE,       // ���� �������� ������ � ������������� ������
    hintColor = BLACK_ON_WHITE,     // ���� ����������� ������ � ������������� ������  
    errColor = WHITE_ON_RED,        // ���� ������ ��������� �� ������
    resColor = LTCYAN_ON_LTBLACK,   // ����� ��������� ��������
    titleColor = WHITE_ON_LTBLACK,  // ����� ��������� �������
    consColor = GRAY_ON_BLACK       // ���� �������
};