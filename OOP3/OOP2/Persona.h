#pragma once
#include <iostream>
#include <fstream>
#include <cstdio>
#include <string>

using namespace std;

enum Gender { male = 1, female, other, attackHelicopter, commandant, endOfEnum};
enum PersonaType { Student_ = 0, Teacher_, HOD_ };

class Persona
{
private:
	string personaName;
	Gender personaGender;
	int personaAge;
	string instituteName;
	string facultyName;
	string departmentName;
	PersonaType personaType;
	int personaId = 0;

	static int count_;
	static int currentId;

	void convertGenderView(Gender type);
public:
	Persona();
	Persona(string name, Gender gender, int age, string InstituteName, string FacultyName, string DepartmentName, PersonaType personaType);
	Persona(PersonaType type);
	Persona(const Persona& persona);

	virtual ~Persona();
	virtual void ShowPersonaData();
	virtual void writeToFile(ofstream* file);

	string getName();
	Gender getGender();
	int getAge();
	string getInstituteName();
	string getFacultyName();
	string getDepartmentName();
	static int getPersonaCount();
	int getPersonaId();
	PersonaType getPersonaType(PersonaType);

	void setName(string);
	void setGender(Gender);
	void setAge(int);
	void setInstituteName(string);
	void setFacultyName(string);
	void setDepartmentName(string);
	void setPersonaType(PersonaType);
};

