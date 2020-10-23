#include <stdio.h>
#include <stdlib.h>


int sreplace(char old, char n, char* buffer)
{
	int count = 0;

	if (*buffer)
	{
		while (*buffer)
		{
			if (*buffer == old)
			{
				*buffer = n;
				count++;
			}
			buffer++;
		}
	}
	return count;
}

void errExit(const char* errmsg, const char* fileName, int lineNumber)
{
	fprintf(stderr, "%s! \n\tFile: %s \n\tLine: %d\n", errmsg, fileName, lineNumber);
	system("pause");
	exit(EXIT_FAILURE);
}

void handleString(char* buffer, const char* fileName, int lineNumber)
{
	if (*buffer)
	{
		if (!sreplace('\n', '\0', buffer))
			errExit("Buffer overflow!", fileName, lineNumber);
		return;
	}
	errExit("function handleString failed to execute on provided string!",
		fileName, lineNumber);

}