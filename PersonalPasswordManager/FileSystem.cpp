#include "FileSystem.h"



FileSystem::FileSystem()
{
	fd			= 0;
	fileStatus	= 0;
	saveCheck	= 0;
	memset(fileSavePath, 0, sizeof(fileSavePath));
	pFile = NULL;
}


FileSystem::~FileSystem()
{
	fileStatus	= 0;
	saveCheck	= 0;
	if (pFile)
		fclose(pFile);
	if (fd > 0)
		close(fd);
	memset(fileSavePath, 0, sizeof(fileSavePath));
}

bool FileSystem::OpenFile(const char* fileName, int option)
{
	if (*fileName)
	{
		switch (option)
		{
		case FOPEN:
		case OPEN:
			fd = open(fileName, O_RDWR);
			if (fd > 0)
				return true;
			else if (fd < 0)
				return false;
		default:
			fprintf(stderr, "Failed to open file\n");
			return false;
		}
	}
	else
	{
		fprintf(stderr, "Failed to enter a valid fileName to open\n");
		return false;
	}
}

//Incomplete
bool FileSystem::DoesPathExist(const char* path)
{
	struct stat st;
	int			status;
	if (*path)
	{
		status = stat(path, &st);
		if (status == -1)
		{
			switch (errno)
			{
			case ENOENT:
				fprintf(stderr, "Path does not exist!\n");
				break;
			case EACCES:
				fprintf(stderr, "Search permission is denied!\n");
				break;
			case ENAMETOOLONG:
				fprintf(stderr, "FIle name too long!\n");
				break;
			default:
				fprintf(stderr, "An unknown error occurred! Program terminating!\n");
				system("pause");
				exit(EXIT_FAILURE);
			}
		}
		else
		{
			//if(st.st_mode & S_IFDIR)
		}
	}
	else
		return false;
}

int FileSystem::SetMode(const char* path, int mask)
{
	if (*path)
	{
		if (chmod(path, mask) == -1)
		{
			switch (errno)
			{
			case EINVAL:
				fprintf(stderr, "Invalid parameter to chmod.\n");
				break;
			case ENOENT:
				fprintf(stderr, "File %s not found\n", path);
				break;
			default:
				fprintf(stderr, "Unexected error when executing chmod.\n");
				system("pause");
				return 1;
			}
		}
	}
	else
	{
		fprintf(stderr, "Invalid path entered\n");
		return 1;
	}
	return 0;
}


void FileSyystem::getCurrentPath(char* path)
{

}

void FileSystem::checkForSave()
{
	char		savePath[MAXBUF + 1];
	int			ret = 0;
	int			sz = 0;
	struct stat st;

	memset(savePath, 0, sizeof(savePath));

	// Get the current working directory
	if (!getcwd(savePath, MAXBUF))
	{
		fprintf(stderr, "Failed to get current directory!");
		return;
	}
	
	// Check if the cwd path and the dir name fit in array size
	sz = strlen(SAVEDIR) + strlen(savePath);
	if (sz <= MAXBUF)
		strcat(savePath, SAVEDIR);		// concat dir name to path


#if defined(WIN32) || defined(_WIN32)

	// Check if dir exists
	if(stat(savePath, &st) == -1)
		mkdir(savePath);

#elif defined(UNIX) || defined(__unix__) || defined(__linux__) || defined (LINUX)

	if (stat(savePath, &st) == -1)
		mkdir(savePath, 0700);

#endif

	// Set permissions to read and write for directory
	SetMode(savePath, S_IWRITE);

	// check if full path fits in savePath array
	sz = strlen(SAVEPATH) + strlen(savePath);
	if (sz <= MAXBUF)
		strcat(savePath, SAVEPATH);
	else
	{
		fprintf(stderr, "Unable to concat data file name to path! Buffer overflow!\n");
		return;
	}

	if(stat(savePath, &st) == -1)




	 
}





