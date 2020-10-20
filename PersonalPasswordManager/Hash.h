#ifndef HASH_H
#define HASH_H

#include <windows.security.cryptography.h>

class Hash
{
public:
	Hash(const char* pszKey);
	~Hash();
	void		GenerateHash(char* input);
	//void		HashPrint(HCRYPTHASH hOriginalHash);
	void		HashPrint();
	bool		HashCompare(HCRYPTHASH hKey, HCRYPTHASH hOriginalHash);
	void		hashValue(HCRYPTHASH hKey, BYTE** pbHash, DWORD dwHashLen);


private:
	HCRYPTPROV	hCryptProv;
	HCRYPTHASH	hHashKey;
};


#endif // HASH_H
