#include <NTL/ZZ.h>
#include <string>
#include <vector>

using namespace NTL;
using std::vector;
using std::string;

vector<ZZ> extMcdZZ(ZZ, ZZ);
ZZ inversa(ZZ, ZZ);
ZZ mcdZZ(ZZ, ZZ);
ZZ moduloZZ(ZZ, ZZ);
ZZ powerZZ(ZZ, ZZ, ZZ);
ZZ getPrime(ZZ = conv<ZZ>("0"));
bool isPrime(ZZ);
string zToString(ZZ);
vector <string> stringToVector(string, int);
vector <string> stringToVectorIndex(string, int, string);
string vectorToString(vector <string>);

