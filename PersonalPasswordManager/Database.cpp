#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <Windows.h>
#include "Database.h"


using std::vector;
using std::cout;
using std::endl;



Database::Database()
{
	memset(this, 0, sizeof(this));
	checkForSave();
}

Database::~Database()
{
	memset(this, 0, sizeof(this));
}


void Database::addToDatabase(Data data)
{
	DataList.push_back(data);
}

void Database::printDatabase()
{
	unsigned int i;

	for (i = 0; i < DataList.size(); i++)
	{
		cout	<< "Login contents: \n" << endl
				<< "Website:	" << DataList[i].getWebSite() << endl
				<< "Login:		" << DataList[i].getLogin() << endl
				<< "Key:		" << DataList[i].getKey() << endl;
	}

}

#if 0
void Database::checkForSave()
{
	//Check to see if directory exists

	//If directory does not exist do this

	//If directory does exist do this
}

#endif