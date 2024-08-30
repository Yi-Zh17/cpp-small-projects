#include "schoolManager.h"
#include "people.h"
#include "student.h"
#include "lecturer.h"
#include "head.h"

SchoolManager::SchoolManager()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);

	// Check whether save file exists
	if (!ifs.is_open())
	{
		std::cout << "Creating a save file..." << std::endl;
		this->m_numPeople = 0;
		this->m_peopleArray = nullptr;
		this->m_fileIsEmpty = true;
		ifs.close();
		return;
	}

	// Check whether save file is empty
	char ch;
	ifs >> ch;
	if (ifs.eof())
	{
		std::cout << "Save file is empty." << std::endl;
		this->m_numPeople = 0;
		this->m_peopleArray = nullptr;
		this->m_fileIsEmpty = true;
		ifs.close();
		return;
	}
	
	// Initialize data if file not empty
	int num = this->getPeopleNum();
	std::cout << num << " people in record." << std::endl;
	this->m_numPeople = num;
	// Initialize array
	this->m_peopleArray = new People * [this->m_numPeople];
	// Initialize data
	this->initPeople();

	// Testing
	//for (int i = 0; i < this->m_numPeople; i++)
	//{
	//	std::cout << "ID: " << this->m_peopleArray[i]->m_id
	//		<< "Name: " << this->m_peopleArray[i]->m_name
	//		<< "Title: " << this->m_peopleArray[i]->m_categoryId << std::endl;
	//}
}

SchoolManager::~SchoolManager()
{
	if (this->m_peopleArray != nullptr)
	{
		delete[] this->m_peopleArray;
		this->m_peopleArray = nullptr;
	}
}

void SchoolManager::show_menu()
{
	std::cout << "**********************************" << std::endl;
	std::cout << "**** School Management System ****" << std::endl;
	std::cout << "**********************************" << std::endl;
	std::cout << "***** 0. Exit               ******" << std::endl;
	std::cout << "***** 1.Add Person Info     ******" << std::endl;
	std::cout << "***** 2.Show Person Info    ******" << std::endl;
	std::cout << "***** 3.Delete Person Info  ******" << std::endl;
	std::cout << "***** 4.Edit Person Info    ******" << std::endl;
	std::cout << "***** 5.Search Person Info  ******" << std::endl;
	std::cout << "***** 6.Sort by ID          ******" << std::endl;
	std::cout << "***** 7.Clear all entries   ******" << std::endl;
	std::cout << "**********************************" << std::endl;
	std::cout << "**********************************" << std::endl;
	std::cout << std::endl;
}

void SchoolManager::exitSystem()
{
	std::cout << "Bye" << std::endl;
	system("pause");
	exit(0);
}

void SchoolManager::addPeople()
{
	std::cout << "Number of people you would like to add: ";

	int num = 0;
	std::cin >> num;

	if (num > 0)
	{
		// Calculate overall size needed
		int newSize = this->m_numPeople + num;

		// Open up a new space in heap
		People** newPeopleArr = new People * [newSize];

		// Copy old data into new array
		if (this->m_peopleArray != nullptr)
		{
			for (int i = 0; i < this->m_numPeople; i++)
			{
				newPeopleArr[i] = this->m_peopleArray[i];
			}
		}

		// Add new data
		for (int i = 0; i < num; i++)
		{
			int id;
			std::string name;
			int category;

			std::cout << "Person No." << i << ": " << std::endl;

			std::cout << "ID: " << std::endl;
			std::cin >> id;

			std::cout << "Name: " << std::endl;
			std::cin >> name;

			std::cout << "Category: " << std::endl;
			std::cout << "1. Student" << std::endl;
			std::cout << "2. Lecturer" << std::endl;
			std::cout << "3. Head of School" << std::endl;
			std::cin >> category;

			People* people = nullptr;

			switch (category)
			{
			case 1:
				people = new Student(id, name, category);
				break;

			case 2:
				people = new Lecturer(id, name, category);
				break;

			case 3:
				people = new Head(id, name, category);
				break;

			default:
				std::cout << "Invalid input. Aborted." << std::endl;
				system("pause");
				system("cls");
				return;
			}

			newPeopleArr[this->m_numPeople + i] = people;

		}

		// Release original array
		delete[] this->m_peopleArray;

		// Assign new array
		this->m_peopleArray = newPeopleArr;

		// Update size of new array
		this->m_numPeople = newSize;

		// Message
		std::cout << "Successfully added " << num << "people." << std::endl;

		// Save data
		this->save();
		this->m_fileIsEmpty = false;

	}

	else
	{
		std::cout << "Invalid input." << std::endl;
	}

	system("pause");
	system("cls");
}

int SchoolManager::getPeopleNum()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);

	int id;
	std::string name;
	int category;

	int num = 0;
	while (ifs >> id && ifs >> name && ifs >> category)
	{
		//Increment number of people
		num++;
	}

	return num;
}

void SchoolManager::initPeople()
{
	std::ifstream ifs;
	ifs.open(FILENAME, std::ios::in);

	int id;
	std::string name;
	int category;

	int index = 0;
	while (ifs >> id && ifs >> name && ifs >> category)
	{
		People* people = nullptr;
		switch (category)
		{
		case 1:
			people = new Student(id, name, category);
			break;

		case 2:
			people = new Lecturer(id, name, category);
			break;

		case 3:
			people = new Head(id, name, category);
			break;

		default:
			break;
		}

		this->m_peopleArray[index] = people;
		index++;
	}
}

void SchoolManager::showPeople()
{
	if (this->m_fileIsEmpty)
	{
		std::cout << "There are no people in record." << std::endl;
		system("pause");
		system("cls");
	}
	else
	{
		for (int i = 0; i < this->m_numPeople; i++)
		{
			this->m_peopleArray[i]->showInfo();
		}
	}

	system("pause");
	system("cls");
}

void SchoolManager::deletePeople()
{
	if (this->m_fileIsEmpty)
	{
		std::cout << "There are no people in record." << std::endl;
		system("pause");
		system("cls");
	}
	else
	{
		std::cout << "Please provide the person's id: " << std::endl;
		int id = 0;
		std::cin >> id;
	
		int index = -1;
		if (index != -1)
		{
			for (int i = index; i < this->m_numPeople - 1; i++)
			{
				this->m_peopleArray[i] = this->m_peopleArray[i + 1];
			}
			this->m_numPeople--;
		}
		else
		{
			std::cout << "Person not found. Aborted." << std::endl;
		}
	}

	system("pause");
	system("cls");
}

int SchoolManager::peopleExist(int id)
{
	int index = -1; // return -1 if person does not exist

	for (int i = 0; i < this->m_numPeople; i++)
	{
		if (this->m_peopleArray[i]->m_id == id)
		{
			index = i;
			break;
		}
	}
	return index;
}

void SchoolManager::modifyPeople()
{
	if (this->m_fileIsEmpty)
	{
		std::cout << "There are no people in record." << std::endl;
		system("pause");
		system("cls");
	}
	else
	{
		std::cout << "Please provide the person's ID: ";
		int id;
		std::cin >> id;

		int result = this->peopleExist(id);
		if (result != -1)
		{
			delete this->m_peopleArray[result];

			int newId = 0;
			std::string newName = "";
			int newCategory = 0;

			std::cout << "Person found." << std::endl;
			std::cout << "New ID: ";
			std::cin >> newId;
			std::cout << "New Name: " << std::endl;
			std::cin >> newName;
			std::cout << "New Category: " << std::endl;
			std::cout << "1. Student" << std::endl;
			std::cout << "2. Lecturer" << std::endl;
			std::cout << "3. Head of School" << std::endl;
			std::cin >> newCategory;

			People* people = nullptr;
			switch (newCategory)
			{
			case 1:
				people = new Student(newId, newName, newCategory);
				break;

			case 2:
				people = new Lecturer(newId, newName, newCategory);
				break;

			case 3:
				people = new Head(newId, newName, newCategory);
				break;

			default:
				break;
			}

			this->m_peopleArray[result] = people;

			std::cout << "Successfully modified." << std::endl;

			this->save();
		}
		else
		{
			std::cout << "Person not found. Aborted." << std::endl;
		}
	}

	system("pause");
	system("cls");
}

void SchoolManager::findPeople()
{
	if (this->m_fileIsEmpty)
	{
		std::cout << "There are no people in record." << std::endl;
		system("pause");
		system("cls");
	}
	else
	{
		std::cout << "1. Search by ID" << std::endl;
		std::cout << "2. Search by name" << std::endl;

		int select = 0;
		std::cin >> select;

		if (select == 1)
		{
			std::cout << "Please provide the person's ID: ";
			int id;
			std::cin >> id;
			int result = this->peopleExist(id);

			if (result != -1)
			{
				std::cout << "Person found." << std::endl;
				this->m_peopleArray[result]->showInfo();
			}
			else
			{
				std::cout << "Person not found." << std::endl;
			}
		}
		else if (select == 2)
		{
			std::string name;
			std::cout << "Please provide the person's name: ";
			std::cin >> name;
			
			// Flag remains false if person not found
			bool flag = false;
			for (int i = 0; i < m_numPeople; i++)
			{
				if (m_peopleArray[i]->m_name == name)
				{
					std::cout << "Person found." << std::endl;
					this->m_peopleArray[i]->showInfo();
					flag = true;
				}
			}

			if (flag == false)
			{
				std::cout << "Person not found." << std::endl;
			}
		}
		else
		{
			std::cout << "Invalid input. Please try again." << std::endl;
		}

		system("pause");
		system("cls");
	}
}

void SchoolManager::sortPeople()
{
	if (this->m_fileIsEmpty)
	{
		std::cout << "There are no people in record." << std::endl;
		system("pause");
		system("cls");
	}
	else
	{
		std::cout << "1. Ascending order" << std::endl;
		std::cout << "2. Descending order" << std::endl;

		int choice;
		std::cin >> choice;

		for (int i = 0; i < this->m_numPeople; i++)
		{
			int benchmark = i;
			for (int j = i + 1; j < this->m_numPeople; j++)
			{
				if (choice == 1)
				{
					if (this->m_peopleArray[benchmark]->m_id > this->m_peopleArray[j]->m_id)
					{
						benchmark = j;
					}
				}
				else if (choice == 2)
				{
					if (this->m_peopleArray[benchmark]->m_id < this->m_peopleArray[j]->m_id)
					{
						benchmark = j;
					}
				}
				else
				{
					std::cout << "Invalid input. Aborted." << std::endl;
				}
			}

			if (i != benchmark)
			{
				// Swap people
				People* temp = this->m_peopleArray[i];
				this->m_peopleArray[i] = this->m_peopleArray[benchmark];
				this->m_peopleArray[benchmark] = temp;
			}
		}

		std::cout << "Sorted. Result: " << std::endl;
		this->save();
		this->showPeople();
	}
}

void SchoolManager::clearAll()
{
	std::cout << "This will wipe out all data. Continue? (y/n)" << std::endl;
	char choice;
	std::cin >> choice;

	if (choice == 'y')
	{
		// use ios::trunc to recreate the file
		std::ofstream ofs(FILENAME, std::ios::trunc);
		ofs.close();

		if (this->m_peopleArray != nullptr)
		{
			for (int i = 0; i < this->m_numPeople; i++)
			{
				if (this->m_peopleArray[i] != nullptr)
				{
					delete this->m_peopleArray[i];
				}
			}
			this->m_numPeople = 0;
			delete[] this->m_peopleArray;
			this->m_peopleArray = nullptr;
			this->m_fileIsEmpty = true;
		}

		std::cout << "Successfully wiped out all data." << std::endl;

		system("pause");
		system("cls");
	}
}

void SchoolManager::save()
{
	std::ofstream ofs;
	ofs.open(FILENAME, std::ios::out);

	for (int i = 0; i < this->m_numPeople; i++)
	{
		ofs << this->m_peopleArray[i]->m_id << " "
			<< this->m_peopleArray[i]->m_name << " "
			<< this->m_peopleArray[i]->m_categoryId << std::endl;
	}

	ofs.close();
}