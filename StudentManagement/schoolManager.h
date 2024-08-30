#pragma once
#include <iostream>
#include "people.h"
#include <fstream>

#define FILENAME "profile.txt"

class SchoolManager
{
public:
	// Constructors and destructors
	SchoolManager();

	~SchoolManager();

	// Methods
	void show_menu();

	void exitSystem();

	void save();

	void addPeople();

	int getPeopleNum();

	void initPeople();

	void showPeople();

	void deletePeople();

	int peopleExist(int id);

	void modifyPeople();

	void findPeople();

	void sortPeople();

	void clearAll();

	// Member variable
	int m_numPeople; // Number of people in record

	People** m_peopleArray;

	bool m_fileIsEmpty;

};
