#include <iostream>
#include <string>

using namespace std;

void swap(char& a, char&b)
{
    char temp = a;
    a = b;
    b = temp;
}

void selSort(string &myString)
{
    int menor;
    for(int i = 0; i < (int)myString.length() - 1; i++)
    {
        menor = i;
        for(int j = i + 1; j < (int)myString.length(); j++)
        {
            if(myString[j] < myString[menor])
            {
                menor = j;
            }
            swap(myString[j], myString[menor]);
        }

    }
}

int main()
{
    string cadena = "Hola como estas";
    selSort(cadena);
    cout << cadena;


    return 0;
}