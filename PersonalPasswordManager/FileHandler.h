#ifndef FILEHANDLER_H
#define FILEHANDLER_H

#include <stdio.h>
#include <string.h>

#define MAXFILENAME	32
#define MAXFILEPATH	512

#define TYPE_BIN		700
#define TYPE_TEXT		701
#define TYPE_LOG		702
#define TYPE_BINSAVE	703	


class FileHandler
{
public:
	FileHandler(int type);
	~FileHandler();
	void	BinOpen(const char* pszPath);
	void	BinRead();
	void	BinAppendWrite();
	void	TextRead();
	void	TextWrite();
	void	CloseFile();
	//checkForSave(char* path);
private:
	int	fileType;
	int	fd;
	char	fileName[MAXFILENAME + 1];
	char	fileHandlerPath[MAXFILEPATH + 1];
	FILE* fh;
};


#endif // FILEHANDLER_H
