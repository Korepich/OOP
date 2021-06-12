#include "PersonaList.h"

using namespace std;

void PersonaList::addItem(Persona* persona) {
	personaList.push_back(persona);
}

void PersonaList::showAllItems() {
	if (!personaList.empty()) {
		for (auto element : personaList) {
			element->ShowPersonaData();
		}
	}
	else {
		std::cout << "\nCписок пуст!\n";
	}
}

void PersonaList::showItem(int personaId) {
	if (!personaList.empty()) {
		for (auto element : personaList) {
			if (element->getPersonaId() == personaId) {
				element->ShowPersonaData();
			}
		}
	}
	else {
		std::cout << "Список пуст!\n";
	}
}

void PersonaList::deleteAllItems() {
	if (!personaList.empty()) {
		std::vector<Persona*>::iterator itt;
		for (itt = personaList.begin(); itt != personaList.end();) {
			delete* itt;
			itt = personaList.erase(itt);
		}
		std::cout << "\nВсе элементы были удалены из списка!\n";
	}
	else {
		std::cout << "\nВы не можете очистить список, так как он уже пуст!\n";
	}
}

void PersonaList::deleteItem(int personaId) {
	if (!personaList.empty()) {
		std::vector<Persona*>::iterator itt;
		for (itt = personaList.begin(); itt != personaList.end();) {
			if ((*itt)->getPersonaId() == personaId) {
				delete* itt;
				itt = personaList.erase(itt);
			}
			else {
				itt++;
			}
		}
	}
	else {
		std::cout << "\nВы не можете удалить элемент списка, так как он уже пуст!\n";
	}
}

void PersonaList::showItemsByClassName(const type_info& type) {
	for (auto element : personaList) {
		if (typeid(*element) == type) {
			element->ShowPersonaData();
		}
	}
}

void PersonaList::writeToFile(std::ofstream* file) {
	for (auto element : personaList) {
		element->writeToFile(file);
	}
}

void PersonaList::addObjectsFromFile() {
	file_->open("data.txt", std::ios::binary | std::ios::in);
	if (!file_->is_open()) {
		std::cout << "Невозможно открыть файл!" << "\n";
		exit(1);
	}

	if (!(file_->peek() == std::ifstream::traits_type::eof())) {
		while (!(file_->peek() == std::ifstream::traits_type::eof())) {
			int type = 0;
			int personaNameSize = 0;
			int personaInstituteNameSize = 0;
			int personaFacultyNameSize = 0;
			int personaDepartmentNameSize = 0;
			int personaGender = 0;
			int age = 0;
			//Считываем тип
			file_->read(reinterpret_cast<char*>(&type), sizeof(int));
			//Считываем имя персоны 
			file_->read(reinterpret_cast<char*>(&personaNameSize), sizeof(int));
			char* personaNameCh = new char[personaNameSize];
			file_->read(personaNameCh, personaNameSize);
			//Считываем гендер персоны
			file_->read(reinterpret_cast<char*>(&personaGender), sizeof(int));
			//Считываем возраст персоны
			file_->read(reinterpret_cast<char*>(&age), sizeof(int));
			//Считываем институт персоны 
			file_->read(reinterpret_cast<char*>(&personaInstituteNameSize), sizeof(int));
			char* perosnaInstituteNameCh = new char[personaInstituteNameSize];
			file_->read(perosnaInstituteNameCh, personaInstituteNameSize);
			//Считываем факультет персоны
			file_->read(reinterpret_cast<char*>(&personaFacultyNameSize), sizeof(int));
			char* perosnaFacultyNameCh = new char[personaFacultyNameSize];
			file_->read(perosnaFacultyNameCh, personaFacultyNameSize);
			//Считываем кафедру персоны
			file_->read(reinterpret_cast<char*>(&personaDepartmentNameSize), sizeof(int));
			char* perosnaDepartmentNameCh = new char[personaDepartmentNameSize];
			file_->read(perosnaDepartmentNameCh, personaDepartmentNameSize);
			//Подготовка данных к созданию класса
			std::string personaName(personaNameCh);
			std::string personaInstituteName(perosnaInstituteNameCh);
			std::string personaFacultyName(perosnaFacultyNameCh);
			std::string personaDepartmentName(perosnaDepartmentNameCh);
			switch (type)
			{
			case Student_:
				initStudentObject(Student_, personaName, age, personaInstituteName, personaFacultyName, personaDepartmentName, (Gender)personaGender);
				break;
			case Teacher_:
				initTeacherObject(Teacher_, personaName, age, personaInstituteName, personaFacultyName, personaDepartmentName, (Gender)personaGender);
				break;
			case HOD_:
				initHodObject(HOD_, personaName, age, personaInstituteName, personaFacultyName, personaDepartmentName, (Gender)personaGender);
				break;
			default:
				std::cout << "Ошибка!\n";
				break;
			}
			delete[] personaNameCh;
			delete[] perosnaInstituteNameCh;
			delete[] perosnaFacultyNameCh;
			delete[] perosnaDepartmentNameCh;
		}
		file_->close();
	}
}

bool PersonaList::isEmpty() {
	return personaList.empty();
}

PersonaList::~PersonaList() {
	if (!personaList.empty()) {
		std::vector<Persona*>::iterator itt;
		for (itt = personaList.begin(); itt != personaList.end();) {
			delete* itt;
			itt = personaList.erase(itt);
		}
	}
	delete file_;
}

void PersonaList::initStudentObject(PersonaType type, string personaName, int age, string instituteName, 
									string facultyName, string departmentName, Gender gender) {
	int academicDebts = 0;
	int course = 0;
	file_->read(reinterpret_cast<char*>(&academicDebts), sizeof(int));
	file_->read(reinterpret_cast<char*>(&course), sizeof(int));
	addItem(new Student(academicDebts, course, personaName, gender, age, instituteName, facultyName, departmentName, type));
}

void PersonaList::initTeacherObject(PersonaType type, string personaName, int age, string instituteName, string facultyName, string departmentName, Gender gender) {
	int teacherAcademicDegreeSize = 0;
	int teacherAcademicTitleSize = 0;
	//Считываем учёную степень
	file_->read(reinterpret_cast<char*>(&teacherAcademicDegreeSize), sizeof(int));
	char* teacherAcademicDegreeCh = new char[teacherAcademicDegreeSize];
	file_->read(reinterpret_cast<char*>(teacherAcademicDegreeCh), teacherAcademicDegreeSize);
	//Считываем звание преподавателя
	file_->read(reinterpret_cast<char*>(&teacherAcademicTitleSize), sizeof(int));
	char* teacherAcademicTitleCh = new char[teacherAcademicTitleSize];
	file_->read(reinterpret_cast<char*>(teacherAcademicTitleCh), teacherAcademicTitleSize);

	string teacherDegree(teacherAcademicDegreeCh);
	string teacherTitle(teacherAcademicTitleCh);

	addItem(new Teacher(teacherDegree, teacherTitle, personaName, gender, age, instituteName, facultyName, departmentName, type));

	delete[] teacherAcademicDegreeCh;
	delete[] teacherAcademicTitleCh;
}

void PersonaList::initHodObject(PersonaType type, string personaName, int age, string instituteName, string facultyName, string departmentName, Gender gender) {
	int groupCount = 0;
	int studentCount = 0;

	file_->read(reinterpret_cast<char*>(&groupCount), sizeof(int));
	file_->read(reinterpret_cast<char*>(&studentCount), sizeof(int));

	addItem(new HOD(groupCount, studentCount, personaName, gender, age, instituteName, facultyName, departmentName, type));
}
