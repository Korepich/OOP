#include "Student.h"

using namespace std;

int Student::count_ = 0;

Student::Student() : Persona(Student_)
{
	cout << "������� ���������� ������������� �������������� ��������: ";
	cin >> studentAcademicDebts;
	cout << "������� ���� ��������: ";
	cin >> studentCourse;
	count_++;
}

Student::Student(int academicDebts, int course, string name, 
				Gender gender, int age, string InstituteName, 
				string FacultyName, string DepartmentName, PersonaType type) 
				: Persona(name, gender, age, InstituteName, FacultyName, DepartmentName, type)
{
	studentAcademicDebts = academicDebts;
	studentCourse = course;
	count_++;
}

Student::Student(const Student& student)
{	
	count_++;
	studentAcademicDebts = student.studentAcademicDebts;
	studentCourse = student.studentCourse;
}

Student::~Student()
{
	cout << "" << endl;
	count_--;
}

int Student::getAcademicDebts()
{
	return studentAcademicDebts;
}

int Student::getCourse()
{
	return studentCourse;
}

int Student::getStudentsCount()
{
	return count_;
}

void Student::setAcademicDebts(int academicDebts)
{
	studentAcademicDebts = academicDebts;
}

void Student::setCourse(int course)
{
	studentCourse = course;
}

void Student::ShowPersonaData()
{
	Persona::ShowPersonaData();
	std::cout << "������������� �������������: " << studentAcademicDebts << endl;
	std::cout << "����: " << studentCourse << endl;
}

void Student::writeToFile(ofstream* file)
{
	Persona::writeToFile(file);
	if (!file->is_open()) {
		std::cout << "������! ���� �� ����� ���� ������!\n";
	}
	else {
		//���������� ���������� ������ ��������
		file->write(reinterpret_cast<char*>(&studentAcademicDebts), sizeof(studentAcademicDebts));
		//���������� ���� ��������
		file->write(reinterpret_cast<char*>(&studentCourse), sizeof(studentCourse));
		std::cout << "���� �������\n";
	}
}
