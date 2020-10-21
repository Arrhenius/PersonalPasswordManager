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

	system("cls");
	

}


