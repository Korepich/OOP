#pragma once
#include <string>
#include <iostream>
#include "Persona.h"

using namespace std;


class Student : public Persona
{
private:
	int studentAcademicDebts;
	int studentCourse;
	static int count_;

public:
	Student();
	Student(int, int, string name,
		Gender gender, int age, string InstituteName, string FacultyName, string DepartmentName, PersonaType type);
	Student(const Student&);
	~Student();

	int getAcademicDebts();
	int getCourse();
	static int getStudentsCount();

	void setAcademicDebts(int);
	void setCourse(int);

	void ShowPersonaData();

	void writeToFile(ofstream* file);

};

