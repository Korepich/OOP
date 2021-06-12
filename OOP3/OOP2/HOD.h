#pragma once
#include "Persona.h"


class HOD : public Persona
{
private:
	// ���������� ����� �� �������
	int groupCount_;
	// ���������� ��������� �� �������
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

