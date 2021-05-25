//#include <NTL/ZZ.h>
#include "../headers/source.h"
#include "../headers/functions.h"
#include <iostream>

using std::string;

source::source(ZZ userPublic, ZZ uN, string uAlphabet) :
    publicKey(userPublic), N(uN), alphabet(uAlphabet)
{

}

ZZ source::cypherZZ(ZZ mensaje)
{
    //return moduloZZ(powerZZ(mensaje, publicKey), N);
    return powerZZ(mensaje, publicKey, N);
}

vector <string> source::stringDivider(string message, int ddigits)
{
    vector <string> firstBlock;
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

string source::converter(vector <string> blocks)
{
    string final;
    if (!blocks.empty())
    {
        for (vector <string>::iterator i = blocks.begin(); i != blocks.end(); i++)
        {
            final.append(*i);
        }
    }
    return final;
}

string source::cypher(string message)
{
    //alphabet.back(); 
    int availableDigits = std::to_string((int)alphabet.length()).length();
    return string();
}
