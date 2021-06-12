#include "ListInterface.h"

void ListInterface::drawInterface() {
	list.addObjectsFromFile();
	while (true) {
		clearscr();
		int choice = 0;
		std::cout << "=========================================\n";
		std::cout << "1) �������� �������\n";
		std::cout << "2) �������� ������ ���� ��������� ������\n";
		std::cout << "3) ������� ������� ������\n";
		std::cout << "4) ������� ��� �������� � ������\n";
		std::cout << "5) ������� ������ ��������� �� ���� ������\n";
		std::cout << "6) �����\n";
		std::cout << "�������� ��������: ";
		std::cin >> choice;
		if (std::cin.good()) {
			if (choice == 6) {
				if (!list.isEmpty()) {
					dataFile->open("data.txt", std::ios::binary | std::ios::trunc);
					list.writeToFile(dataFile);
					dataFile->close();
				}
				break;
			}
			this->doAction(choice);
		}
		else {
			std::cout << "\n������������ ������!\n ������� Enter, ����� ����������\n";
			std::cin.clear();
			std::cin.ignore();
			_getch();
		}
	}
}

void ListInterface::doAction(int choice) {
	clearscr();
	switch (choice)
	{
	case 1: this->drawAddingElement();
		break;
	case 2: list.showAllItems();
		break;
	case 3: this->deleteElementById();
		break;
	case 4: list.deleteAllItems();
		break;
	case 5: this->drawShowingElementsByClassName();
		break;
	default:
		std::cout << "��� ������ ��������!\n";
		break;
	}
	_getch();
}

void ListInterface::processCountryChoice(int choice) {
	clearscr();
	switch (choice)
	{
	case 1: list.addItem(new Student());
		break;
	case 2: list.addItem(new Teacher());
		break;
	case 3: list.addItem(new HOD());
		break;
	default:
		std::cout << "��� ������ �������!\n";
		break;
	}
}

void ListInterface::drawAddingElement() {
	int choice = 0;
	std::cout << "===== ��������� � ���������� �������� =====\n";
	std::cout << "1) Student\n";
	std::cout << "2) Teacher\n";
	std::cout << "3) HOD\n";
	std::cout << "������� ����� �������, ������� ������ �������: ";
	std::cin >> choice;
	if (std::cin.good()) {
		this->processCountryChoice(choice);
	}
	else {
		std::cout << "\n������������ ������!\n ������� Enter, ����� ����������\n";
		std::cin.clear();
		std::cin.ignore();
		_getch();
	}
}

void ListInterface::deleteElementById() {
	bool isConfirmed = false;
	list.showAllItems();
	int countryId = 0;
	std::cout << "������� ID �������, ����� ��� �������: ";
	std::cin >> countryId;
	if (std::cin.good()) {

		std::cin.clear();
		std::cin.ignore();

		std::cout << "�� �������������� ������ ������� ������?\n Yes = 1 / No = 0\n";
		std::cin >> isConfirmed;

		if (std::cin.good()) {
			if (isConfirmed) {
				list.deleteItem(countryId);
			}
			else {
				std::cout << "������ �� ��� �����!\n";
			}
		}
		else {
			std::cout << "\n������������ ������!\n ������� Enter, ����� ����������\n";
			std::cin.clear();
			std::cin.ignore();
			_getch();
		}
	}
	else {
		std::cout << "\n������������ ������!\n ������� Enter, ����� ����������\n";
		std::cin.clear();
		std::cin.ignore();
		_getch();
	}
}

void ListInterface::drawShowingElementsByClassName() {
	clearscr();
	int choice = 0;
	std::cout << "1) Student\n";
	std::cout << "2) Teacher\n";
	std::cout << "3) HOD\n";
	std::cout << "�������� ��� �����, �������� �������� ����� ��������: \n";
	std::cin >> choice;
	if (std::cin.good()) {
		switch (choice)
		{
		case 1: list.showItemsByClassName(typeid(Student));
			break;
		case 2: list.showItemsByClassName(typeid(Teacher));
			break;
		case 3: list.showItemsByClassName(typeid(HOD));
			break;
		default:
			std::cout << "��� ������ ������!\n";
			break;
		}
	}
	else {
		std::cout << "\n������������ ������!\n ������� Enter, ����� ����������\n";
		std::cin.clear();
		std::cin.ignore();
		_getch();
	}
}

void ListInterface::clearscr() {
	HANDLE hStdOut = GetStdHandle(STD_OUTPUT_HANDLE);
	COORD coord = { 0, 0 };
	DWORD count;

	CONSOLE_SCREEN_BUFFER_INFO csbi;
	GetConsoleScreenBufferInfo(hStdOut, &csbi);

	FillConsoleOutputCharacter(hStdOut, ' ', csbi.dwSize.X * csbi.dwSize.Y, coord, &count);

	SetConsoleCursorPosition(hStdOut, coord);
}

ListInterface::~ListInterface() {
	delete dataFile;
}
