#ifndef HELP_FUNC_H
#define HELP_FUNC_H

#define MAXWEBSZ		128
#define MAXLOGINSZ		64
#define MAXKEYSZ		512


int		sreplace(char old, char n, char* buffer);
void	errExit(const char* errmsg, const char* fileName, int lineNumber);
void	handleString(char* buffer, const char* fileName, int lineNumber);



#endif // HELP_FUNC_H
