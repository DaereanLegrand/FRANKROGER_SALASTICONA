#include <NTL/ZZ.h>
#include <string>
#include <vector>

using namespace NTL;
using std::string;
using std::vector;

class source
{
    private:
        string alphabet;
    public:
        ZZ publicKey;
        ZZ N;
        source (ZZ, ZZ, string);
        ZZ cypherZZ (ZZ);
        vector <string> stringDivider(string, int);
        string converter (vector <string>);
        string cypher(string);
};
