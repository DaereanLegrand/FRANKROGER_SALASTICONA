#include <iostream>
#include "afin.h"

using namespace std;

int main()
{
    while (true)
    {
        affineCypher emisor(11, 18, "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,");
        affineCypher receptor(11, 18, "abcdefghijklmnopqrstuvwxyz ABCDEFGHIJKLMNOPQRSTUVWXYZ,");

        //affineCypher emisor(7, 18, "abcdefghijklmnopqrstuvwxyz");
        //affineCypher receptor(7, 18, "abcdefghijklmnopqrstuvwxyz");

        string mensaje;
        cout << "Ingrese un mensaje: ";
        getline(cin, mensaje);

        cout << "Mensaje encriptado es: ";
        string mensajeEncriptado = emisor.cypher(mensaje);
        cout << mensajeEncriptado << endl;

        cout << "Mensaje desencriptado es: ";
        string mensajeDesencriptado = receptor.decypher(mensajeEncriptado);
        cout << mensajeDesencriptado << endl;
    }
    return 0;
}
