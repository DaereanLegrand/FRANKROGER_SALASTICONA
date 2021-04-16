#include <iostream>
#include <string>
#include <stdio.h>
#include <string.h>

using namespace std;

void function(string& cadena)
{
    char* tokens;
    char* cad;
    cad = new char[(int)cadena.length()];
    string puntuacion = ".,:;-";

    for (int i = 0; i < (int)cadena.length(); i++)
    {
        if (puntuacion.find(cadena[i]) != string::npos)
        {
            cadena[i] = ' ';
        }
        cad[i] = cadena[i];
    }

    tokens = strtok(cad, " ");
    while (tokens != NULL)
    {
        cout << tokens << endl;
        tokens = strtok(NULL, " ");
    }

}

int main()
{
    string myString;
    cout << "Ingrese una cadena de caracteres: ";
    getline(cin, myString);

    function(myString);
    
    cout << myString;

    return 0;
}