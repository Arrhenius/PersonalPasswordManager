#include <Windows.h>
#include <stdio.h>
#include <iostream>
#include "Hash.h"
#include "help_func.h"

using std::cout;
using std::endl;


// Hash constructor
Hash::Hash(const char* pszKey)
{
	if (*pszKey == '\0' || *pszKey == '\n')
	{
		cout << "Unable to create a Hash object. Input key invalid!" << endl;
		exit(EXIT_FAILURE);
	}
	//Acquire the cryptographic provider context handle.
	if (!CryptAcquireContext(&hCryptProv, NULL, NULL, PROV_RSA_AES, 0))
	{
		cout << "CryptAcquireContext() failed! Terminating!" << endl;
		cout << "\tError code: " << GetLastError() << endl;
		exit(EXIT_FAILURE);
	}

	if (!CryptCreateHash(hCryptProv, CALG_SHA_512, 0, 0, &hHashKey))
	{
		cout << "CryptCreateHash() failed! Terminating!" << endl;
		cout << "\tError code: " << GetLastError() << endl;
		exit(EXIT_FAILURE);
	}

	if (!CryptHashData(hHashKey, (BYTE*)pszKey, sizeof(pszKey),	0))
	{
		cout << "CryptHashData() failed! Terminating!" << endl;
		cout << "\tError code: " << GetLastError() << endl;
		exit(EXIT_FAILURE);
	}
}


// Hash deconstructor
Hash::~Hash()
{
	if (CryptDestroyHash(hHashKey))
		cout << "Key destroyed" << endl;
	else
		cout << "Failed to destroy key" << endl;

	if (hCryptProv)
		CryptReleaseContext(hCryptProv, 0);
}






//void Hash::HashPrint(HCRYPTHASH hOriginalHash)
void Hash::HashPrint()
{
	HCRYPTHASH	hHash;
	BYTE*		pbHash;
	DWORD		dwHashLen;
	DWORD		dwHashLenSize = sizeof(DWORD);
	DWORD		i;


	if (!CryptDuplicateHash(hHashKey, NULL, 0, &hHash))
		errExit("CryptDuplicateHash failed!", __FILE__, __LINE__);

	if (!CryptGetHashParam(hHash, HP_HASHSIZE, (BYTE*)&dwHashLen, &dwHashLenSize, 0))
		errExit("CryptGetHashParam failed!", __FILE__, __LINE__);

	if (!(pbHash = (BYTE*)malloc(dwHashLen)))
		errExit("pbHash malloc failed. Terminating.", __FILE__, __LINE__);


	if (CryptGetHashParam(hHash, HP_HASHVAL, pbHash, &dwHashLen, 0))
	{
		for (i = 0; i < dwHashLen; i++)
			printf("%x", pbHash[i]);
		printf("\n");
	}

	free(pbHash);
	if (!CryptDestroyHash(hHash))
		errExit("CryptDestroyHash failed! Terminating...", __FILE__, __LINE__);
}


void Hash::hashValue(HCRYPTHASH hKey, BYTE** pbHash, DWORD dwHashLen)
{
	if (!CryptGetHashParam(hKey, HP_HASHVAL, (*pbHash), &dwHashLen, 0))
	{
		cout << "Failed to obtain hash value!" << endl;
		cout << "Internal error! Terminating program!" << endl;
	}
}

bool Hash::HashCompare(HCRYPTHASH hKey, HCRYPTHASH hOriginalHash)
{
	HCRYPTHASH	hHash;
	BYTE*		pbHash;
	BYTE*		pbKey;
	DWORD		dwHashKeyLen;
	DWORD		dwOriginalKeyLen;
	DWORD		dwHashLenSize = sizeof(DWORD);
	DWORD		i;

	if (CryptGetHashParam(hKey, HP_HASHSIZE, (BYTE*)&pbKey, &dwHashKeyLen, 0) &&
		CryptGetHashParam(hOriginalHash, HP_HASHSIZE, (BYTE*)&pbHash, &dwOriginalKeyLen, 0) )
	{
		if (dwHashKeyLen == dwOriginalKeyLen)
		{
			hashValue(hKey, &pbKey, dwHashKeyLen);
			hashValue(hOriginalHash, &pbHash, dwOriginalKeyLen);
			for (int i = 0; i < dwHashKeyLen; i++)
			{
				if (pbKey[i] != pbHash[i])
				{
					cout << "Keys do not match! Data does not match!" << endl;
					return false;
				}
			}
		}
		else
			return false;
	}
		
}


