#include <iostream>
#include <string>

#define MAX 1000

struct Person {
	std::string name;
	char gender;
	int age;
	std::string tel;
	std::string city;
};

struct Contact {
	Person people[MAX];
	int size;
};

// Show menu
void showMenu()
{
	std::cout << "************************" << std::endl;
	std::cout << "* 1. Add contact       *" << std::endl;
	std::cout << "* 2. Show all contact  *" << std::endl;
	std::cout << "* 3. Delete contact    *" << std::endl;
	std::cout << "* 4. Find contact      *" << std::endl;
	std::cout << "* 5. Edit contact      *" << std::endl;
	std::cout << "* 6. Clear all contact *" << std::endl;
	std::cout << "* 0. Quit              *" << std::endl;
	std::cout << "************************" << std::endl;
}

// Add contact
void addPerson(Contact* contact)
{
	if (contact->size >= MAX)
	{
		// Check the size of the contact
		std::cout << "Contact already full." << std::endl;
		return;
	}
	else
	{
		// name
		std::string name;
		std::cout << "Name: " << std::endl;
		std::cin >> name;
		contact->people[contact->size].name = name;

		// gender
		char gender;
		while (true)
		{
			std::cout << "Gender (M/F/N): " << std::endl;
			std::cin >> gender;
			if (gender == 'M' || gender == 'F' || gender == 'N')
			{
				contact->people[contact->size].gender = gender;
				break;
			}
			else
			{
				std::cout << "Invalid input. Try again." << std::endl;
			}
		}

		// age
		int age;
		while (true)
		{
			std::cout << "Age: " << std::endl;
			std::cin >> age;
			if (age >= 0 && age <= 150)
			{
				contact->people[contact->size].age = age;
				break;
			}
			else
			{
				std::cout << "Invalid input. Try again." << std::endl;
			}
		}
		
		// tel
		std::string tel;
		std::cout << "Telephone number:" << std::endl;
		std::cin >> tel;
		contact->people[contact->size].tel = tel;

		// city
		std::string city;
		std::cout << "City: " << std::endl;
		std::cin >> city;
		contact->people[contact->size].city = city;

		contact->size++;
		std::cout << "Successfully added a person to contact." << std::endl;

		// Press any button to continue
		system("pause");
		system("cls");
	}
}

void showPeople(Contact* contact)
{
	if (contact->size == 0)
	{
		std::cout << "There are no contacts yet." << std::endl;
		return;
	}
	else
	{
		for (int i = 0; i < contact->size; i++)
		{
			std::cout << "Name: " << contact->people[i].name
				<< "    " << "Gender: " << contact->people[i].gender
				<< "    " << "Age: " << contact->people[i].age
				<< "    " << "Telephone: " << contact->people[i].tel
				<< "    " << "City: " << contact->people[i].city << std::endl;
		}

		system("pause");
		system("cls");
	}
}

// Detect if a person exists
int person_exists(Contact* contact, std::string person_name)
{
	for (int i = 0; i < contact->size; i++)
	{
		if (contact->people[i].name == person_name)
			return i; // returns location if exists
	}
	return -1; // return -1 otherwise
}

// Delete a person
void deletePerson(Contact* contact)
{
	std::cout << "Name the person to be deleted:" << std::endl;
	std::string name;
	std::cin >> name;

	int result = person_exists(contact, name);
	if (result == -1)
		std::cout << "No such person." << std::endl;
	else
	{
		for (int i = result; i < contact->size; i++)
		{
			contact->people[i] = contact->people[i + 1];
		}
		contact->size--;
	}

	std::cout << "Successfully deleted one person from contact." << std::endl;

	system("pause");
	system("cls");
}

// Find a person
void findPerson(Contact* contact)
{
	std::cout << "Name a person to be found:" << std::endl;
	std::string name;
	std::cin >> name;

	int result = person_exists(contact, name);
	if (result == -1)
		std::cout << "No such person." << std::endl;
	else
	{
		std::cout << "Name: " << contact->people[result].name
			<< "    " << "Gender: " << contact->people[result].gender
			<< "    " << "Age: " << contact->people[result].age
			<< "    " << "Telephone: " << contact->people[result].tel
			<< "    " << "City: " << contact->people[result].city << std::endl;
	}

	system("pause");
	system("cls");
}

// Edit a person's info
void modifyPerson(Contact* contact)
{
	std::cout << "Name a person to be modified:" << std::endl;
	std::string name;
	std::cin >> name;

	int result = person_exists(contact, name);

	if (result == -1)
		std::cout << "No such person." << std::endl;
	else
	{
		// name
		std::string name;
		std::cout << "Name: " << std::endl;
		std::cin >> name;
		contact->people[result].name = name;

		// gender
		char gender;
		while (true)
		{
			std::cout << "Gender (M/F/N): " << std::endl;
			std::cin >> gender;
			if (gender == 'M' || gender == 'F' || gender == 'N')
			{
				contact->people[result].gender = gender;

				break;
			}
			else
			{
				std::cout << "Invalid input. Try again." << std::endl;
			}
		}

		// age
		int age;
		while (true)
		{
			std::cout << "Age: " << std::endl;
			std::cin >> age;
			if (age >= 0 && age <= 150)
			{
				contact->people[result].age = age;
				break;
			}
			else
			{
				std::cout << "Invalid input. Try again." << std::endl;
			}
		}

		// tel
		std::string tel;
		std::cout << "Telephone number:" << std::endl;
		std::cin >> tel;
		contact->people[result].tel = tel;

		// city
		std::string city;
		std::cout << "City: " << std::endl;
		std::cin >> city;
		contact->people[result].city = city;

		contact->size++;
		std::cout << "Successfully modified the person's info." << std::endl;
	}
	// Press any button to continue
	system("pause");
	system("cls");
}


// Clear contact
void clearContact(Contact* contact)
{
	std::cout << "Clear all contact? (y/n)" << std::endl;
	char ans;
	while (true)
	{
		std::cin >> ans;
		if (ans == 'y')
		{
			// Perform a logical clear
			contact->size = 0;

			std::cout << "Contact all cleared." << std::endl;
			break;
		}
		else if (ans == 'n')
		{
			break;
		}
		else {
			std::cout << "Invalid input. Try again." << std::endl;
		}
	}

	system("pause");
	system("cls");
}

int main()
{
	// Initialize a Contact
	Contact address_book;
	address_book.size = 0;

	// Variable to receive input
	int select = 0;
	
	// Program loop
	while (true)
	{
		showMenu();
		std::cin >> select;

		switch (select)
		{
		// quit
		case 0:
			std::cout << "Quitted." << std::endl;
			system("pause");
			return 0;
		// Add contact		
		case 1:
			addPerson(&address_book);
			break;
		// Show contact
		case 2:
			showPeople(&address_book);
			break;
		// Delete contact
		case 3:
			deletePerson(&address_book);
			break;
			// Find contact
		case 4:
			findPerson(&address_book);
			break;
		// Edit contact
		case 5:
			modifyPerson(&address_book);
			break;
		// Clear contact
		case 6:
			clearContact(&address_book);
			break;
		default:
			system("cls");
			break;
		}
	}



	system("pause");
	return 0;
}