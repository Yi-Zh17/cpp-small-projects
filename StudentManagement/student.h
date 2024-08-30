#pragma once
#include<iostream>
#include<string>
#include "people.h"

class Student : public People
{
public:
	Student(int id, std::string name, int dId);

	virtual void showInfo();

	virtual std::string getCategoryName();
};
