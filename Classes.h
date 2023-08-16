#pragma once
#include <winnt.h>

#pragma region Dish
class Dish
{
public:
	char* Name;  // поле названия блюда
	char* Type;  // поле типа блюда
	float Cost;  // поле цены блюда
	int Size;    // поле размера(г.,мг) блюда

	Dish();                                             // конструктор по умолчанию
	Dish(char* name, char* type, float cost, int size); // конструктор
	char* GetName();                                    // функция получения названия блюда
	char* GetType();                                    // функция получения типа блюда
	float GetCost();                                    // функция получения цены блюда
	int GetSize();                                      // функция получения размера(г.,мг) блюда
	void SetName(char* NewName);                        // функция присвоения названия блюда
	void SetType(char* NewType);                // функция присвоения типа блюда
	void SetCost(int NewCost);                          // функция присвоения цены блюда
	void SetSize(int NewSize);                          // функция присвоения размера(г.,мг) блюда
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
	Dish* dishes;                        // блюдо
	char* Type;                          // тип меню
	int DishCount;                       // количество блю в меню
									     
	Menu();                              // конструктор: по умолчанию
	Menu(char* type, int DishCount);     // конструктор: тип меню и количество блюд в нём
	Menu(char* type);				     // конструктор: только тип меню
	virtual char* GetType();             // функция получения типа меню
	virtual void SetType(char* NewType); // фукция установления нового типа меню
	int GetDishCount();                  // функция получения количества блюд меню
	float GetAvgCost();                  // функция получения средней цены блюд
	void ShowMenu(char** ArrFrases);     // функция вывода меню на экран
	void operator<(Dish* dish);          // перегрузка бинарного оператора(добавление блюда в меню)
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
	char* Type; // тип доставки
	float Cost; // стоимость доставки

	Deliver(char* type);                               // конструктор с типом доставки
	void SetType(char* NewType) override;              // переопределение наследованного сетера
	void ShowType(char** ArrFrases);                   // вывод типа доставки
	void ChangeType() override;                        // поменять тип достаки
};
#pragma endregion

#pragma region Pay 
class Pay : public TypedClasses
{
	char* Type;  // поле типа оплаты
public:

	Pay(char* type);                  // конструктор с типом оплаты
	void SetType(char* NewType);      // переопределение наследованного сетера
	void ChangeType() override;       // поменять тип оплаты
	void ShowType(char** ArrFrases);  // вывод типа оплаты
	
};
#pragma endregion

#pragma region Stock
class Stock
{
public:
	int Value;                     // поле объёма скидки
	vector <string> NamesDishStock; // массив названий блюд которым положена скидка
	 

	Stock();                                 // конструктор
	void SetStockValue(int NewValue);        // установить размер скидки
	int  GetStockValue();                    // взять размер скидки
	void FillStock(char** ArrFrases);        // заполнение массива скидок
	void PrintDishOfStock(char** ArrFrases); // функция выяснения есть ли на это блюдо скидка 
};
#pragma endregion

#pragma region Offer
class Offer
{
public:
	
	int DishCount = 0;              // количество заказанных блюд
	Dish OfferedDishes[10];         // массив блюд

	Offer();                                                  // конструктор
	void DeleteDish(int DishNumber);                          // функция удаления блюда по номеру в списке
	void DeleteOffer();                                       // функция удаления всего списка(очистка корзины)
	void AddDish(int ChooseDish, char** ArrFrases);           // функция добавления блюда в заказ
	int DishOffer(char** ArrFrases);                          // функция получения количества заказанных блюд и их вывод
	int SumCost(float DeliverCost, vector <string> Stoks);    // функция получения итоговой стоимости заказа
};

// функция перегрузки операции вывода
ostream& operator<<(ostream& os, const Dish& CurrentDish);

#pragma endregion

