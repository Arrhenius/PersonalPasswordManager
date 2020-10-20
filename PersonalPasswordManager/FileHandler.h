#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <stdio.h>
#include <string.h>


#define MAXFILEPATH	256

class FileHandler
{
public:
	FileHandler();
	~FileHandler();
	checkForSave(char* path);
private:
	FILE* fh;
	char	fileHandlerPath[MAXFILEPATH + 1];
};


#endif // FILEHANDLER_H
