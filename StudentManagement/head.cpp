#include "head.h"

Head::Head(int id, std::string name, int dId)
{
	this->m_id = id;
	this->m_name = name;
	this->m_categoryId = dId;
}

void Head::showInfo()
{
	std::cout << "Head ID: " << this->m_id
		<< "    Name: " << this->m_name
		<< "    Department: " << this->getCategoryName()
		<< "    Responsibility: Hold conferences" << std::endl;
}

std::string Head::getCategoryName()
{
	return std::string("Head of School");
}