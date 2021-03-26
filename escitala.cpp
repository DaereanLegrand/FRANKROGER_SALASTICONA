/*
usar string, es un vector de caracteres
stl     vector<int>

          filas (digamos 3)
        /
clave 
        \
          columnas (digamos 6)

menasaje = "hola como estan"

crear array 3x6 (o posiblemente otras dimensiones)

array = {
    {h,o,l,a, ,c}, 
    {o,m,o, ,e,s},
    {t,a,n, , , }
    }

    0   1   2   3   4
    5   6   7   8   9
    10  11  12  13  14

    0   1   2   3   4   5
    6   7   8   9   10  11
    12  13  14  15  16  17

extraer clave = "hotomalona   e cs "

para desencriptar hacerlo inversamente 

NO USAR MATRICES SOLO EL VECTOR STRING

*/

#include <iostream>
#include <string>

using namespace std;

class algoritmo
{
    private:
    int filas;
    int columnas;

    public:
    algoritmo()
    {
        int tempClave = getClave();
        columnas = tempClave % 10;
        filas = (tempClave - columnas) / 10;
    }

    algoritmo(int c_clave)
    {
        columnas = c_clave % 10;
        filas = (c_clave - columnas) / 10;
    }

    int getClave()
    {
        int tempClave;
        cout << "Ingrese la clave: ";
        cin >> tempClave;
        return tempClave;
    }

    string encrypt(string cadena)
    {
        if (cadena.length() < columnas * filas)
        {
            int add = (columnas * filas) - cadena.length();

            for (int i = 0; i < add; i++)
            {
                cadena.append(" ");
            }
        
        }

        int proof = 0;
        string encriptado = cadena;

        for (int j = 0; j < columnas; j++)
        {
            for (int i = 0; i < filas; i++)
            {
                if (proof < cadena.length()) 
                {
                    int ind_cad = (i * columnas) + j;
                    //cout << "ind_cad: " << ind_cad << '\t' << "proof: " << proof << endl;
                    encriptado[proof] = cadena[ind_cad];
                    proof++;
                }
            }
        }

        return encriptado;
    }

    string decrypt(string cadena)
    {
        if (cadena.length() < columnas * filas)
        {
            int add = (columnas * filas) - cadena.length();

            for (int i = 0; i < add; i++)
            {
                cadena.append(" ");
            }
        
        }

        int cont = 0;
        string desencriptado = cadena;

        for (int j = 0; j < columnas; j++)
        {
            for (int i = 0; i < filas; i++)
            {
                if (cont < cadena.length()) 
                {
                    int ind_cad = (i * columnas) + j;
                    //cout << "ind_cad: " << ind_cad << '\t' << "proof: " << cont << endl;
                    desencriptado[ind_cad] = cadena[cont];
                    cont++;
                }
            }
        }

        return desencriptado;
    }

};

int main ()
{
    string mensaje;
    cout << "Ingrese un mensaje: ";
    getline(cin, mensaje);

    algoritmo emisor;
    algoritmo receptor;

    cout << "mensaje: " << mensaje << endl;
    string msj_cifrado = emisor.encrypt(mensaje);
    cout << "mensaje cifrado: " << msj_cifrado << endl;
    string msj_descifrado = receptor.decrypt(msj_cifrado);
    cout << "mensaje descifrado: " << msj_descifrado << endl << endl;

    return 0;
}