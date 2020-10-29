#include "FileHandler.h"
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <limits.h>

#if defined(UNIX) || defined(__unix__) || defined(__linux__) || defined(LINUX)
#include <unistd.h>
#define OS_LINUX
#define OPEN(path)	open(path, O_CREAT | O_RDWR, S_IRWXU)

#endif


#if defined(WIN32) || defined(_WIN32)
#include <io.h>
#include <Windows.h>
#define OS_WINDOWS
#define O_CREAT		_O_CREAT
#define O_RDWR		_O_RDWR
#define OPEN(path)	open(path, O_CREAT | O_RDWR, S_IREAD | S_IWRITE)

#endif


/*
 * Date: 10/23/20
 * NOTE:
 * In the process of making this windows application compatible with linux
 * in the close future I will probably make dumb/odd decisions with what
 * is implemented and what isn't, up until I design something to be more 
 * aligned with a decently designed windows/linux application.
 * For now anything that I attempt to create a linux solution for will
 * be simply because I remembered I can do this or that...sorry
 */
FileHandler::FileHandler(int type)
{
	fh			= NULL;
	fd			= 0;
	fileType	= type;
	memset(fileName, 0, sizeof(fileName));
	memset(fileHandlerPath, 0, sizeof(fileHandlerPath));
}



FileHandler::~FileHandler()
{
	CloseFile();
	fileType = 0;
	memset(this, 0, sizeof(this));
}

/*
* Windows:
		_S_IREAD | _S_IWRITE	Reading and writing permitted.

   Linux: 
		S_IRWXU					user has read/write/execute perms
		S_IRUSR					00400 user has read permission
		S_IWUSR					00200 user has write permission
*/
void FileHandler::BinOpen(const char* pszPath)
{
	using std::endl;
	using std::cerr;
	if (fileType == TYPE_BIN)
	{
		fd = OPEN(pszPath);
		if (fd == -1)
		{
			// TODO: Add to error log function
			cerr << "Error: "		<< strerror(errno)	<< endl;
			cerr << "File: "		<< __FILE__			<< endl;
			cerr << "Function: "	<< __FUNCTION__		<< endl;
			cerr << "\tLine: "		<< __LINE__			<< endl;
		}
	}
}

void FileHandler::Write(void* data, size_t sz)
{
	using std::cerr;
	using std::endl;

	size_t res = 0;
	if( fd > 0 )
		res = write(fd, data, sz);
	else
	{
		cerr << "Invalid file descriptor passed! " << endl;
		cerr << "Write failed. Returning. " << endl;
		return;
	}

	if ( res == -1 )
	{
		cerr << "Error: " << strerror(errno) << endl;
		cerr << "Exiting function." << endl;
		return;
	}
	
}


void FileHandler::BinRead(void* data)
{
	if (fileType == TYPE_BIN)
	{

	}
}

void FileHandler::BinAppendWrite()
{
	if (fileType == TYPE_BIN)
	{

	}
}

// This function will be using fgets()
void FileHandler::TextRead()
{
	if (fileType == TYPE_TEXT)
	{

	}
}

// This function will be using fprintf()
void FileHandler::TextWrite()
{
	if (fileType == TYPE_TEXT)
	{

	}
}


void FileHandler::CloseFile()
{
	if (fd > 0)
		close(fd);
	if (fh)
		fclose(fh);
}