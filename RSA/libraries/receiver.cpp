#include <math.h>
#include <string>
#include <NTL/ZZ.h>
#include <ctime>
#include "../headers/functions.h"
//#include "./functions.cpp"
#include "../headers/receiver.h"

#include <iostream>

using std::string;
using namespace NTL;

receiver::receiver(int nBits, string uAlphabet) :
    alphabet(uAlphabet)
{
    p = RandomPrime_ZZ(nBits);
    q = RandomPrime_ZZ(nBits);
    N = p * q;
    fiN = (p - 1) * (q - 1);
    e = RandomBnd(fiN - 1) + 1;
    while (mcdZZ(e, fiN) != 1)
    {
        e = RandomBnd(fiN - 1) + 1;
    }
    d = moduloZZ(inversa(e, fiN), fiN);

    std::cout << "p: " << p << std::endl;
    std::cout << "q: " << q << std::endl;
    std::cout << "N: " << N << std::endl;
    std::cout << "fiN: " << fiN << std::endl;
    std::cout << "e: " << e << std::endl;
    std::cout << "d: " << d << std::endl;
}

string receiver::decypher(string message)
{
    string toReturn;
    int availableDigits = std::to_string((int)alphabet.length()).length();
    int nDigits = (int)zToString(N).length();
    vector<string> temp = stringToVector(message, nDigits);
    vector<string> tempDecypher;
    for (vector<string>::iterator i = temp.begin(); i != temp.end(); i++)
    {
        string temp1 = *i;
        ZZ zTemp(INIT_VAL, temp1.c_str());
        temp1 = zToString(powerZZ(zTemp, d, N));
        tempDecypher.push_back(string((nDigits - 1) - (int)temp1.length(), '0') + temp1);
    }
    temp = stringToVector(vectorToString(tempDecypher), availableDigits);
    for (vector<string>::iterator i = temp.begin(); i != temp.end(); i++)
    {
        string temp1 = *i;
        int iTemp = std::stoi(temp1);
        toReturn.append(alphabet, iTemp, 1);
    }
    return toReturn;
}
