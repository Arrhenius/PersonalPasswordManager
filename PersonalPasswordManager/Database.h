#ifndef DATABASE_H
#define DATABASE_H


#include <vector>
#include "Data.h"
#include "FileSystem.h"

using std::vector;

class Database : public FileSystem
{
public:
	Database();
	~Database();
	void	addToDatabase(Data data);
	void	printDatabase();
	//void	checkForSave();

private:
	int				sz;
	vector<Data>	DataList;

};


#endif
