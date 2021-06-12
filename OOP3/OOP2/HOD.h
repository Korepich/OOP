#pragma once
#include "Persona.h"


class HOD : public Persona
{
private:
	// Количество групп на кафедре
	int groupCount_;
	// Количество студентов на кафедре
	int studentCount_;
	void setGroupCount(int groupCount);
	void setStudentCount(int studentCount);

public:
	HOD();
	HOD(int groupCount, int studentCount, string name, Gender gender, int age, string InstituteName,
		string FacultyName, string DepartmentName, PersonaType type);
	void ShowPersonaData();
	int getGroupCount();
	int getStudentCount();
	void writeToFile(ofstream* file);
};

