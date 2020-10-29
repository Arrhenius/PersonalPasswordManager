#ifndef DISPLAY_H
#define DISPLAY_H

/*
 * This header file will be used for two files. 
 * TerminalDisplay.cpp and GUIDisplay.cpp
 * will be the two files that use it. The class 
 * itself stays the same but is meant to be used
 * for whichever menu happens to load
 */


//#include "Hash.h"
#include "../User.h"
#include "../FileSystem/FileSystem.h"

#define LOGIN_MENU	100

class Display
{
public:
	Display();
	~Display();
	void	SetUserHash(const char* pszUserName);
	void	SetKeyHash(const char* pszUserKey);
	void	DisplayMenu(int menu);
	void	LoginMenu();
	void	CheckSaves();
	
private:
	FileSystem* fileSystem;
	Hash*		userLoginName;
	Hash*		userLoginKey;
	User*		userID;
	
};



#endif // LOGINMENU_H
