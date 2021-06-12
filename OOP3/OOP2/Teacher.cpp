#include "Teacher.h"

using namespace std;

int Teacher::count_ = 0;

Teacher::Teacher() : Persona(Teacher_)
{
	cout << "Введите учёную степень: ";
	getline(cin, teacherAcademicDegree);
	cout << "Введите учёное звание: ";
	getline(cin, teacherAcademicTitle);
	count_++;
}

Teacher::Teacher(string academicDegree, string academicTitle, 
	string name, Gender gender, int age, string InstituteName, 
	string FacultyName, string DepartmentName, PersonaType type) :
	Persona(name, gender, age, InstituteName, FacultyName, DepartmentName, type)
{
	teacherAcademicDegree = academicDegree;
	teacherAcademicTitle = academicTitle;
	count_++;	
}

Teacher::Teacher(const Teacher& teacher)
{
	teacherAcademicDegree = teacher.teacherAcademicDegree;
	teacherAcademicTitle = teacher.teacherAcademicTitle;
	count_++;
}

Teacher::~Teacher()
{
	cout << "" << endl;
	count_--;
}

string Teacher::getAcademicDegree()
{
	return teacherAcademicDegree;
}

string Teacher::getAcademicTitle()
{
	return teacherAcademicTitle;
}

int Teacher::getTeacherCount()
{
	return count_;
}
 
void Teacher::setAcademicDegree(string academicDegree)
{
	teacherAcademicDegree = academicDegree;
}

void Teacher::setAcademicTitle(string academicTitle)
{
	teacherAcademicTitle = academicTitle;
}

void Teacher::ShowPersonaData()
{
	Persona::ShowPersonaData();
	std::cout << "Ученая степень: " <<teacherAcademicDegree <<endl;
	std::cout << "Ученое звание: " <<teacherAcademicTitle <<endl;

}

void Teacher::writeToFile(ofstream* file)
{
	Persona::writeToFile(file);
	if (!file->is_open()) {
		std::cout << "Ошибка! Файл не может быть открыт!\n";
	}
	else {
		int teacherDegreeSize = teacherAcademicDegree.length() + 1;
		int teacherTitleSize = teacherAcademicTitle.length() + 1;
		teacherAcademicDegree.append("\0");
		teacherAcademicTitle.append("\0");
		//Записываем учёную степень
		file->write(reinterpret_cast<char*>(&teacherDegreeSize), sizeof(teacherDegreeSize));
		file->write(teacherAcademicDegree.data(), teacherDegreeSize);
		//Записываем звание
		file->write(reinterpret_cast<char*>(&teacherTitleSize), sizeof(teacherTitleSize));
		file->write(teacherAcademicTitle.data(), teacherTitleSize);
		std::cout << "Файл записан\n";
	}
}

