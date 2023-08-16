#include "Colors.h"
#include "Palette.h"
#include "pch.h"
#include "Utils.h"
#include "Classes.h"
#include "Functions.h"

// функция второй возможности программы "вывод меню"
void ShowMenuTask(char** ArrFrases, Menu CurrentMenu, Offer* UserOffer);

// функция смены меню
void ChangeMenuTask(char** ArrFrases, Menu* CurrentMenu);

// вывод заказа
void ShowOrder(char** ArrFrases, Offer* UserOffer, Deliver* CurrentDeliver, Pay* CurrentPay, Stock CurrentStock);

// подтверждение заказа
void EndedTask(char** ArrFrases, Offer* UserOffer, Deliver* CurrentDeliver, Pay* CurrentPay, Stock CurrentStock);

// вывод информации о авторе
void ShowAboutInfo(char** ArrFrases);

// вывод титульной страницы
void ShowTitulka(char** ArrFrases);

// вывод описания предметной области
void FunctionShowObjectArea(char** ArrFrases);

int main()
{
	// подготовка приложения
	init();

	// ширина вывод окна финишного сообщения
	const int W = 83;

	// код нажатой клавиши
	int key;
	bool flag = true;
	
	char* DeliverType = new char[20];
	strcpy(DeliverType, "self");

	char* PayType = new char[20];
	strcpy(PayType, "cash");

	// создание массива фраз выбранного языка
	int CountRow(110), CountLetterInRow(1024);
	char** ArrFrases = create(CountRow, CountLetterInRow);

	// создание объектов
	Menu CurrentMenu;
	Stock CurrentStocks;
	Offer UserOffer;
	Deliver UserDeliver(DeliverType);
	Pay UserPay(PayType);

	
	// главный цикл приложения
	while (true) {
		setColor(mainColor);
		Cls();

		if (flag) {
			ChangeLang(&ArrFrases, CountRow, CountLetterInRow);
			CurrentStocks.FillStock(ArrFrases);
			fillDishes(ArrFrases);
			ShowTitulka(ArrFrases);
			flag = false;
			Cls();
		}

		// выводим информацию о решаемых задачвх
		setColor(infoColor);
		cout << "\n\n\n\n" << left
			<< "\t" << setw(W) << " " << "\n"
			<< "\t" << setw(W) << ArrFrases[firstTask] << "\n"
			<< "\t" << setw(W) << ArrFrases[printMenuTask] << "\n"
			<< "\t" << setw(W) << ArrFrases[changeMenuTask] << "\n"
			<< "\t" << setw(W) << ArrFrases[ShowUserOffer] << "\n"
			<< "\t" << setw(W) << ArrFrases[ShowStockDishes] << "\n"
			<< "\t" << setw(W) << ArrFrases[ShowInfo] << "\n"
			<< "\t" << setw(W) << ArrFrases[ShowTitul] << "\n"
			<< "\t" << setw(W) << ArrFrases[ShowObjectArea] << "\n"
			<< "\t" << setw(W) << ArrFrases[footerTask] << "\n"
			<< "\t" << setw(W) << ArrFrases[endTask] << "\n"
			<< "\t" << setw(W) << " " << "\n" << right;
		setColor(mainColor);
		cout << "\n\n\n\t";

		// получить код клавиши и обработать ее
		key = getKey(ArrFrases[pressKey]);
		Cls();

		// выход из приложения
		if (key == K_F10 || key == VK_ESCAPE) {
			break;
		} // if

		try{
			// команды вызова функций по заданию
			switch (key) {
			case '1':
				ChangeLang(&ArrFrases, CountRow, CountLetterInRow);
				CurrentMenu.SetType(nullptr);
				CurrentMenu.DishCount = 0;
				CurrentStocks.FillStock(ArrFrases);
				UserOffer.DeleteOffer();
				fillDishes(ArrFrases);
				break;
			case '2':
				if (CurrentMenu.GetType() == nullptr)
					throw exception(ArrFrases[MenuDoesntChoose]);
				ShowMenuTask(ArrFrases, CurrentMenu, &UserOffer);
				break;
			case '3':
				ChangeMenuTask(ArrFrases, &CurrentMenu);
				break;
			case '4':
				if (CurrentMenu.GetType() == nullptr)
					throw exception(ArrFrases[DontOfferedDish]);
				ShowOrder(ArrFrases, &UserOffer, &UserDeliver, &UserPay, CurrentStocks);
				break;
			case '5':
				CurrentStocks.PrintDishOfStock(ArrFrases);
				break;
			case '6':
				ShowAboutInfo(ArrFrases);
				break;
			case '7':
				ShowTitulka(ArrFrases);
				break;
			case '8':
				FunctionShowObjectArea(ArrFrases);
				break;


			default:
				Cls();
				setColor(errColor);
				cout << "\n\n\n\n" << left
					<< "\t" << setw(W) << " " << "\n"
					<< "\t" << setw(W) << ArrFrases[firstError] << "\n"
					<< "\t" << setw(W) << ArrFrases[SecondError] << "\n"
					<< "\t" << setw(W) << " " << "\n"
					<< "\t" << setw(W) << " " << "\n" << right;
				setColor(mainColor);
				cout << "\n\n\n\n\n\n\n\n\n\n\n\n";
			} // switch
		}
		catch (exception& ex) {
			// вывод сообщения о ошибке
			MessageBeep(MB_ICONERROR);
			setColor(errColor);
			cout << "\n\n" << left
				<< "\t" << setw(W) << " " << "\n"
				<< "\t" << setw(W) << ArrFrases[firstError] << "\n"
				<< "\t" << "    " << setw(W - 4) << ex.what() << "\n"
				<< "\t" << setw(W) << " " << "\n"
				<< right;
			setColor(mainColor);
			cout << "\n\n\n";
		}
		// Ожидание нажатия любой клавиши после вывода результатов
		setColor(mainColor);
		cout << "\n\n";
		getKey(ArrFrases[pressKey]);
	} // while

	// финальное сообщение
	Cls();
	setColor(infoColor);
	cout << "\n\n\n"
		<< "\t                                           \n"
		<< "\t" << ArrFrases[GoodBye] << "\n"
		<< "\t                                           ";
	setColor(mainColor);
	cout << "\n\n\n";

	// освобождение динамической памяти
	delete[] DeliverType;
	delete[] PayType;
	destroy(ArrFrases, CountRow);

	return 0;
}



#pragma region Вспомогательные_функции
// функция смены меню
void ChangeMenuTask(char** ArrFrases, Menu* CurrentMenu) {
	// переменная ширины вывода
	const int W = 83;
	// переменная выбранного меню
	int chooseMenu = 0;
	do
	{
		// очистка экрана
		Cls();
		// вывод вариантов меню
		setColor(infoColor);
		cout << "\n\n\n\n" << left
			<< "\t" << setw(W) << " " << "\n"
			<< "\t" << setw(W) << ArrFrases[HotMenu] << "\n"
			<< "\t" << setw(W) << ArrFrases[PizzaMenu] << "\n"
			<< "\t" << setw(W) << ArrFrases[SaltMenu] << "\n"
			<< "\t" << setw(W) << ArrFrases[DrinkMenu] << "\n"
			<< "\t" << setw(W) << ArrFrases[footerTask] << "\n"
			<< "\t" << setw(W) << ArrFrases[BackTask] << "\n"
			<< "\t" << setw(W) << " " << "\n" << right;
		setColor(mainColor);
		cout << "\n\n\n\t";

		// получить код клавиши и обработать ее
		chooseMenu = getKey(ArrFrases[pressKey]);
		// если ввод правильный выходим из цикла
		if (chooseMenu >= '1' && chooseMenu <= '4') break;

		// кнопки возвращения назад
		if (chooseMenu == K_F10 || chooseMenu == VK_ESCAPE) return;

		// вывод ошибки
		setColor(errColor);
		cout << "\n\n\n\n" << left
			<< "\t" << setw(W) << " " << "\n"
			<< "\t" << setw(W) << ArrFrases[firstError] << "\n"
			<< "\t" << setw(W) << ArrFrases[SecondError] << "\n"
			<< "\t" << setw(W) << " " << "\n"
			<< "\t" << setw(W) << " " << "\n" << right;
		setColor(mainColor);
		Sleep(1500);

	} while (true);
	// функция смены меню
	ChangeCurrentMenu(CurrentMenu, chooseMenu, ArrFrases);
}

// функция второй возможности программы "вывод меню"
void ShowMenuTask(char** ArrFrases, Menu CurrentMenu, Offer* UserOffer) {
	// переменная ширины вывода
	const int W = 51;
	// переменная выбранного блюда
	int chooseDish = 0;
	do
	{
		// очистка экрана
		Cls();

		// вывод выбранного меню
		CurrentMenu.ShowMenu(ArrFrases);
		setColor(infoColor);
		cout << left 
			<< "\t" << setw(W) << ArrFrases[BackTask] << "\n"
			<< "\t" << setw(W) << " " << "\n" << right;
		setColor(mainColor);
		cout << "\n\n\n\t";

		// получить код клавиши и обработать ее
		chooseDish = getKey(ArrFrases[СhooseDishKey]);
		// если ввод правильный выходим из цикла
		if (chooseDish >= '1' && chooseDish <= '5') break;

		// кнопки возвращения назад
		if (chooseDish == K_F10 || chooseDish == VK_ESCAPE) return;

		setColor(errColor);
		cout << "\n\n\n\n" << left
			<< "\t" << setw(W) << " " << "\n"
			<< "\t" << setw(W) << ArrFrases[firstError] << "\n"
			<< "\t" << setw(W) << ArrFrases[SecondError] << "\n"
			<< "\t" << setw(W) << " " << "\n"
			<< "\t" << setw(W) << " " << "\n" << right;
		setColor(mainColor);
		Sleep(1500);

	} while (true);
	UserOffer->AddDish((chooseDish - '0'), ArrFrases);
}

// сохрание информации в файл
void FillEndFile(char** ArrFrases, Offer* UserOffer, Deliver* CurrentDeliver, Stock CurrentStock) {
	int W = 83;
	char* Path = new char[1024];
	const char* FileName = "output.txt";
	FILE* f;
	ostringstream oss;
	do {
		Cls();
		// запрос на ввод пути для файла
		setColor(resColor);
		cout << "\n\n" << "Введите путь: ";
		setColor(mainColor);
		cin.ignore(cin.rdbuf()->in_avail(), '\n');
		cin.getline(Path, 1024);

		// объединяем 2 строки
		strcat(Path, FileName);

		// открываем файл для записи
		f = fopen(Path, "w");

		// если путь был не правильный(т.е. Файл не может открыться)
		// то сообщаем об ошибке и запрашиваем ввод снова
		if (!f) {

			setColor(errColor);
			cout << "\n\n\n\n" << left
				<< "\t" << setw(W) << " " << "\n"
				<< "\t" << setw(W) << ArrFrases[WrongPath] << "\n"
				<< "\t" << setw(W) << ArrFrases[SecondError] << "\n"
				<< "\t" << setw(W) << " " << "\n"
				<< "\t" << setw(W) << " " << "\n" << right;
			setColor(mainColor);
			Sleep(1500);
			continue;
		}
		break;
	} while (true);

	// запись в файл сколько блюд заказали и на какую сумму
	oss.str("");
	oss << ArrFrases[ForCountDish] << UserOffer->DishCount << "\n";
	fputs(oss.str().c_str(), f);
	oss.str("");
	oss << ArrFrases[SumCostDish]
		<< UserOffer->SumCost(CurrentDeliver->Cost, CurrentStock.NamesDishStock) << "\n";
	fputs(oss.str().c_str(), f);

	// закрыть файл
	fclose(f);

	// освободить занятую память
	delete[] Path;
}

// подтверждение заказа
void EndedTask(char** ArrFrases, Offer* UserOffer, Deliver* CurrentDeliver, Pay* CurrentPay, Stock CurrentStock) {
	int W = 51;
	int chooseAnswer = 0;
	ostringstream oss;
	do
	{
		// очистка экрана
		Cls();

		// вывод сообщения
		UserOffer->DishOffer(ArrFrases);
		setColor(infoColor);
		cout << left;
		CurrentPay->ShowType(ArrFrases);
		CurrentDeliver->ShowType(ArrFrases);
		
		oss << ArrFrases[SumCostDish]
			<< UserOffer->SumCost(CurrentDeliver->Cost, CurrentStock.NamesDishStock);

		cout << "\t" << setw(W) << oss.str().c_str() << "\n"
			 << "\t" << setw(W) << ArrFrases[AcceptOrder] << "\n"
			 << "\t" << setw(W) << ArrFrases[BackTask] << "\n"
			 << "\t" << setw(W) << " " << "\n" << right;
		setColor(mainColor);
		cout << "\n\n\n\t";

		// получить код клавиши и обработать ее
		chooseAnswer = getKey(ArrFrases[СhooseDishOrCommandKey]);
		// если ввод правильный выходим из цикла
		if (chooseAnswer == 'y') break;


		// кнопки возвращения назад
		if (chooseAnswer == 'n' || chooseAnswer == VK_ESCAPE) return;

		setColor(errColor);
		cout << "\n\n\n\n" << left
			<< "\t" << setw(W) << " " << "\n"
			<< "\t" << setw(W) << ArrFrases[firstError] << "\n"
			<< "\t" << setw(W) << ArrFrases[SecondError] << "\n"
			<< "\t" << setw(W) << " " << "\n"
			<< "\t" << setw(W) << " " << "\n" << right;
		setColor(mainColor);
		Sleep(1500);

	} while (true);
	Cls();
	setColor(infoColor);
	cout << "\n\n\n"
		<< "\t                                           \n"
		<< "\t" << ArrFrases[ThxForOrder] << "\n"
		<< "\t                                           ";
	setColor(mainColor);
	cout << "\n\n\n";
	Sleep(2000);
	// сохрание информации в файл
	FillEndFile(ArrFrases, UserOffer, CurrentDeliver, CurrentStock);
	exit(0);
}

// вывод заказа
void ShowOrder(char** ArrFrases, Offer* UserOffer, Deliver* CurrentDeliver, Pay* CurrentPay, Stock CurrentStock) {
	// переменная ширины вывода
	const int W = 51;
	// переменная выбранного блюда
	int chooseCommand = 0;
	do
	{
		// очистка экрана
		Cls();

		// вывод выбранных блюд
		UserOffer->DishOffer(ArrFrases);
		setColor(infoColor);
		cout << left;
		CurrentPay->ShowType(ArrFrases);
		CurrentDeliver->ShowType(ArrFrases);
		cout << "\t" << setw(W) << ArrFrases[footerTask] << "\n"
			 << "\t" << setw(W) << ArrFrases[CommandP] << "\n"
			 << "\t" << setw(W) << ArrFrases[CommandD] << "\n"
			 << "\t" << setw(W) << ArrFrases[CommandO] << "\n"
			 << "\t" << setw(W) << ArrFrases[BackTask] << "\n"
			 << "\t" << setw(W) << " " << "\n" << right;
		setColor(mainColor);
		cout << "\n\n\n\t";

		// получить код клавиши и обработать ее
		chooseCommand = getKey(ArrFrases[СhooseDishOrCommandKey]);
		// если ввод правильный выходим из цикла
		if (chooseCommand >= '1' && chooseCommand <= ('0' + UserOffer->DishCount)) {
			UserOffer->DeleteDish((chooseCommand - '0'));
			break;
		}
		// кнопки возвращения назад
		if (chooseCommand == K_F10 || chooseCommand == VK_ESCAPE) return;
		
		if (chooseCommand == 'p' || chooseCommand == 'd' || chooseCommand == 'o') {
			switch (chooseCommand)
			{
			case 'p':
				CurrentPay->ChangeType();
				break;
			case 'd':
				CurrentDeliver->ChangeType();
				break;
			case 'o':
				EndedTask(ArrFrases, UserOffer, CurrentDeliver, CurrentPay, CurrentStock);
				break;
			}
			continue;
		}
		

		setColor(errColor);
		cout << "\n\n\n\n" << left
			<< "\t" << setw(W) << " " << "\n"
			<< "\t" << setw(W) << ArrFrases[firstError] << "\n"
			<< "\t" << setw(W) << ArrFrases[SecondError] << "\n"
			<< "\t" << setw(W) << " " << "\n"
			<< "\t" << setw(W) << " " << "\n" << right;
		setColor(mainColor);
		Sleep(1500);

	} while (true);
	
}

// вывод информации о авторе
void ShowAboutInfo(char** ArrFrases) {
	int W = 51;
	setColor(infoColor);
	cout << "\n\n\n" << left
		<< "\t" << setw(W) << " " << "\n"
		<< "\t" << setw(W) << ArrFrases[AboutMe1] << "\n"
		<< "\t" << setw(W) << ArrFrases[AboutMe2] << "\n"
		<< "\t" << setw(W) << " " << "\n"
		<< "\t" << setw(W) << " " << "\n" << right;
	setColor(mainColor);
}

// вывод титульной страницы
void ShowTitulka(char** ArrFrases) {
	cout << '+' << setw(117) << setfill('-') << '+' << "\n"
		 << setfill(' ') 
		 << '|' << setw(77) << ArrFrases[TitMinobr] << setw(40) << '|' << "\n"
		 << '|' << setw(81) << ArrFrases[TitDonNTU] << setw(36) << '|' << "\n"
		 << '|' << setw(116) << " " << '|' << "\n"
		 << '|' << setw(116) << " " << '|' << "\n"
		 << '|' << setw(116) << " " << '|' << "\n"
		 << '|' << setw(116) << ArrFrases[TitFakul] << '|' << "\n"
		 << '|' << setw(116) << ArrFrases[TitCaf] << '|' << "\n"
		 << '|' << setw(116) << " " << '|' << "\n"
		 << '|' << setw(116) << " " << '|' << "\n"
		 << '|' << setw(116) << " " << '|' << "\n"
		 << '|' << setw(66) << ArrFrases[TitKursProj] << setw(51) << '|' << "\n"
		 << '|' << setw(89) << ArrFrases[TitDiscip] << setw(28) << '|' << "\n"
		 << '|' << setw(90) << ArrFrases[TitTema] << setw(27) << '|' << "\n"
		 << '|' << setw(116) << " " << '|' << "\n"
		 << '|' << setw(116) << " " << '|' << "\n"
		 << '|' << setw(116) << " " << '|' << "\n"
		 << '|' << setw(116) << " " << '|' << "\n"
		 << '|' << ArrFrases[TitCheck] << setw(116 - strlen(ArrFrases[TitCheck])) << ArrFrases[TitDo] << '|' << "\n"
		 << '|' << ArrFrases[TitPrep] << setw(116 - strlen(ArrFrases[TitPrep])) << ArrFrases[TitStud] << '|' << "\n"
		 << '|' << ArrFrases[TitMorozova] << setw(116 - strlen(ArrFrases[TitMorozova])) << ArrFrases[TitMe] << '|' << "\n"
		 << '|' << setw(116) << " " << '|' << "\n"
		 << '|' << setw(116) << " " << '|' << "\n"
		 << '|' << setw(116) << " " << '|' << "\n"
		 << '|' << setw(66) << ArrFrases[TitDonetsk] << setw(51) << '|' << "\n"
		 << '+' << setw(117) << setfill('-') << '+' << "\n" << setfill(' ');
	getKey(ArrFrases[pressKey]);
}

// вывод описания предметной области
void FunctionShowObjectArea(char** ArrFrases) {
	int W = 95;
	setColor(infoColor);
	cout << "\n\n\n" << left
		<< "\t" << setw(W) << " " << "\n"
		<< "\t" << setw(W) << ArrFrases[ObjectAreaRow1] << "\n"
		<< "\t" << setw(W) << ArrFrases[ObjectAreaRow2] << "\n"
		<< "\t" << setw(W) << ArrFrases[ObjectAreaRow3] << "\n"
		<< "\t" << setw(W) << ArrFrases[ObjectAreaRow4] << "\n"
		<< "\t" << setw(W) << ArrFrases[ObjectAreaRow5] << "\n"
		<< "\t" << setw(W) << ArrFrases[ObjectAreaRow6] << "\n"
		<< "\t" << setw(W) << ArrFrases[ObjectAreaRow7] << "\n"
		<< "\t" << setw(W) << ArrFrases[ObjectAreaRow8] << "\n"
		<< "\t" << setw(W) << ArrFrases[ObjectAreaRow9] << "\n"
		<< "\t" << setw(W) << ArrFrases[ObjectAreaRow10] << "\n"
		<< "\t" << setw(W) << ArrFrases[ObjectAreaRow11] << "\n"
		<< "\t" << setw(W) << ArrFrases[ObjectAreaRow12] << "\n"
		<< "\t" << setw(W) << ArrFrases[ObjectAreaRow13] << "\n"
		<< "\t" << setw(W) << ArrFrases[ObjectAreaRow14] << "\n"
		<< "\t" << setw(W) << ArrFrases[ObjectAreaRow15] << "\n"
		<< "\t" << setw(W) << ArrFrases[ObjectAreaRow16] << "\n"
		<< "\t" << setw(W) << ArrFrases[ObjectAreaRow17] << "\n"
		<< "\t" << setw(W) << ArrFrases[ObjectAreaRow18] << "\n"
		<< "\t" << setw(W) << ArrFrases[ObjectAreaRow19] << "\n"
		<< "\t" << setw(W) << ArrFrases[ObjectAreaRow20] << "\n"
		<< "\t" << setw(W) << ArrFrases[ObjectAreaRow21] << "\n"
		<< "\t" << setw(W) << ArrFrases[ObjectAreaRow22] << "\n"
		<< "\t" << setw(W) << ArrFrases[ObjectAreaRow23] << "\n"
		<< "\t" << setw(W) << " " << "\n"
		<< "\t" << setw(W) << " " << "\n" << right;
	setColor(mainColor);
}

#pragma endregion
