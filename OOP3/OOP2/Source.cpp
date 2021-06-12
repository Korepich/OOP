#include <iostream>
#include <locale>
#include "ListInterface.h"

using namespace std;

int main()
{
	setlocale(LC_ALL, "Russian");
	ListInterface listInterface;
	listInterface.drawInterface();
	return 0;
}