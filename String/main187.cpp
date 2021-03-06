#include <iostream>
#include <string>

using namespace std;

int modulo(int a, int b = 26)
{
    int q = a / b;
    int res = a - (q * b);

    if (res < 0) 
    {
        q--;
        res = a - (q * b);

    }

    return res;
}

string encrypt(string message, int key)
{
    int length = message.length();
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    string encrypted(length, ' ');

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (message[i] == alphabet[j])
            {
                encrypted[i] = alphabet[modulo(j + key)];//MODULO
            }
            else if(tolower(message[i]) == alphabet[j])
            {
                encrypted[i] = toupper(alphabet[modulo(j + key)]);
            }
        }
    }

    return encrypted;
}

string decrypt(string message, int key)
{
    int length = message.length();
    char alphabet[26] = {'a','b','c','d','e','f','g','h','i','j','k','l','m','n','o','p','q','r','s','t','u','v','w','x','y','z'};
    string encrypted(length, ' ');

    for (int i = 0; i < length; i++)
    {
        for (int j = 0; j < 26; j++)
        {
            if (message[i] == alphabet[j])
            {
                encrypted[i] = alphabet[modulo(j - key)];//MODULO
            }
            else if(tolower(message[i]) == alphabet[j])
            {
                encrypted[i] = toupper(alphabet[modulo(j - key)]);
            }

        }
    }

    return encrypted;
}

int main()
{
    string mensaje = "hola COMO estais";
    string encriptado = encrypt(mensaje, 34);
    cout << encriptado << endl;
    string desencriptada = decrypt(encriptado, 34);
    cout << desencriptada;

    return 0;
}