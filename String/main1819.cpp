#include <iostream>
#include <string>

using namespace std;

int main()
{
    string myString;
    cout << "Ingrese una cadena de caracteres: ";
    getline(cin, myString);
    myString.insert((int)myString.length() / 2, "*******");
    cout << myString;

    return 0;
}