#include "FileHandler.h"


FileHandler::FileHandler()
{
	fh = NULL;
	memset(fileHandlerPath, 0, sizeof(fileHandlerPath));
}

FileHandler::~FileHandler()
{
	if (fh)
		fclose(fh);
	memset(fileHandlerPath, 0, sizeof(fileHandlerPath));
}

