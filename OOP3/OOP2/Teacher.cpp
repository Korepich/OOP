#include "Teacher.h"

using namespace std;

int Teacher::count_ = 0;

Teacher::Teacher() : Persona(Teacher_)
{
	cout << "������� ������ �������: ";
	getline(cin, teacherAcademicDegree);
	cout << "������� ������ ������: ";
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
	std::cout << "������ �������: " <<teacherAcademicDegree <<endl;
	std::cout << "������ ������: " <<teacherAcademicTitle <<endl;

}

void Teacher::writeToFile(ofstream* file)
{
	Persona::writeToFile(file);
	if (!file->is_open()) {
		std::cout << "������! ���� �� ����� ���� ������!\n";
	}
	else {
		int teacherDegreeSize = teacherAcademicDegree.length() + 1;
		int teacherTitleSize = teacherAcademicTitle.length() + 1;
		teacherAcademicDegree.append("\0");
		teacherAcademicTitle.append("\0");
		//���������� ������ �������
		file->write(reinterpret_cast<char*>(&teacherDegreeSize), sizeof(teacherDegreeSize));
		file->write(teacherAcademicDegree.data(), teacherDegreeSize);
		//���������� ������
		file->write(reinterpret_cast<char*>(&teacherTitleSize), sizeof(teacherTitleSize));
		file->write(teacherAcademicTitle.data(), teacherTitleSize);
		std::cout << "���� �������\n";
	}
}

