#include <string>
#include "functions.h"

using namespace std;

class alfabeto
{
    public:
        int sizeAlpha;
        char* alpha;
        int sizeVocales;
        char* vocales;

        alfabeto(string cadena, string uvocales = "aeiou")
        {
            sizeAlpha = cadena.length();
            alpha = new char[sizeAlpha];
            sizeVocales = uvocales.length();
            vocales = new char[sizeVocales];

            for (int i = 0; i < sizeAlpha; i++)
            {
                alpha[i] = cadena[i];
            }

            for (int i = 0; i < sizeVocales; i++)
            {
                vocales[i] = uvocales[i];
            }
        }
};

class affineCypher: public alfabeto 
{
    private:
        int keyA;
        int keyB;

    public:
        
        affineCypher(int uKeyA, int uKeyB, string uAlfabeto):
            alfabeto(uAlfabeto), keyA(uKeyA), keyB(uKeyB)
        {
            //comprobar claves NO OLVIDAR
        }

        string cypher(string cadena)
        {
            string encrypted((int)cadena.length(), ' ');

            for (int i = 0; i < (int)cadena.length(); i++)
            {
                for (int j = 0; j < sizeAlpha; j++)
                {
                    if (cadena[i] == alpha[j])
                    {
                        int temp = keyA * j;
                        //if (temp >= sizeAlpha) modulo(temp, sizeAlpha);
                        temp += keyB;
                        if (temp >= sizeAlpha) temp = modulo(temp, sizeAlpha);
                        encrypted[i] = alpha[temp];
                    }
                }
            }

            return encrypted;
        }

        string decypher(string cadena)
        {
            string decrypted((int)cadena.length(), ' ');
            // x = a^-1 (y - b) SACAR MODULO SI ES MAYOR AL TAMANO DEL ALFABETO, O SI ES MENOR
            
            for (int i = 0; i < (int)cadena.length(); i++)
            {
                for (int j = 0; j < sizeAlpha; j++)
                {
                    if (cadena[i] == alpha[j])
                    {
                        int tempX = 0;
                        int tempY = 0;
                        int modulo = extMcd(keyA, keyB, tempX, tempY);
                        int temp = tempX * (j - keyB);
                        //if (temp >= sizeAlpha) modulo(temp, sizeAlpha)
                        if (temp >= sizeAlpha || temp < 0) 
                        {
                            temp = modulo(temp, sizeAlpha);
                        }
                        decrypted[i] = alpha[temp];
                    }
                }
            }

            return decrypted;
        }

}; 
