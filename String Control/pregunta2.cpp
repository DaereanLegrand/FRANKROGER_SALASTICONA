#include <iostream>
#include <string>
#include <math.h>

using namespace std;

int main()
{
    char userInput[100];
    cout << "Ingrese un numero: ";
    fgets(userInput, 100, stdin);

    int myNumber = atoi(userInput);
    cout << myNumber / 2;

    return 0;
}