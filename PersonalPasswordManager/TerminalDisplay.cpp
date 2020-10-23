#include <iostream>
#include "Display.h"
#include "Hash.h"



Display::Display()
{
	userLoginName	= NULL;
	userLoginKey	= NULL;
	
}

Display::~Display()
{
	userLoginName->~Hash();
	userLoginKey->~Hash();
}



void Display::SetUserHash(const char* pszUserName)
{
	userLoginName = new Hash(pszUserName);
}

void Display::SetKeyHash(const char* pszUserKey)
{
	userLoginKey = new Hash(pszUserKey);
}

void Display::DisplayMenu(int menu)
{
	using std::cerr;
	using std::endl;
	switch (menu)
	{
	case LOGIN_MENU:
		LoginMenu();
		break;
	default:
		cerr << "Invalid Menu choice!" << endl;
		break;
	}
}

void Display::LoginMenu()
{
	using std::cerr;
	using std::cout;
	using std::endl;

	
	char username[MAXNAMESZ + 1];
	char password[MAXPWSZ + 1];

	// Will clear these variables twice in the function.
	// One before to zero out the memory and the second
	// to make sure entered information is destroyed once 
	// used
	memset(username, 0, sizeof(username));
	memset(password, 0, sizeof(password));

	system("cls");

	
	printf("Username: ");
	fgets(username, MAXNAMESZ, stdin);
	printf("Password: ");
	fgets(password, MAXPWSZ, stdin);


	SetUserHash(username);
	SetKeyHash(password);
	memset(username, 0, sizeof(username));
	memset(password, 0, sizeof(password));
	if (userLoginName && userLoginKey)
	{
		CheckSave();
	}
	

}


