#ifndef _CRT_SECURE_NO_WARNINGS
#define _CRT_SECURE_NO_WARNINGS
#endif


#include "User.h"



User::User()
{
	memset(this, 0, sizeof(this));
}

User::~User()
{
	memset(this, 0, sizeof(this));
}


void User::setFirstName(const char* first)
{
	if (*first)
		strcpy(firstName, first);
	else
		firstName[0] = '\0';
}

void User::setLastName(const char* last)
{
	if (*last)
		strcpy(lastName, last);
	else
		lastName[0] = '\0';
}


void User::setUsername(const char* user)
{
	if (*user)
		usernameHash = new Hash(user);
	else
		usernameHash = NULL;
}

void User::setPassword(const char* pass)
{
	if (*pass)
		passwordHash = new Hash(pass);
	else
		passwordHash = NULL;
}


#if 0
void User::setUsername(const char* user)
{
	if (*user)
		strcpy(username, user);
	else
		username[0] = '\0';
}

void User::setPassword(const char* pass)
{
	if (*pass)
		strcpy(password, pass);
	else
		password[0] = '\0';
}



void User::initiateDatabase()
{
	db = new Database();
}

#endif