#include <stdio.h>
#include <stdlib.h>
#include <Windows.h>
#include "Database.h"
#include "help_func.h"
#include <windows.security.cryptography.h>




int main(int nargs, char *argv[])
{
	Database*		db = new Database();
	Data			data;
	unsigned int	i;
	char			buffer[1024];
	
	

	


	for (i = 0; i < 4; i++)
	{
		printf("Enter a website: ");
		fgets(buffer, 128, stdin);
		handleString(buffer, __FILE__, __LINE__);
		data.setWebSite(buffer);


		printf("Enter a login: ");
		fgets(buffer, MAXLOGINSZ, stdin);
		handleString(buffer, __FILE__, __LINE__);
		data.setLogin(buffer);

		printf("Enter a key: ");
		fgets(buffer, MAXKEYSZ, stdin);
		handleString(buffer, __FILE__, __LINE__);
		data.setKey(buffer);

		db->addToDatabase(data);
	}

	db->printDatabase();

	system("pause");
	db->~Database();

	return EXIT_SUCCESS;
}