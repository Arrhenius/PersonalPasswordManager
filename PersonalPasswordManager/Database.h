#ifndef DATABASE_H
#define DATABASE_H


#include <vector>
#include "Data.h"


using std::vector;

class Database
{
public:
	Database();
	~Database();
	void	addToDatabase(Data data);
	void	printDatabase();

private:
	int				sz;
	vector<Data>	DataList;
};


#endif
