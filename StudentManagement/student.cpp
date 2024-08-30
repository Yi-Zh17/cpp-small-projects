#include "student.h"

Student::Student(int id, std::string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_categoryId = dId;
}

void Student::showInfo() {
	std::cout << "Student ID: " << this->m_id
		<< "    Name: " << this->m_name
		<< "    Department: " << this->getCategoryName()
		<< "    Responsibility: Attend lectures" << std::endl;
}

std::string Student::getCategoryName()
{
	return std::string("Student");
}