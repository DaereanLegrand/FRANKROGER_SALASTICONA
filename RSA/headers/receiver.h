#include <NTL/ZZ.h>
#include <string>

using namespace NTL;

class receiver
{
    private:
        ZZ p, q, fiN, d;
        std::string alphabet;
    public:
        ZZ e, N;
        receiver (ZZ, ZZ);
        ZZ decypher (ZZ);
};
