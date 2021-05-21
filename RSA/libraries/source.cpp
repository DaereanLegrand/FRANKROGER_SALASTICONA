#include <math.h>
#include <NTL/ZZ.h>
#include "../headers/source.h"
#include "../headers/functions.h"

source::source(ZZ userPublic, ZZ uN) :
    publicKey(userPublic), N(uN)
{

}

ZZ source::cypher(ZZ mensaje)
{
    //return moduloZZ(powerZZ(mensaje, publicKey), N);
    return powerZZ(mensaje, publicKey, N);
}
