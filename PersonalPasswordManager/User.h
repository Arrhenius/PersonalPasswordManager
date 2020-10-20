#ifndef USER_H
#define USER_H



#define MAXNAMESZ	32
#define MAXPWSZ	512

#include "Database.h"
#include "Hash.h"

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
	char	firstName[MAXNAMESZ + 1];
	char	lastName[MAXNAMESZ + 1];
	Hash*	usernameHash;
	Hash*	passwordHash;
	
};

#if 0
class User
{
public:
	User();
	~User();
	void	setFirstName(const char* first);
	void	setLastName(const char* last);
	void	setUsername(const char* user);
	void	setPassword(const char* pass);
	void	initiateDatabase();
private:
	char			firstName[MAXNAMESZ + 1];
	char			lastName[MAXNAMESZ + 1];
	char			username[MAXNAMESZ + 1];
	char			password[MAXPWSZ + 1];
	Database*	db;
};
#endif

#endif // USER_H
