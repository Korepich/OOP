#include "HOD.h"

void HOD::setGroupCount(int groupCount)
{
	groupCount_ = groupCount;
}

void HOD::setStudentCount(int studentCount)
{
	studentCount_ = studentCount;
}

HOD::HOD() : Persona(HOD_)
{
	cout << "Введите количество групп: ";
	cin >> groupCount_;
	cout << "Введите количество судентов: ";
	cin >> studentCount_;
}

HOD::HOD(int groupCount, int studentCount, string name, 
		Gender gender, int age, string InstituteName, 
		string FacultyName, string DepartmentName, PersonaType type) : 
	Persona(name, gender, age, InstituteName, FacultyName, DepartmentName, type)
{
	groupCount_ = groupCount;
	studentCount_ = studentCount;
}

void HOD::ShowPersonaData()
{
	Persona::ShowPersonaData();
	cout << "Количество групп на кафедре: " << groupCount_;
	cout << "\nКоличество студентов на кафедре: " << studentCount_;
}

int HOD::getGroupCount()
{
	return groupCount_;
}

int HOD::getStudentCount()
{
	return studentCount_;
}

void HOD::writeToFile(ofstream* file)
{
	Persona::writeToFile(file);
	if (!file->is_open()) {
		std::cout << "Ошибка! Файл не может быть открыт!\n";
	} else {
		//Записываем количество групп
		file->write(reinterpret_cast<char*>(&groupCount_), sizeof(groupCount_));
		//Записываем количество студентов
		file->write(reinterpret_cast<char*>(&studentCount_), sizeof(studentCount_));
		std::cout << "Файл записан\n";
	}
}
