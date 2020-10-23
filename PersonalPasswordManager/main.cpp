/*
 * Program:	Personal Password Manager
 * Author:	Abel Atkinson
 * Date:	10/21/2020
 * Github:	github.com/arrhenius
 */


#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "Database.h"
#include "help_func.h"
#include "Display.h"
#include <windows.security.cryptography.h>



 // TODO: Create Login Menu
 // TODO: Create Save handler
 // TODO: Create File Handlers

 // Currently working on the file handling system
 // to perform a CheckSave() function call to load
 // the database in the correct location


int main(int nargs, char* argv[])
{

	Display* Window = new Display();


	while (1)
	{
		Window->DisplayMenu(LOGIN_MENU);
	}






	return EXIT_SUCCESS;
}