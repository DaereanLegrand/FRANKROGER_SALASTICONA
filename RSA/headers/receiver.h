#include <NTL/ZZ.h>

using namespace NTL;

class receiver
{
    private:
        ZZ p, q, fiN, d;
    public:
        ZZ e, N;
        receiver (ZZ, ZZ);
        ZZ decypher (ZZ);
};
