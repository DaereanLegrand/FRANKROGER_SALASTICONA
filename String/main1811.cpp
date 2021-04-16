#include <iostream>
#include <string>

using namespace std;

string lenom(string nombre, string apellido)
{
    string temp(nombre + ' ' + apellido);
    cout << temp;

    return temp;
}

int main()
{
    string nombres;
    cout << "Ingrese su nombre: ";
    getline(cin, nombres);

    string apellido;
    cout << "Ingrese su apellido: ";
    getline(cin, apellido);

    lenom(nombres, apellido);

    return 0;
}