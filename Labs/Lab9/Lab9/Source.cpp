#include "RSA.h"

int main()
{
	RSA rsa(13, 77); // 13 is the value of e and 77 is value of n
	rsa.crypt("plainFile", "cipherFile"); 
	return 0;
}
