#pragma once
#include <winnt.h>

#pragma region Dish
class Dish
{
public:
	char* Name;  // ���� �������� �����
	char* Type;  // ���� ���� �����
	float Cost;  // ���� ���� �����
	int Size;    // ���� �������(�.,��) �����

	Dish();                                             // ����������� �� ���������
	Dish(char* name, char* type, float cost, int size); // �����������
	char* GetName();                                    // ������� ��������� �������� �����
	char* GetType();                                    // ������� ��������� ���� �����
	float GetCost();                                    // ������� ��������� ���� �����
	int GetSize();                                      // ������� ��������� �������(�.,��) �����
	void SetName(char* NewName);                        // ������� ���������� �������� �����
	void SetType(char* NewType);                // ������� ���������� ���� �����
	void SetCost(int NewCost);                          // ������� ���������� ���� �����
	void SetSize(int NewSize);                          // ������� ���������� �������(�.,��) �����
};
#pragma endregion

#pragma region Menu
static const int N = 20;
static vector <Dish> ArrDish(N);
static vector <Dish> ArrCurrentDish(N/4);
void ClaeanCurrentDish();

class Menu 
{
public:
	Dish* dishes;                        // �����
	char* Type;                          // ��� ����
	int DishCount;                       // ���������� ��� � ����
									     
	Menu();                              // �����������: �� ���������
	Menu(char* type, int DishCount);     // �����������: ��� ���� � ���������� ���� � ��
	Menu(char* type);				     // �����������: ������ ��� ����
	virtual char* GetType();             // ������� ��������� ���� ����
	virtual void SetType(char* NewType); // ������ ������������ ������ ���� ����
	int GetDishCount();                  // ������� ��������� ���������� ���� ����
	float GetAvgCost();                  // ������� ��������� ������� ���� ����
	void ShowMenu(char** ArrFrases);     // ������� ������ ���� �� �����
	void operator<(Dish* dish);          // ���������� ��������� ���������(���������� ����� � ����)
};
#pragma endregion

#pragma region TypedClasses
class TypedClasses
{
public:
	char* Type;
	virtual void ChangeType();
	virtual void SetType(char* NewType);
};
#pragma endregion

#pragma region Deliver
class Deliver : public Menu, public TypedClasses
{
public:
	char* Type; // ��� ��������
	float Cost; // ��������� ��������

	Deliver(char* type);                               // ����������� � ����� ��������
	void SetType(char* NewType) override;              // ��������������� �������������� ������
	void ShowType(char** ArrFrases);                   // ����� ���� ��������
	void ChangeType() override;                        // �������� ��� �������
};
#pragma endregion

#pragma region Pay 
class Pay : public TypedClasses
{
	char* Type;  // ���� ���� ������
public:

	Pay(char* type);                  // ����������� � ����� ������
	void SetType(char* NewType);      // ��������������� �������������� ������
	void ChangeType() override;       // �������� ��� ������
	void ShowType(char** ArrFrases);  // ����� ���� ������
	
};
#pragma endregion

#pragma region Stock
class Stock
{
public:
	int Value;                     // ���� ������ ������
	vector <string> NamesDishStock; // ������ �������� ���� ������� �������� ������
	 

	Stock();                                 // �����������
	void SetStockValue(int NewValue);        // ���������� ������ ������
	int  GetStockValue();                    // ����� ������ ������
	void FillStock(char** ArrFrases);        // ���������� ������� ������
	void PrintDishOfStock(char** ArrFrases); // ������� ��������� ���� �� �� ��� ����� ������ 
};
#pragma endregion

#pragma region Offer
class Offer
{
public:
	
	int DishCount = 0;              // ���������� ���������� ����
	Dish OfferedDishes[10];         // ������ ����

	Offer();                                                  // �����������
	void DeleteDish(int DishNumber);                          // ������� �������� ����� �� ������ � ������
	void DeleteOffer();                                       // ������� �������� ����� ������(������� �������)
	void AddDish(int ChooseDish, char** ArrFrases);           // ������� ���������� ����� � �����
	int DishOffer(char** ArrFrases);                          // ������� ��������� ���������� ���������� ���� � �� �����
	int SumCost(float DeliverCost, vector <string> Stoks);    // ������� ��������� �������� ��������� ������
};

// ������� ���������� �������� ������
ostream& operator<<(ostream& os, const Dish& CurrentDish);

#pragma endregion

