#include <iostream>
#include "./headers/receiver.h"
#include "./headers/source.h"

using std::cin;
using std::cout;
using std::endl;

int main()
{
    cout << "RSA: =================\n";
    receiver miReceptor(3, 5);
    source miEmisor(miReceptor.e, miReceptor.N);

    int mensajeC = miEmisor.cypher(4);
    cout << "El mensaje cifrado es: " << mensajeC << endl;
    int mensajeD = miReceptor.decypher(mensajeC);
    cout << "El mensaje decifrado es: " << mensajeD << endl;
}
