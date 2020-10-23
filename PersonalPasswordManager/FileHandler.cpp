#include "FileHandler.h"
#include <stdio.h>
#include <Windows.h>
#include <io.h>
#include <fcntl.h>

#if defined(UNIX) || defined(__unix__) || defined(__linux__) || defined(LINUX)
#include <unistd.h>

#endif


#if defined(WIN32) || defined(_WIN32)
#define O_CREAT	_O_CREAT
#define O_RDWR	_O_RDWR

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


void FileHandler::BinOpen(const char* pszPath)
{
	if (fileType == TYPE_BIN)
	{
		fd = open(pszPath, O_CREAT)
	}
}


void FileHandler::BinRead()
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


void FileHandler::TextRead()
{
	if (fileType == TYPE_TEXT)
	{

	}
}

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