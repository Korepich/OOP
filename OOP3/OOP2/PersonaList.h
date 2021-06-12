#pragma once
#include <fstream>
#include <typeinfo>
#include <iostream>
#include <string>
#include <vector>

#include "Persona.h"
#include "Student.h"
#include "Teacher.h"
#include "HOD.h"

using namespace std;

class PersonaList
{
public:
	void addItem(Persona* persona);
	void showAllItems();
	void showItem(int personaId);

	void deleteAllItems();
	void deleteItem(int personaId);

	void showItemsByClassName(const type_info& type);
	void writeToFile(std::ofstream* file);
	void addObjectsFromFile();
	bool isEmpty();
	~PersonaList();

private:
	void initStudentObject(PersonaType type, string personaName, int age, string instituteName, string facultyName, string departmentName, Gender gender);
	void initTeacherObject(PersonaType type, string personaName, int age, string instituteName, string facultyName, string departmentName, Gender gender);
	void initHodObject(PersonaType type, string personaName, int age, string instituteName, string facultyName, string departmentName, Gender gender);

	std::vector<Persona*> personaList;
	std::ifstream* file_ = new std::ifstream;
};

