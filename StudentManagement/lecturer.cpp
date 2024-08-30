#include "lecturer.h"

Lecturer::Lecturer(int id, std::string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_categoryId = dId;
}

void Lecturer::showInfo()
{
	std::cout << "Lecturer ID: " << this->m_id
		<< "    Name: " << this->m_name
		<< "    Department: " << this->m_categoryId
		<< "    Responsibility: Deliver lectures" << std::endl;
}

std::string Lecturer::getCategoryName()
{
	return std::string("Lecturer");
}