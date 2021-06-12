#pragma once
#include <string>
#include <iostream>
#include "Persona.h"

using namespace std;

class Teacher : public Persona
{
private:
	string teacherAcademicDegree;
	string teacherAcademicTitle;
	static int count_;
public:
	Teacher();
	Teacher(string, string, string name, Gender gender, int age, string InstituteName, 
			string FacultyName, string DepartmentName, PersonaType type);
	Teacher(const Teacher&);
	~Teacher();

	string getAcademicDegree();
	string getAcademicTitle();
	static int getTeacherCount();

	void setAcademicDegree(string);
	void setAcademicTitle(string);
	void ShowPersonaData();

	void writeToFile(ofstream* file);
};

