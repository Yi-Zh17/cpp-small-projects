#include <iostream>
#include "schoolManager.h"

int main()
{
	// Instantiate a SchoolManager
	SchoolManager sm;

	int choice = 0;
	while (true)
	{
		sm.show_menu();
		std::cout << "Select an option: ";
		std::cin >> choice;

		switch (choice)
		{
		case 0:
			sm.exitSystem();
			break;
		case 1:
			sm.addPeople();
			break;
		case 2:
			sm.showPeople();
			break;
		case 3:
			sm.deletePeople();
			break;
		case 4:
			sm.modifyPeople();
			break;
		case 5:
			sm.findPeople();
			break;
		case 6:
			sm.sortPeople();
			break;
		case 7:
			sm.clearAll();
			break;
		default:
			system("cls");
			break;
		}
	}

	system("pause");
	return 0;
}