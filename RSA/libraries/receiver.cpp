#pragma once
#include <math.h>
#include "../headers/functions.h"
#include "../headers/receiver.h"

using namespace std;

receiver::receiver(int p_key, int q_key) :
    p(p_key), q(q_key), N(p_key * q_key), fiN((p_key - 1) * (q_key - 1))
{
    int tempE = 1 + (rand() / (fiN - 1));
    while (!isPrime(tempE))
    {
        tempE = 1 + (rand() / (fiN - 1)); //FLAG
    }
    e = tempE;
    extMcd(e, fiN, d);
    d = mcd(d, fiN);
}

int receiver::decypher(int mensajeCifrado)
{
    return mcd(pow(mensajeCifrado, d), N);
}
