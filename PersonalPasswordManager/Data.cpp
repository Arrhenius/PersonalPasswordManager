#define _CRT_SECURE_NO_WARNINGS 1


#include "Data.h"
#include <string.h>




Data::Data()
{
	memset(this, 0, sizeof(this));
}

Data::~Data()
{
	memset(this, 0, sizeof(this));
}


void Data::setWebSite(const char* ws)
{
	if (*ws)
		strcpy(pszWebSite, ws);
	else
		*pszWebSite = '\0';
}

void Data::setLogin(const char* login)
{
	if (*login)
		strcpy(pszLogin, login);
	else
		*pszLogin = '\0';
}

void Data::setKey(const char* key)
{
	if (*key)
		strcpy(pszKey, key);
	else
		*pszKey = '\0';
}

char* Data::getWebSite()
{
	return pszWebSite;
}

char* Data::getLogin()
{
	return pszLogin;
}

char* Data::getKey()
{
	return pszKey;
}
