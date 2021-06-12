#include "Persona.h";
#include <string>

using namespace std;

int Persona::count_ = 0;
int Persona::currentId = 0;

void Persona::convertGenderView(Gender type)
{
	switch (type)
	{
	case male:
		cout << "�������" << endl;
		break;

	case female:
		cout << "�������" << endl;
		break;

	case other:
		cout << "������" << endl;
		break;

	case attackHelicopter:
		cout << "������ ��������" << endl;
		break;

	case commandant:
		cout << "���������" << endl;
		break;
	default:
		cout << "�������������" << endl;
		break;
		cout << "\n";
	};
}

Persona::Persona()
{
	count_++;
}

Persona::Persona(string name, Gender gender, int age, string InstituteName, string FacultyName, string DepartmentName, PersonaType personaType)
{
	currentId++;
	count_++;
	personaName = name;
	personaGender = gender;
	personaAge = age;
	instituteName = InstituteName;
	facultyName = FacultyName;
	departmentName = DepartmentName;
	this->personaType = personaType;
	personaId = currentId;
}
// ������������ �����������
Persona::Persona(PersonaType type)
{
	count_++;
	currentId++;
	personaId = currentId;
	personaType = type;
	cout << "������� ���: ";
	cin.ignore();
	getline(cin, personaName);
	// ��������� ������� - ������
	cout << "������� ������ �� ������: \n";
	for (int i = 0; i < Gender::endOfEnum - 1; i++) {
		cout << i + 1 << ")";
		convertGenderView((Gender)(i+1));
	}
	int gender;
	cin >> gender;
	personaGender = (Gender)gender;
	// ��������� ������� - �����
	cout << "������� �������: ";
	cin >> personaAge;
	cin.ignore();
	cout << "������� �������� ���������: ";
	getline(cin, instituteName);
	cout << "������� �������� ����������: ";
	getline(cin, facultyName);
	cout << "������� �������� �������: ";
	getline(cin, departmentName);
}

Persona::Persona(const Persona& persona)
{
	count_++;
	personaName = persona.personaName;
	personaGender = persona.personaGender;
	personaAge = persona.personaAge;
	instituteName = persona.instituteName;
	facultyName = persona.facultyName;
	departmentName = persona.departmentName;

}

Persona::~Persona()
{
	cout << "" << endl;
	count_--;
}
// �������
string Persona::getName()
{
	return personaName;
}

Gender Persona::getGender()
{
	return personaGender;
}

int Persona::getAge()
{
	return personaAge;
}

string Persona::getInstituteName()
{
	return instituteName;
}

string Persona::getFacultyName()
{
	return facultyName;
}

string Persona::getDepartmentName()
{
	return departmentName;
}

int Persona::getPersonaCount()
{
	return count_;
}

int Persona::getPersonaId()
{
	return personaId;
}

PersonaType Persona::getPersonaType(PersonaType)
{
	return personaType;
}

void Persona::setName(string name)
{
	personaName = name;
}
// �������
void Persona::setGender(Gender gender)
{
	personaGender = gender;
}

void Persona::setAge(int age)
{
	personaAge = age;
}

void Persona::setInstituteName(string name)
{
	instituteName = name;
}

void Persona::setFacultyName(string name)
{
	facultyName = name;
}

void Persona::setDepartmentName(string name)
{
	departmentName = name;
}

void Persona::setPersonaType(PersonaType type)
{
	personaType = type;
}
// �������
void Persona::ShowPersonaData()
{
	cout << "\n\n";
	cout << "ID: " << personaId << endl;
	cout << "���: " << personaName << endl;
	cout << "�������: " << personaAge << endl;
	cout << "��������: " << instituteName << endl;
	cout << "���������: " << facultyName << endl;
	cout << "�������: " << departmentName << endl;
	cout << "������: ";
	convertGenderView(personaGender);
}
// ������ � ����
void Persona::writeToFile(ofstream* file)
{
	if (!file->is_open()) {
		std::cout << "������! ���� �� ����� ���� ������!\n";
	} else {
		int personaNameSize = personaName.length() + 1;
		int facultyNameSize = facultyName.length() + 1;
		int instituteNameSize = instituteName.length() + 1;
		int departmentNameSize = departmentName.length() + 1;
		personaName.append("\0");
		instituteName.append("\0");
		facultyName.append("\0");
		departmentName.append("\0");
		//���������� ��� ������ ��� ���������� � �������� ������
		file->write(reinterpret_cast<char*>(&personaType), sizeof(personaType));
		//���������� ��� �������
		file->write(reinterpret_cast<char*>(&personaNameSize), sizeof(personaNameSize));
		file->write(personaName.data(), personaNameSize);
		//���������� ������ �������
		file->write(reinterpret_cast<char*>(&personaGender), sizeof(personaGender));
		//���������� ������� �������
		file->write(reinterpret_cast<char*>(&personaAge), sizeof(personaAge));
		//���������� �������� �������
		file->write(reinterpret_cast<char*>(&instituteNameSize), sizeof(instituteNameSize));
		file->write(instituteName.data(), instituteNameSize);
		//���������� ��������� �������
		file->write(reinterpret_cast<char*>(&facultyNameSize), sizeof(facultyNameSize));
		file->write(facultyName.data(), facultyNameSize);
		//���������� ������� �������
		file->write(reinterpret_cast<char*>(&departmentNameSize), sizeof(departmentNameSize));
		file->write(departmentName.data(), departmentNameSize);

		std::cout << "���� �������\n";
	}

}



