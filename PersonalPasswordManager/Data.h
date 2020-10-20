#ifndef DATA_H
#define DATA_H


class Data
{
public:
	Data();
	~Data();
	void		setWebSite(const char* ws);
	void		setLogin(const char* login);
	void		setKey(const char* key);
	char*		getWebSite();
	char*		getLogin();
	char*		getKey();
private:
	char		pszWebSite[128];
	char		pszLogin[64];
	char		pszKey[512];
};


#endif // DATA_H
