#include "../headers/functions.h"
#include <NTL/ZZ.h>
#include <ctime>
#include <cstdlib>
#include <sstream>
#include <string>
#include <vector>

using namespace NTL;

std::vector<ZZ> extMcdZZ(ZZ a, ZZ b)
{
    std::vector<ZZ> temp;
    ZZ q = a / b;
    ZZ res = a - (q * b);

    ZZ s1;
    s1 = 1;
    ZZ s2;
    s2 = 0;
    ZZ s = s1 - (q * s2);

    ZZ t1;
    t1 = 0;
    ZZ t2;
    t2 = 1;
    ZZ t = t1 - (q * t2);

    while (res > 0)
    {
        a = b;
        b = res;
        q = a / b;
        res = a - (q * b);

        s1 = s2;
        s2 = s;
        s = s1 - (q * s2);

        t1 = t2;
        t2 = t;
        t = t1 - (q * t2);

    }

    temp.push_back(b);
    temp.push_back(s2);
    temp.push_back(t2);

    return temp;
}

ZZ inversa(ZZ a, ZZ b)
{
    return extMcdZZ(a, b).at(1);
}

ZZ mcdZZ(ZZ a, ZZ b)
{
    ZZ res = a - ((a / b) * b);
    while (res != 0)
    {
        a = b;
        b = res;
        res = a - ((a / b) * b);
        //cout << a << " = (" << a / b << ") * " << b << " + " << res << endl;
    }
    return b;
}

ZZ moduloZZ(ZZ a, ZZ b)
{
    ZZ q = a / b;
    ZZ res = a - (q * b);
    if (res < 0)
    {
        q--;
        res = a - (q * b);
    }
    return res;
}

ZZ powerZZextra(ZZ a, ZZ b)
{
    ZZ temp = a;
    while (b > 1)
    {
        a = a * temp;
        b--;
    }
    return a;
}

ZZ powerZZ(ZZ a, ZZ b, ZZ N)
{
    ZZ cumulativeExponent, newB, nMod, lastSquare, lastExponent, otherSquare, two;
    cumulativeExponent = 1;
    newB = b;
    lastSquare = a;
    lastExponent = 0;
    otherSquare = 1;
    two = 2;
    do
    {
        nMod = moduloZZ(newB, two);
        if (cumulativeExponent != 1) lastSquare = moduloZZ(powerZZextra(lastSquare, two), N);
        if (nMod == 1)
        {
            lastExponent = lastExponent + cumulativeExponent;
            otherSquare = moduloZZ(lastSquare * otherSquare, N);
        }
        newB = newB / 2;
        cumulativeExponent = cumulativeExponent * 2;
    }
    while (newB > 0);
    return otherSquare;
}


ZZ getPrime(ZZ diff)
{
    int tempo = 0;
    ZZ temp;
    temp = 0;
    srand(time(NULL));

    while(true)
    {    
        tempo = rand() % 9999;
        temp = tempo;
        if (isPrime(temp) && temp > 2 && temp != diff)
        {
            return temp;
        }
    }
}

bool isPrime (ZZ a)
{
    ZZ i;
    for (i = 2; i < a; i++)
    {
        if (a % i == 0) return false;
    }
    return true;
}

std::string zToString(ZZ z) {
    std::stringstream buffer;
    buffer << z;
    return buffer.str();
}


vector<string> stringToVector(string message, int ddigits)
{
    vector<string> blocks;
    for (int i = 0; i < (int)message.length(); i+=ddigits)
    {
        blocks.push_back(string(message, i, ddigits));
    }
    return blocks;
}

vector<string> stringToVectorIndex(string message, int ddigits, string alphabet)
{
    vector<string> firstBlock;
    for (string::iterator i = message.begin(); i != message.end(); i++)
    {
        //IF NOT FOUND WILL RETURN 0
        string temp = std::to_string(alphabet.find(*i));
        //std::cout << temp.length();
        string block = string(ddigits - (int)temp.length(), '0') + temp;
        firstBlock.push_back(block);
    }
    return firstBlock;
}

string vectorToString(vector<string> blocks)
{
    string final;
    if (!blocks.empty())
    {
        for (vector<string>::iterator i = blocks.begin(); i != blocks.end(); i++)
        {
            final.append(*i);
        }
    }
    return final;
}


