#include <iostream>
#include <string>
#include <vector>
#include <string.h>

using namespace std;

void div(string myCadena, int cant)
{
    string temp; // cahr * 
    vector<string> myVector;
    vector<string>::iterator cont;

    if ((int)myCadena.length() % cant != 0)
    {
        myCadena.append(cant - ((int)myCadena.length() % cant), 'X');
    }

    for (int i = 0; i < (int)myCadena.length() / cant; i++)
    {
        temp = myCadena.substr(i * cant, cant);
        cout << temp << endl;

        myVector.insert(myVector.end() ,temp);
    }

    for (cont = myVector.begin(); cont < myVector.end(); cont++)
    {
        cout << *cont << ' ';
    }

}

int main()
{
    string cadena = "intente analizar mas profundamente los mensajes recibidos";
    div(cadena, 4);

    return 0;
}