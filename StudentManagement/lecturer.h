#pragma once
#include<iostream>
#include "people.h"

class Lecturer : public People
{
public:

	Lecturer(int id, std::string name, int dId);

	virtual void showInfo();

	virtual std::string getCategoryName();
};
