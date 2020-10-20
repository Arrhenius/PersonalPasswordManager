#ifndef ERRORLOGGER_H
#define ERRORLOGGER_H

#include <errno.h>
#include <stdio.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>

#define LOGPATHSZ		512


#if defined(WIN32) || defined(_WIN32)

#define ERRORPATH	"\\Error.log"
#define ERRORDIR	"\\Log"

// Windows headers
#include <direct.h>
#include <Windows.h>
#include <io.h>

#elif defined(UNIX) || defined(__unix__) || defined(__linux__) || defined(LINUX)

#define ERRORPATH	"/Error.log"
#define ERRORDIR	"/Log"

// Linux headers
#include <dirent.h>
#include <unistd.h>

#endif

class ErrorLogger
{
public:
	ErrorLogger();
	~ErrorLogger();
	void		CheckLogPath();
	void		WriteToLog();
	void		HandleError(int err);
private:
	char		LoggerSavePath[LOGPATHSZ + 1];
	FILE*		logfp;
};



#endif //ERRORLOGGER_H
