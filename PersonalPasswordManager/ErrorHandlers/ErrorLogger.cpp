/*
* This section of the program is under heavy development and will
* be refactored fairly soon
*/

// TODO: Fix this crap
#include "ErrorLogger.h"
#include <errno.h>
#include <iostream>
#include <filesystem>
#include <experimental/filesystem>



#include <winrt/base.h>
#include <winrt/Windows.Foundation.h>
#include <winrt/Windows.Foundation.Collections.h>
#include <winrt/Windows.Foundation.Diagnostics.h>
#include <winrt/Windows.UI.Xaml.Interop.h>

using std::cerr;
using std::endl;


ErrorLogger::ErrorLogger()
{
	memset(LoggerSavePath, 0, sizeof(LoggerSavePath));
	logfp = NULL;
}

ErrorLogger::~ErrorLogger()
{
	memset(LoggerSavePath, 0, sizeof(LoggerSavePath));
	if (logfp)
		fclose(logfp);
	logfp = NULL;
}

// Incomplete
void ErrorLogger::CheckLogPath()
{
	char		logPath[LOGPATHSZ + 1];
	int			sz = 0;
	struct stat st;

	memset(logPath, 0, sizeof(logPath));

	// Get current working directory
	if (!getcwd(logPath, LOGPATHSZ))
	{
		HandleError(errno);
		cerr << "Failed to get current working directory, " << endl;
		cerr << "Returning from the function." << endl;
		cerr << "Event has been logged!" << endl;
		system("pause");
		return;
	}

	// Check if the cwd path and the dir name fit in array size
	sz = strlen(ERRORDIR) + strlen(logPath);
	if (sz <= LOGPATHSZ)
		strcat(logPath, ERRORDIR);				// Concat dir name to path

#if defined(WIN32) || defined(_WIN32)
	
	// Check if dir exists
	if (stat(logPath, &st) == -1)
		mkdir(logPath);

#elif defined(UNIX) || defined(__unix__) || defined(__linux__) || defined(LINUX)
c
	cerr << "This has not been implemented for linux. Force exiting!" << endl;
	cerr << "Internal failure!!!" << endl;
	system("pause");
	exit(EXIT_FAILURE);

#endif

	// Check if full path fits in logPath array
	sz = strlen(ERRORPATH) + strlen(logPath);
	if (sz <= LOGPATHSZ)
		strcat(logPath, ERRORPATH);
	else
	{
		cerr << "Unable to concat error path to logPath string!" << endl;
		cerr << "FATAL ERROR!" << endl;
		system("pause");
		exit(EXIT_FAILURE);
	}

	if(stat(logPath, &st) == -1)




}


void ErrorLogger::HandleError(int err)
{
	cerr << "Error No. : " << errno << endl;
	cerr << "Description: " << strerror(errno) << endl;
}





