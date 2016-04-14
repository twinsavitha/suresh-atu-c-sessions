const int SHM_SIZE = 1024;

key_t KEY_SHM = 9999;

struct sharedMemBlock
{
	bool bAccess;
	char chText[SHM_SIZE];
};
