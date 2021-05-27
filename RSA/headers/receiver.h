#include <NTL/ZZ.h>
#include <string>

using namespace NTL;
using std::string;

class receiver
{
    private:
        ZZ p, q, fiN, d;
        string alphabet;
    public:
        ZZ e, N;
        receiver (int, string);
        string decypher (string);
};
