#include <NTL/ZZ.h>

using namespace NTL;

class source
{
    public:
        ZZ publicKey;
        ZZ N;
        source (ZZ, ZZ);
        ZZ cypher (ZZ);
};
