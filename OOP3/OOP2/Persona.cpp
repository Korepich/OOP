#include "Persona.h";
#include <string>

using namespace std;

int Persona::count_ = 0;
int Persona::currentId = 0;

void Persona::convertGenderView(Gender type)
{
	switch (type)
	{
	case male:
		cout << "Мужской" << endl;
		break;

	case female:
		cout << "Женский" << endl;
		break;

	case other:
		cout << "Другой" << endl;
		break;

	case attackHelicopter:
		cout << "Боевой ветролет" << endl;
		break;

	case commandant:
		cout << "Комендант" << endl;
		break;
	default:
		cout << "Неопределённый" << endl;
		break;
		cout << "\n";
	};
}

Persona::Persona()
{
	count_++;
}

Persona::Persona(string name, Gender gender, int age, string InstituteName, string FacultyName, string DepartmentName, PersonaType personaType)
{
	currentId++;
	count_++;
	personaName = name;
	personaGender = gender;
	personaAge = age;
	instituteName = InstituteName;
	facultyName = FacultyName;
	departmentName = DepartmentName;
	this->personaType = personaType;
	personaId = currentId;
}
// Используемый конструктор
Persona::Persona(PersonaType type)
{
	count_++;
	currentId++;
	personaId = currentId;
	personaType = type;
	cout << "Введите имя: ";
	cin.ignore();
	getline(cin, personaName);
	// Обработка гендера - НАЧАЛО
	cout << "Введите гендер из списка: \n";
	for (int i = 0; i < Gender::endOfEnum - 1; i++) {
		cout << i + 1 << ")";
		convertGenderView((Gender)(i+1));
	}
	int gender;
	cin >> gender;
	personaGender = (Gender)gender;
	// Обработка гендера - КОНЕЦ
	cout << "Введите возраст: ";
	cin >> personaAge;
	cin.ignore();
	cout << "Введите название института: ";
	getline(cin, instituteName);
	cout << "Введите название факультета: ";
	getline(cin, facultyName);
	cout << "Введите название кафедры: ";
	getline(cin, departmentName);
}

Persona::Persona(const Persona& persona)
{
	count_++;
	personaName = persona.personaName;
	personaGender = persona.personaGender;
	personaAge = persona.personaAge;
	instituteName = persona.instituteName;
	facultyName = persona.facultyName;
	departmentName = persona.departmentName;

}

Persona::~Persona()
{
	cout << "" << endl;
	count_--;
}
// Геттеры
string Persona::getName()
{
	return personaName;
}

Gender Persona::getGender()
{
	return personaGender;
}

int Persona::getAge()
{
	return personaAge;
}

string Persona::getInstituteName()
{
	return instituteName;
}

string Persona::getFacultyName()
{
	return facultyName;
}

string Persona::getDepartmentName()
{
	return departmentName;
}

int Persona::getPersonaCount()
{
	return count_;
}

int Persona::getPersonaId()
{
	return personaId;
}

PersonaType Persona::getPersonaType(PersonaType)
{
	return personaType;
}

void Persona::setName(string name)
{
	personaName = name;
}
// Сеттеры
void Persona::setGender(Gender gender)
{
	personaGender = gender;
}

void Persona::setAge(int age)
{
	personaAge = age;
}

void Persona::setInstituteName(string name)
{
	instituteName = name;
}

void Persona::setFacultyName(string name)
{
	facultyName = name;
}

void Persona::setDepartmentName(string name)
{
	departmentName = name;
}

void Persona::setPersonaType(PersonaType type)
{
	personaType = type;
}
// Принтер
void Persona::ShowPersonaData()
{
	cout << "\n\n";
	cout << "ID: " << personaId << endl;
	cout << "Имя: " << personaName << endl;
	cout << "Возраст: " << personaAge << endl;
	cout << "Институт: " << instituteName << endl;
	cout << "Факультет: " << facultyName << endl;
	cout << "Кафедра: " << departmentName << endl;
	cout << "Гендер: ";
	convertGenderView(personaGender);
}
// Запись в файл
void Persona::writeToFile(ofstream* file)
{
	if (!file->is_open()) {
		std::cout << "Ошибка! Файл не может быть открыт!\n";
	} else {
		int personaNameSize = personaName.length() + 1;
		int facultyNameSize = facultyName.length() + 1;
		int instituteNameSize = instituteName.length() + 1;
		int departmentNameSize = departmentName.length() + 1;
		personaName.append("\0");
		instituteName.append("\0");
		facultyName.append("\0");
		departmentName.append("\0");
		//Записываем тип класса для считывания и создания класса
		file->write(reinterpret_cast<char*>(&personaType), sizeof(personaType));
		//Записываем имя персоны
		file->write(reinterpret_cast<char*>(&personaNameSize), sizeof(personaNameSize));
		file->write(personaName.data(), personaNameSize);
		//Записываем гендер персоны
		file->write(reinterpret_cast<char*>(&personaGender), sizeof(personaGender));
		//Записываем возраст персоны
		file->write(reinterpret_cast<char*>(&personaAge), sizeof(personaAge));
		//Записываем институт персоны
		file->write(reinterpret_cast<char*>(&instituteNameSize), sizeof(instituteNameSize));
		file->write(instituteName.data(), instituteNameSize);
		//Записываем факультет персоны
		file->write(reinterpret_cast<char*>(&facultyNameSize), sizeof(facultyNameSize));
		file->write(facultyName.data(), facultyNameSize);
		//Записываем кафедру персоны
		file->write(reinterpret_cast<char*>(&departmentNameSize), sizeof(departmentNameSize));
		file->write(departmentName.data(), departmentNameSize);

		std::cout << "Файл записан\n";
	}

}



