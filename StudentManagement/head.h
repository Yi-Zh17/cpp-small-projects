#pragma once
#include <iostream>
#include "people.h"

class Head : public People
{
public:

	Head(int id, std::string name, int dId);

	virtual void showInfo();

	virtual std::string getCategoryName();
};
