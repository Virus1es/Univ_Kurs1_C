#include "Colors.h"
#include "Palette.h"
#include "pch.h"
#include "Utils.h"
#include "Classes.h"
#include "Functions.h"

#pragma region ���������������_�������
void FillArrFras(char*** ArrFrases, const char* fileName, int CountRow, int CountLetterInRow) {
	// ������� ���������� ����� ����
	destroy(*ArrFrases, CountRow);
	// ������� ����� ������ ����
	*ArrFrases = create(CountRow, CountLetterInRow);

	ostringstream oss;
	// ��������� ���� ��� ������
	FILE* f = fopen(fileName, "r");
	if (!f) {
		if (strcmp(fileName, "text_ru.txt") == 0)
			oss << "������! �� ���� ������� ���� " << fileName << " ��� ������";
		else
			oss << "Error! Can't open the file " << fileName << " for reading";
		throw exception(oss.str().c_str());
	}
	int i = 0;
	while (true)
	{
		// ������ ������ �� �����
		fgets((*ArrFrases)[i], 1024, f);

		// ������� ���� �������� ����� �����
		if (feof(f)) break;

		// ������� ��� ������ ������ � ����� ������ ����� ������
		if ((*ArrFrases)[i][strlen((*ArrFrases)[i]) - 1] == '\n') (*ArrFrases)[i][strlen((*ArrFrases)[i]) - 1] = 0;

		i++;
	}

	fclose(f);
}

// �������� ������� - ��������� ������
char** create(int CountRow, int CountLetterInRow)
{
	// ��������� �� ������� - ��������� �� ������ ���������� �� ������ �������
	char** frases = new char* [CountRow];

	// �������� ����� �������, ������ ������ ����� n
	// �� ����� ����� ����������� ����� (����� ��� ����� "������" ������)
	for (int i = 0; i < CountRow; i++)
		frases[i] = new char[CountLetterInRow];

	return frases;
}

// �������� ������� - ������������ ������
void destroy(char** frases, int CountRow) {
	// �������� ����� �������
	for (int i = 0; i < CountRow; i++)
		delete frases[i];  // ������� i-� ������ �������

	// �������� ������� ���������� �� ������ 
	delete[] frases;
}

#pragma endregion


// ������� ����� �����
void ChangeLang(char*** ArrFras, int CountRow, int CountLetterInRow) {

	while (true)
	{
		const int W = 83;
		const char* FileName;
		int lang = 0;
		// ����������� ������ �����
		cout << "\n\n\t";
		setColor(infoColor);
		cout << "Choose language(1 - �������, 2 - English)";
		setColor(mainColor);
		cout << "\n\n";
		// ������� ������� �������
		lang = getKey("   Press any key to continue...");
		Cls();

		//������������� ���������� ������� ����
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
					<< "\t" << setw(W) << "    ��� ����� ������� ����������" << "\n"
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
				<< "\t" << setw(W) << "    [������]" << "\n"
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


// ������� ��� ���������� ����
void fillMenu(Menu* CurrentMenu) {

	for (int i = 0; i < N; i++)
	{
		if (!strcmp(CurrentMenu->GetType(), ArrDish[i].GetType())) {
			
			(*CurrentMenu) < &ArrDish[i];
		}
	}
}

// ������� ����� ����
void ChangeCurrentMenu(Menu* CurrentMenu, int MenuCount, char** ArrFrases) {
	char* MenuType = new char[20];
	// ������ ��� ���� �� ������
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
	// ���������� ���� ������ ����������
	fillMenu(CurrentMenu);
	delete[] MenuType;
}


// ������� ��� ���������� ������������ ����
void fillDishes(char** ArrFrases) {

	// ��������
	int i = 0;
	while (true)
	{
		// ������� ���� �������� ����� �������
		if (i >= N) break;

		// ����������� ��� �����
		ArrDish[i].SetType(ArrFrases[TypeMenu1 + (i / 5)]);
		
		// ����������� �������� ����� 
		ArrDish[i].SetName(ArrFrases[Dish1 + i]);

		if (ArrDish[i].GetCost() <= 0) {
			// ����������� ��������� �����
			int cost = getRand(20, 40);
			cost *= 10;
			ArrDish[i].SetCost(cost);
		}
		
		if (ArrDish[i].GetSize() <= 0) {
			// ����������� ������ �����
			int size = getRand(15, 30);
			size *= 10;
			ArrDish[i].SetSize(size);
		}

		i++;
	}
	ClaeanCurrentDish();
}

