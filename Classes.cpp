#include "Colors.h"
#include "Palette.h"
#include "pch.h"
#include "Utils.h"
#include "Classes.h"
#include "Functions.h"

#pragma region Dish
Dish::Dish() {
	Name = NULL;
	Type = NULL;
	Cost = 0;
	Size = 0;
}

Dish::Dish(char* name, char* type, float cost, int size)
{
	Name = name;
	Type = type;
	Cost = cost;
	Size = size;
}

char* Dish::GetName() {
	return Name;
}

char* Dish::GetType() {
	return Type;
}

float Dish::GetCost() {
	return Cost;
}

int Dish::GetSize() {
	return Size;
}

void Dish::SetName(char* NewName) {
	Name = NewName;
}

void Dish::SetType(char* NewType) {
	Type = NewType;
}

void Dish::SetCost(int NewCost) {
	Cost = NewCost;
}

void Dish::SetSize(int NewSize) {
	Size = NewSize;
}
#pragma endregion

#pragma region Menu

Menu::Menu() {
	dishes = NULL;
	Type = nullptr;
	DishCount = 0;
}

Menu::Menu(char* type, int dishCount)
{
	dishes = NULL;
	Type = type;
	DishCount = dishCount;
}

Menu::Menu(char* type)
{
	dishes = NULL;
	Type = type;
	DishCount = 0;
}

// функция получения типа меню
int Menu::GetDishCount() {
	return DishCount;
}

char* Menu::GetType() {
	return Type;
}

void Menu::SetType(char *NewType) {
	Type = NewType;
}

float Menu::GetAvgCost() {
	float sum = 0;
	int i = 0;
	while (ArrCurrentDish[i].GetName() != nullptr) {
		sum += ArrCurrentDish[i].GetCost();
		++i;
	}
	return sum / DishCount;
}

void Menu::ShowMenu(char** ArrFrases) {
	setColor(infoColor);
	int i = 0;

	cout << "\t ---------------" << ArrFrases[RowInMenu] << ": " 
		 << setw(13) << ArrCurrentDish[i].GetType() << "----------------\n"
		 << "\t +---+----------------+------------+-------------+ \n"
		 << "\t " << ArrFrases[TableRow] << " \n"
		 << "\t +---+----------------+------------+-------------+ \n";
	do {
		cout << "\t |" << setw(3) << i + 1 << "|" << setw(16) << ArrCurrentDish[i].GetName() << "|" << setw(12)
			<< ArrCurrentDish[i].GetSize() << "|" << setw(13) 
			<< ArrCurrentDish[i].GetCost() << "| \n"; // выводим значения элемента
		++i;
	} while (i < N/4);
	cout << "\t +---+----------------+------------+-------------+ \n";
	setColor(mainColor);


}
// перегрузка бинарного оператора(добавление блюда в меню)
void Menu::operator <(Dish* dish)
{
	DishCount++;
	for (int i = 0; i < N/4; i++)
	{
		if (ArrCurrentDish[i].GetName() == NULL)
		{
			ArrCurrentDish[i].SetName((*dish).GetName());
			ArrCurrentDish[i].SetType((*dish).GetType());
			ArrCurrentDish[i].SetCost((*dish).GetCost());
			ArrCurrentDish[i].SetSize((*dish).GetSize());
			break;
		}
	}
	
}

void ClaeanCurrentDish() {
	for (int i = 0; i < N / 4; i++)
	{
		if (ArrCurrentDish[i].GetName() != NULL)
		{
			ArrCurrentDish[i].SetName(NULL);
			ArrCurrentDish[i].SetType(NULL);
			ArrCurrentDish[i].SetCost(0);
			ArrCurrentDish[i].SetSize(0);
		}
	}
	
}
#pragma endregion

#pragma region TypedClasses
void TypedClasses::ChangeType() { Type = nullptr; }

void TypedClasses::SetType(char* NewType) { Type = NewType; }
#pragma endregion

#pragma region Deliver
Deliver::Deliver(char* type)
{
	Type = type;
	if (strcmp(Type, "self") == 0)
		Cost = 0;
	else
		Cost = 150;
}

void Deliver::SetType(char* NewType) {
	strcpy(Type, NewType);
}

// поменять тип достаки
void Deliver::ChangeType() {
	char* DeliverType = new char[20];
	if (strcmp(Type, "self") == 0) {
		strcpy(DeliverType, "company");
		Cost = 150;
	}
	else {
		strcpy(DeliverType, "self");
		Cost = 0;
	}
	SetType(DeliverType);
	delete[] DeliverType;
}

// вывод типа доставки
void Deliver::ShowType(char** ArrFrases) {
	int W = 51;
	if (strcmp(Type, "self") == 0)
		cout << "\t" << setw(W) << ArrFrases[FirstTypeDeliver] << "\n";
	else {
		int time = 0;
			time = 20 + getRand(1, 10);

		ostringstream oss;
		oss.str("");
		oss << ArrFrases[OrderArived];
		oss << time;
		switch (time % 10)
		{
		case 1:
			oss << ArrFrases[FormMinute1];
			break;
		case  2: case 3: case 4:
			oss << ArrFrases[FormMinute2];
			break;
		default:
			oss << ArrFrases[FormMinute3];
			break;
		}
		cout << "\t" << setw(W) << ArrFrases[SecondTypeDeliver] << "\n"
			<< "\t" << setw(W) << oss.str().c_str()  << "\n";
	}
}

#pragma endregion

#pragma region Pay
Pay::Pay(char* type)
{
	Type = type;
}

void Pay::SetType(char* NewType) {
	strcpy(Type, NewType);
}

// поменять тип оплаты
void Pay::ChangeType() {
	char* PayType = new char[20];

	if (strcmp(Type, "cash") == 0)
		strcpy(PayType, "card");
	else
		strcpy(PayType, "cash");

	SetType(PayType);
	delete[] PayType;
}

// вывод типа оплаты
void Pay::ShowType(char** ArrFrases) {
	int W = 51;
	if (strcmp(Type, "cash") == 0)
		cout << "\t" << setw(W) << ArrFrases[FirstPay] << "\n";
	else
		cout << "\t" << setw(W) << ArrFrases[SecondPay] << "\n";
}

#pragma endregion

#pragma region Stock
Stock::Stock()
{
	NamesDishStock = vector <string> (4);
	Value = 120;
}

// установить размер скидки
void Stock::SetStockValue(int NewValue) {
	Value = NewValue;
}

// взять размер скидки
int Stock::GetStockValue() {
	return Value;
}

// заполнение массива скидок
void Stock::FillStock(char** ArrFrases) {
	NamesDishStock[0] = ArrFrases[Dish1 + getRand(0, 4)];
	NamesDishStock[1] = ArrFrases[Dish5 + getRand(0, 4)];
	NamesDishStock[2] = ArrFrases[Dish10 + getRand(0, 4)];
	NamesDishStock[3] = ArrFrases[Dish15 + getRand(0, 4)];
}

// выводим названия блюд со скидкой
void Stock::PrintDishOfStock(char** ArrFrases) {
	int valueOfStock = 0;
	cout << ArrFrases[StockIn] << Value << ArrFrases[ActiveOn];
	setColor(resColor);
	for (int i = 0; i < 4; i++)
	{
		cout << NamesDishStock[i] << ", ";
	}
	setColor(mainColor);
	cout << "\n\n";
}

#pragma endregion

#pragma region Offer
Offer::Offer()
{
	DishCount = 0;
}

void Offer::DeleteOffer() {
	if (OfferedDishes[0].GetName() != NULL)
	{
		for (int i = 0; i < DishCount; i++)
		{
			OfferedDishes[i].SetName(NULL);
			OfferedDishes[i].SetType(NULL);
			OfferedDishes[i].SetCost(0);
			OfferedDishes[i].SetSize(0);
		}
	}
	DishCount = 0;
}

// функция перегрузки операции вывода
ostream& operator<<(ostream& os, const Dish& CurrentDish) {
	os << setw(16) << CurrentDish.Name << "|" << setw(14)
		<< CurrentDish.Type << "|" << setw(12) << CurrentDish.Size << "|" << setw(13)
		<< CurrentDish.Cost << "| \n";
	return os;
}

// функция добавления блюда в заказ
void Offer::AddDish(int ChooseDish, char** ArrFrases) {
	if (DishCount >= 9)
		throw exception(ArrFrases[DishMaxOrder]);
	// копируем парамеры добовляемого блюда
	OfferedDishes[DishCount].SetName(ArrCurrentDish[ChooseDish - 1].GetName());
	OfferedDishes[DishCount].SetType(ArrCurrentDish[ChooseDish - 1].GetType());
	OfferedDishes[DishCount].SetCost(ArrCurrentDish[ChooseDish - 1].GetCost());
	OfferedDishes[DishCount].SetSize(ArrCurrentDish[ChooseDish - 1].GetSize());
	// увелисиваем количество блюд
	DishCount++;
}

// удаляем выбранное блюдо из заказа
void Offer::DeleteDish(int DishNumber) {
	// копируем последнее блюдо в удоляемое
	OfferedDishes[DishNumber - 1].SetName(OfferedDishes[DishCount - 1].GetName());
	OfferedDishes[DishNumber - 1].SetType(OfferedDishes[DishCount - 1].GetType());
	OfferedDishes[DishNumber - 1].SetCost(OfferedDishes[DishCount - 1].GetCost());
	OfferedDishes[DishNumber - 1].SetSize(OfferedDishes[DishCount - 1].GetSize());
	// удаляем последнее блюдо
	OfferedDishes[DishCount - 1].SetName(NULL);
	OfferedDishes[DishCount - 1].SetType(NULL);
	OfferedDishes[DishCount - 1].SetCost(0);
	OfferedDishes[DishCount - 1].SetSize(0);
	// уменьшаем количество блюд в заказе
	DishCount--;
}

int Offer::DishOffer(char** ArrFrases) {
	int i = 0;
	cout << "\t +---+----------------+--------------+------------+-------------+ \n"
		 << "\t " << ArrFrases[OfferTableRow] << " \n"
		 << "\t +---+----------------+--------------+------------+-------------+ \n";
	do {
		cout << "\t |" << setw(3) << i + 1 << "|" << OfferedDishes[i]; // выводим значения элемента
		++i;
	} while (i < DishCount);
	cout << "\t +---+----------------+--------------+------------+-------------+ \n";
	setColor(mainColor);
	cout << "\n\n" << ArrFrases[ForCountDish];
	setColor(resColor);
	cout << DishCount;
	setColor(mainColor);
	cout << "\n\n\n";
	return DishCount;
}

// функция получения итоговой стоимости заказа
int Offer::SumCost(float DeliverCost, vector <string> Stoks) {
	int SumCost = 0, resultCost(0);
	for (int i = 0; i < DishCount; i++)
	{
		resultCost = OfferedDishes[i].GetCost();
		if (Stoks[i] == OfferedDishes[i].GetName())
			resultCost -= 120;
		SumCost += resultCost;
	}
	SumCost += DeliverCost;
	return SumCost;
}

#pragma endregion
