#include "Colors.h"
#include "Palette.h"
#include "pch.h"
#include "Utils.h"
#include "Classes.h"
#include "Functions.h"

#pragma region Вспомогательные_функции
void FillArrFras(char*** ArrFrases, const char* fileName, int CountRow, int CountLetterInRow) {
	// удаляем предыдущий набор фраз
	destroy(*ArrFrases, CountRow);
	// создаем новый массив фраз
	*ArrFrases = create(CountRow, CountLetterInRow);

	ostringstream oss;
	// открываем файл для чтения
	FILE* f = fopen(fileName, "r");
	if (!f) {
		if (strcmp(fileName, "text_ru.txt") == 0)
			oss << "Ошибка! не могу открыть файл " << fileName << " для чтения";
		else
			oss << "Error! Can't open the file " << fileName << " for reading";
		throw exception(oss.str().c_str());
	}
	int i = 0;
	while (true)
	{
		// читаем строки из файла
		fgets((*ArrFrases)[i], 1024, f);

		// выходим если достигли конца файла
		if (feof(f)) break;

		// удаляем для каждой строки в конце символ смены строки
		if ((*ArrFrases)[i][strlen((*ArrFrases)[i]) - 1] == '\n') (*ArrFrases)[i][strlen((*ArrFrases)[i]) - 1] = 0;

		i++;
	}

	fclose(f);
}

// создание матрицы - выделение памяти
char** create(int CountRow, int CountLetterInRow)
{
	// указатель на матрицу - указывает на массив указателей на строки матрицы
	char** frases = new char* [CountRow];

	// создание строк матрицы, каждая строка длины n
	// но может иметь собственную длину (тогда это будет "рваный" массив)
	for (int i = 0; i < CountRow; i++)
		frases[i] = new char[CountLetterInRow];

	return frases;
}

// удаление матрицы - освобождение памяти
void destroy(char** frases, int CountRow) {
	// удаление строк матрицы
	for (int i = 0; i < CountRow; i++)
		delete frases[i];  // удалить i-ю строку матрицы

	// удаление массива указателей на строки 
	delete[] frases;
}

#pragma endregion


// функция смены языка
void ChangeLang(char*** ArrFras, int CountRow, int CountLetterInRow) {

	while (true)
	{
		const int W = 83;
		const char* FileName;
		int lang = 0;
		// предложение выбора языка
		cout << "\n\n\t";
		setColor(infoColor);
		cout << "Choose language(1 - Русский, 2 - English)";
		setColor(mainColor);
		cout << "\n\n";
		// ожидаем нажатие клавиши
		lang = getKey("   Press any key to continue...");
		Cls();

		//переключатель заполнения массива фраз
		try {
			switch (lang)
			{
			case '1':
				FileName = "text_ru.txt";
				FillArrFras(ArrFras, FileName, CountRow, CountLetterInRow);
				break;
			case '2':
				FileName = "text_en.txt";
				FillArrFras(ArrFras, FileName, CountRow, CountLetterInRow);
				break;
			default:
				Cls();
				setColor(errColor);
				cout << "\n\n\n\n" << left
					<< "\t" << setw(W) << " " << "\n"
					<< "\t" << setw(W) << "    [Error]" << "\n"
					<< "\t" << setw(W) << "    Нет такой команды приложения" << "\n"
					<< "\t" << setw(W) << "    No such application command" << "\n"
					<< "\t" << setw(W) << " " << "\n"
					<< "\t" << setw(W) << " " << "\n" << right;
				setColor(mainColor);
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
				Sleep(2000);
				Cls();
				continue;
			}
		}
		catch (exception& ex) {
			MessageBeep(MB_ICONERROR);
			setColor(errColor);
			cout << "\n\n" << left
				<< "\t" << setw(W) << " " << "\n"
				<< "\t" << setw(W) << "    [Ошибка]" << "\n"
				<< "\t" << "    " << setw(W - 4) << ex.what() << "\n"
				<< "\t" << setw(W) << " " << "\n"
				<< right;
			setColor(mainColor);
			cout << "\n\n\n";
			exit(-1);
		}
		break;
	}
}


// функция для заполнения меню
void fillMenu(Menu* CurrentMenu) {

	for (int i = 0; i < N; i++)
	{
		if (!strcmp(CurrentMenu->GetType(), ArrDish[i].GetType())) {
			
			(*CurrentMenu) < &ArrDish[i];
		}
	}
}

// функция смены меню
void ChangeCurrentMenu(Menu* CurrentMenu, int MenuCount, char** ArrFrases) {
	char* MenuType = new char[20];
	// меняем тип меню на нужный
	switch (MenuCount)
	{
	case '1':
		strcpy(MenuType, ArrFrases[TypeMenu1]);
		break;
	case '2':
		strcpy(MenuType, ArrFrases[TypeMenu2]);
		break;
	case '3':
		strcpy(MenuType, ArrFrases[TypeMenu3]);
		break;
	case '4':
		strcpy(MenuType, ArrFrases[TypeMenu4]);
		break;
	}
	CurrentMenu->SetType(MenuType);
	ClaeanCurrentDish();
	// заполнение меню новыми значениями
	fillMenu(CurrentMenu);
	delete[] MenuType;
}


// функция для заполнения всевозможных блюд
void fillDishes(char** ArrFrases) {

	// итератор
	int i = 0;
	while (true)
	{
		// выходим если достигли конца массива
		if (i >= N) break;

		// присваиваем тип блюда
		ArrDish[i].SetType(ArrFrases[TypeMenu1 + (i / 5)]);
		
		// присваиваем название блюда 
		ArrDish[i].SetName(ArrFrases[Dish1 + i]);

		if (ArrDish[i].GetCost() <= 0) {
			// присваиваем стоимость блюду
			int cost = getRand(20, 40);
			cost *= 10;
			ArrDish[i].SetCost(cost);
		}
		
		if (ArrDish[i].GetSize() <= 0) {
			// присваиваем размер блюду
			int size = getRand(15, 30);
			size *= 10;
			ArrDish[i].SetSize(size);
		}

		i++;
	}
	ClaeanCurrentDish();
}

