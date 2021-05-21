#pragma once
#include <math.h>
#include "../headers/source.h"
#include "../headers/functions.h"

source::source(int userPublic, int uN) :
    publicKey(userPublic), N(uN)
{

}

int source::cypher(int mensaje)
{
    return mcd(pow(mensaje, publicKey), N);
}
