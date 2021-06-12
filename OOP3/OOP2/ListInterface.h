#pragma once
#include <typeinfo>
#include <iostream>
#include <fstream>
#include <string>
#include <Windows.h>
#include <conio.h>

#include "PersonaList.h"

class ListInterface {
public:
	void drawInterface();
	~ListInterface();
private:
	PersonaList list;
	void doAction(int choice);
	void processCountryChoice(int choice);
	void drawAddingElement();
	void deleteElementById();
	void drawShowingElementsByClassName();
	void clearscr();
	std::ofstream* dataFile = new std::ofstream;
};

