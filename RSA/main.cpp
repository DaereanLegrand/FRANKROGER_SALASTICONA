#include <NTL/ZZ.h>
#include <iostream>
#include "./headers/receiver.h"
#include "./headers/source.h"
#include "headers/functions.h"

// g++ -g -O2 -std=c++11 -pthread -march=native "$string/$file" -o "$string/$output" -lntl -lgmp -lm

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "RSA: =================\n";
    ZZ p, q, res;
    
    p = getPrime();
    q = getPrime(p);

    receiver miReceptor(p, q);
    source miEmisor(miReceptor.e, miReceptor.N);

    ZZ leMensaje;
    leMensaje = 156478;
    ZZ mensajeC = miEmisor.cypher(leMensaje);
    cout << "El mensaje cifrado es: " << mensajeC << endl;
    ZZ mensajeD = miReceptor.decypher(mensajeC);
    cout << "El mensaje decifrado es: " << mensajeD << endl;
}
