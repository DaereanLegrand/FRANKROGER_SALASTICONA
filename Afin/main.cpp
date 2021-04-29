#include <iostream>
#include "afin.h"

using namespace std;

int main()
{
    affineCypher emisor(7, 18, "abcdefghijklmnopqrstuvwxyz");     
    affineCypher receptor(7, 18, "abcdefghijklmnopqrstuvwxyz");     

    string mensajeEncriptado = emisor.cypher("holamellamofrank");
    cout << mensajeEncriptado << endl;

    string mensajeDesencriptado = receptor.decypher(mensajeEncriptado);
    cout << mensajeDesencriptado << endl;
    

    return 0;
}
