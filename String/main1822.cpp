#include <iostream>
#include <string>

using namespace std;

void reves(string cadena)
{
    for (int i = (int)cadena.length(); i >= 0; i--)
    {
        cout << cadena[i];
    }
    cout << endl;
}

int main()
{
    string myString;
    cout << "Ingrese una linea de texto: ";
    getline(cin, myString);
    reves(myString);

    return 0;
}