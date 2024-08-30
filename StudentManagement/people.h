#pragma once
#include <iostream>
#include <string>

// Abstract class Worker 
class People
{
public:

	virtual void showInfo() = 0;

	virtual std::string getCategoryName() = 0;

	int m_id; // Personal ID
	std::string m_name; // Name
	int m_categoryId; // Category ID
};
