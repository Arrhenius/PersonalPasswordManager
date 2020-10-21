#ifndef USER_H
#define USER_H

#define MAXNAMESZ	64
#define MAXPWSZ 512

#include "Hash.h"
#include "Database.h"

class User
{
public:
	User();
	~User();
	void	setFirstName(const char* first);
	void	setLastName(const char* last);
	void	setUsername(const char* user);
	void	setPassword(const char* pass);

private:
	char			firstName[MAXNAMESZ + 1];
	char			lastName[MAXNAMESZ + 1];
	Hash*			usernameHash;
	Hash*			passwordHash;
	Database*	db;
};
#endif // USER_H
