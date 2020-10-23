#include <stdio.h>
#include <stdlib.h>
#include <vector>
#include <iostream>
#include <sstream>
#include <Windows.h>
#include "Database.h"


Database::Database()
{
	memset(this, 0, sizeof(this));
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
	using std::cout;
	using std::endl;

	unsigned int i;
	for (i = 0; i < DataList.size(); i++)
	{
		cout	<< "Login contents: \n" << endl
				<< "Website:	" << DataList[i].getWebSite() << endl
				<< "Login:		" << DataList[i].getLogin() << endl
				<< "Key:		" << DataList[i].getKey() << endl;
	}
}