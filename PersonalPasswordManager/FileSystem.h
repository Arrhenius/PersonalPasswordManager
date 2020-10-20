#ifndef FILESYSTEM_H
#define FILESYSTEM_H


#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define MAXBUF	260
#define FOPEN	100
#define OPEN	101

#if defined(WIN32) || defined(_WIN32)

#define SAVEPATH	"\\Db.dat"
#define SAVEDIR	"\\Data"

// Windows headers
#include <direct.h>
#include <Windows.h>
#include <io.h>

#elif defined(UNIX) || defined(__unix__) || defined(__linux__) || defined(LINUX)

#define SAVEPATH	"/Db.dat"
#define SAVEDIR	"/Data"

// Linux headers
#include <dirent.h>
#include <unistd.h>

#endif


class FileSystem
{
public:
	FileSystem();
	~FileSystem();
	int		SetMode(const char* path, int mask);
	void		checkForSave();
	bool		DoesPathExist(const char* path);
	bool		OpenFile(const char* fileName, int option);
private:
	int		fd;
	int		fileStatus;
	int		saveCheck;
	char		fileSavePath[MAXBUF + 1];
	FILE*		pFile;

};



#endif // FILESYSTEM_H
