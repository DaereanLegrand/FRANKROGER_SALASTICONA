#include <NTL/ZZ.h>

using namespace NTL;

ZZ extMcdZZ(ZZ, ZZ, ZZ&);
ZZ mcdZZ(ZZ, ZZ);
ZZ moduloZZ(ZZ, ZZ);
ZZ powerZZ(ZZ, ZZ, ZZ);
ZZ getPrime(ZZ = conv<ZZ>("0"));
bool isPrime(ZZ);
