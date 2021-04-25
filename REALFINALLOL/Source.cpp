#include <iostream>
#include "CD.h"
#include "DVD.h"

//menu fucntions
int menu();
void addCD(Linked_List<CD>*);
void addDVD(Linked_List<DVD>*);
void removeCD(Linked_List<CD>*);
void removeDVD(Linked_List<DVD>*);
void updateCD(Linked_List<CD>*);
void updateDVD(Linked_List<DVD>*);
void displayCDs(Linked_List<CD>*);
void displayDVDs(Linked_List<DVD>*);


int main()
{
	//cd lists
	Linked_List<CD> CD_List;
	Linked_List<CD>* CD_List_Ptr;
	CD_List_Ptr = &CD_List;
	//dvd lists
	Linked_List<DVD> DVD_List;
	Linked_List<DVD>* DVD_List_Ptr;
	DVD_List_Ptr = &DVD_List;


	int menuChoice;
	do
	{
		//switch case to function the menu
		menuChoice = menu();

		switch (menuChoice)
		{
		case 1:
			addCD(CD_List_Ptr);
			break;
		case 2:
			addDVD(DVD_List_Ptr);
			break;
		case 3:
			removeCD(CD_List_Ptr);
			break;
		case 4:
			removeDVD(DVD_List_Ptr);
			break;
		case 5:
			updateCD(CD_List_Ptr);
			break;
		case 6:
			updateDVD(DVD_List_Ptr);
			break;
		case 7:
			displayCDs(CD_List_Ptr);
			break;
		case 8:
			displayDVDs(DVD_List_Ptr);
			break;
		}
	} while (menuChoice != 9);

	// end of program
	cout << endl;
	system("pause");
	return 0;
}

//just display your options and read in a choice
int menu()
{
	int choice;
	cout << endl;
	cout << "Menu" << endl
		<< "1. Add CD" << endl
		<< "2. Add DVD" << endl
		<< "3. Remove CD" << endl
		<< "4. Remove DVD" << endl
		<< "5. Update CD" << endl
		<< "6. Update DVD" << endl
		<< "7. Display CDs" << endl
		<< "8. Display DVDs" << endl
		<< "9. Quit" << endl;
	cout << "Enter your choice (1-9): ";
	cin >> choice;

	while (choice < 1 || choice > 9)
	{
		cout << "Invalid choice. Try again ";
		cin >> choice;
	}

	return choice;
}

// add cd choice 1
void addCD(Linked_List<CD>* cdList)
{
	CD myCD;
	string str;
	cin.ignore();

	cout << endl << "Enter CD Artist Name: ";
	getline(cin, str);
	myCD.setArtist(str);


	cout << "Enter CD Album Title: ";
	getline(cin, str);
	myCD.setTitle(str);


	cout << "Enter CD Length: ";
	cin >> str;
	myCD.setLength(str);


	cin.ignore();

	cin.clear();
	char next = 'Y';
	int acc = 0;

	while (toupper(next) == 'Y')
	{
		acc++;
		cin.ignore();
		cout << "Enter song " << acc << " Title: ";
		getline(cin, str);
		myCD.setASongTitle(str);

		cout << "Enter song " << acc << " Lenth: ";
		getline(cin, str);
		myCD.setASongLength(str);
		myCD.setSongList();

		cout << "Add a new song? (Y/N): ";
		cin >> next;
	}

	cdList->appendNode(myCD);
}

// add dvd choice 2
void addDVD(Linked_List<DVD>* dvdList)
{
	DVD myDVD;
	string str;
	cin.ignore();

	cout << endl << "Enter DVD Title: ";
	getline(cin, str);
	myDVD.setTitle(str);

	cout << "Enter Length of Movie: ";
	getline(cin, str);
	myDVD.setLength(str);

	cout << "Enter Year Released: ";
	getline(cin, str);
	myDVD.setYearReleased(str);

	char in = 'Y';
	int acc = 0;

	while (toupper(in) == 'Y')
	{
		acc++;
		cin.ignore();
		cout << "Enter Actor/Actress " << acc << " Name: ";
		getline(cin, str);
		myDVD.setActorInstance(str);

		cout << "Enter Character " << acc << " Name: ";
		getline(cin, str);
		myDVD.setCharacterInstance(str);
		myDVD.setActorList();

		cout << "Is there another actor/actress? (Y/N): ";
		cin >> in;
	}

	dvdList->appendNode(myDVD);
}

// remove cd choice 3
void removeCD(Linked_List<CD>* cdList)
{
	CD myCD;
	string str;

	cdList->displayList();

	cin.ignore();
	cout << endl << "What CD would you like to remove? ";
	getline(cin, str);
	cout << endl;

	myCD.setTitle(str);

	if (cdList->searchList(myCD) == -1)
		cout << "CD does not exist in collection." << endl;
	else
		cdList->deleteNode(myCD);
}

// remove dvd choice 4
void removeDVD(Linked_List<DVD>* dvdList)
{
	DVD myDVD;
	string str;

	dvdList->displayList();

	cin.ignore();
	cout << endl << "Which DVD would you like to remove? ";
	getline(cin, str);
	cout << endl;

	myDVD.setTitle(str);

	if (dvdList->searchList(myDVD) == -1)
		cout << "DVD does not exist in collection." << endl;
	else
		dvdList->deleteNode(myDVD);
}

// update a cd choice 5
void updateCD(Linked_List<CD>* cdList)
{
	CD oldCD;
	CD newCD;
	string str;

	cdList->displayList();
	cin.ignore();
	cout << endl << "Which CD would you like to update? ";
	getline(cin, str);
	cout << endl;

	oldCD.setTitle(str);

	int choice;
	char in = 'Y';
	int acc = 0;

	if (cdList->searchList(oldCD) == -1)
		cout << "Cd does not exist in collection." << endl;
	else
	{
		oldCD = cdList->returnItem(oldCD);

		newCD.setArtist(oldCD.getArtist());
		newCD.setTitle(oldCD.getTitle());
		newCD.setLength(oldCD.getLength());
		cdList->deleteNode(oldCD);

		cout << "What would you like to update? " << endl
			<< "1. Artist" << endl
			<< "2. Album" << endl
			<< "3. Length" << endl
			<< "4. Song List" << endl
			<< "Enter 1 - 4: ";
		cin >> choice;

		if (choice == 1)
		{
			cin.ignore();
			cout << "Enter the new Artist: ";
			getline(cin, str);
			newCD.setArtist(str);
		}
		else if (choice == 2)
		{
			cin.ignore();
			cout << "Enter the new Album: ";
			getline(cin, str);
			newCD.setTitle(str);
		}
		else if (choice == 3)
		{
			cin.ignore();
			cout << "Enter the new Length: ";
			getline(cin, str);
			newCD.setLength(str);
		}
		else if (choice == 4)
		{
			cin.ignore();
			while (toupper(in) == 'Y')
			{
				acc++;
				cin.ignore();
				cout << "Enter song " << acc << " Title: ";
				getline(cin, str);
				newCD.setASongTitle(str);

				cout << "Enter song " << acc << " Length: ";
				getline(cin, str);
				newCD.setASongLength(str);
				newCD.setSongList();

				cout << "Add a new song? (Y/N): ";
				cin >> in;
			}
		}
		cdList->appendNode(newCD);
	}
}

// update a dvd choice 6
void updateDVD(Linked_List<DVD>* dvdList)
{
	DVD oldDVD;
	DVD newDVD;
	string str;

	dvdList->displayList();
	cin.ignore();
	cout << endl << "What DVD would you like to update? ";
	getline(cin, str);
	cout << endl;

	oldDVD.setTitle(str);

	int choice;
	char yn = 'Y';
	int acc = 0;

	if (dvdList->searchList(oldDVD) == -1)
		cout << "That DVD does not exist in your collection." << endl;
	else
	{
		oldDVD = dvdList->returnItem(oldDVD);

		newDVD.setTitle(oldDVD.getTitle());
		newDVD.setYearReleased(oldDVD.getYearReleased());
		newDVD.setLength(oldDVD.getLength());
		dvdList->deleteNode(oldDVD);

		cout << "What would you like to update? " << endl
			<< "1. Title" << endl
			<< "2. Length of Movie" << endl
			<< "3. Year Released" << endl
			<< "4. Actors/Actresses/Characters List" << endl
			<< "Enter 1 - 4: ";
		cin >> choice;

		if (choice == 1)
		{
			cin.ignore();
			cout << "Enter the new Title: ";
			getline(cin, str);
			newDVD.setTitle(str);
		}
		else if (choice == 2)
		{
			cin.ignore();
			cout << "Enter the new Length: ";
			cin >> str;
			newDVD.setLength(str);
		}
		else if (choice == 3)
		{
			cin.ignore();
			cout << "Enter the new Year Released: ";
			cin >> str;
			newDVD.setYearReleased(str);
		}
		else if (choice == 4)
		{
			cin.ignore();
			while (toupper(yn) == 'Y')
			{
				acc++;
				cin.ignore();
				cout << "Enter Actor/Actress " << acc << " Name: ";
				getline(cin, str);
				newDVD.setActorInstance(str);

				cout << "Enter Character " << acc << " Name: ";
				getline(cin, str);
				newDVD.setCharacterInstance(str);
				newDVD.setActorList();

				cout << "Is there another Actor/Actress? (Y/N): ";
				cin >> yn;
			}
		}
		dvdList->appendNode(newDVD);
	}
}

//  display cd in collection choice 7
void displayCDs(Linked_List<CD>* cdList)
{
	cout << endl
		<< left << setw(16) << "Artist"
		<< left << setw(16) << "CD Name"
		<< left << setw(16) << "Length of CD"
		<< left << setw(16) << "Song Title"
		<< left << setw(16) << "Song Length";
	cdList->displayList();
}

//  //display dvds in collection choice 8
void displayDVDs(Linked_List<DVD>* dvdList)
{
	cout << endl
		<< left << setw(16) << "Movie Title"
		<< left << setw(16) << "Length of Movie"
		<< left << setw(16) << "Year Released"
		<< left << setw(16) << "Actor/Actress"
		<< left << setw(16) << "Characters";
	dvdList->displayList();
}