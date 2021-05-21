#include <math.h>
#include <NTL/ZZ.h>
#include <ctime>
#include "../headers/functions.h"
//#include "./functions.cpp"
#include "../headers/receiver.h"

#include <iostream>

using namespace std;
using namespace NTL;

receiver::receiver(ZZ p_key, ZZ q_key) :
    p(p_key), q(q_key), N(p_key * q_key), fiN((p_key - 1) * (q_key - 1))
{
    srand(time(NULL));
    ZZ tempE; 
    ZZ randTemp;
    randTemp = rand() % 1000;
    tempE = 1 + moduloZZ(randTemp, fiN - 1);
    while (!isPrime(tempE) && tempE > 2)
    {
        randTemp = rand() % 1000;
        tempE = 1 + moduloZZ(randTemp, fiN - 1); //FLAG
    }
    e = tempE;
    extMcdZZ(e, fiN, d);
    d = moduloZZ(d, fiN);

    cout << "p: " << p << endl;
    cout << "q: " << q << endl;
    cout << "N: " << N << endl;
    cout << "fiN: " << fiN << endl;
    cout << "e: " << e << endl;
    cout << "d: " << d << endl;


}

ZZ receiver::decypher(ZZ mensajeCifrado)
{

    return powerZZ(mensajeCifrado, d, N);
    //return moduloZZ(powerZZ(mensajeCifrado, d), N);
}
