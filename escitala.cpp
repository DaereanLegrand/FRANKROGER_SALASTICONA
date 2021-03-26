/*
usar string, es un vector de caracteres
stl     vector<int>

          filas (int)
        /
clave 
        \
          columnas (int)

menasaje = "hola como estan"

crear array 3x6 (o posiblemente otras dimensiones)

array = {
    {h,o,l,a, ,c}, 
    {o,m,o, ,e,s},
    {t,a,n, , , }
    }

    //En caso la clave sea de 3,5   3 filas, 5 columnas
    0   1   2   3   4
    5   6   7   8   9
    10  11  12  13  14

    //En caso la clave sea de 3,6   3 filas, 6 columnas
    0   1   2   3   4   5
    6   7   8   9   10  11
    12  13  14  15  16  17

extraer clave = "hotomalona   e cs "

para desencriptar hacerlo inversamente 

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
        cout << "COLUMNAS ";
        columnas = getClave();
        cout << "FILAS ";
        filas = getClave();
        cout << endl;
    }

    algoritmo(int c_clave) //CONSTRUCTOR QUE RECIBE SOLO UNA CLAVE, LA DIVIDE EN DECENAS Y UNIDADES
    {
        columnas = c_clave % 10;
        filas = (c_clave - columnas) / 10;
    }

    algoritmo(int c_columnas, int c_filas) //RECIBE 2 PARAMETROS, PARA LA ENCRIPTACION
    {
        filas = c_filas;
        columnas = c_columnas;
    }

    int getClave() //RECIBE UNA CLAVE
    {
        int tempClave;
        cout << "Ingrese la clave: ";
        cin >> tempClave;
        return tempClave;
    }

    string encrypt(string cadena) 
    {
        fill(cadena); //LLENAR LA CADENA 

        int cont = 0;
        string encriptado = cadena;

        for (int j = 0; j < columnas; j++)
        {
            for (int i = 0; i < filas; i++)
            {
                if (cont < cadena.length()) 
                {
                    int ind_cad = (i * columnas) + j; //LOGICA
                    encriptado[cont] = cadena[ind_cad]; //Indice cont, en orden recorre el string copiado, reemplaza en el nuevo string
                    cont++;
                }
            }
        }

        return encriptado;
    }

    string decrypt(string cadena)
    {
        fill(cadena);

        int cont = 0;
        string desencriptado = cadena;

        for (int j = 0; j < columnas; j++)
        {
            for (int i = 0; i < filas; i++)
            {
                if (cont < cadena.length()) 
                {
                    int ind_cad = (i * columnas) + j; //LOGICA
                    desencriptado[ind_cad] = cadena[cont]; //Indice cont, en orden recorre el string copiado, reemplaza en el nuevo string
                    cont++;
                }
            }
        }

        return desencriptado;
    }

    void fill (string &cadena)
    {
        if (cadena.length() < columnas * filas)
        {
            int add = (columnas * filas) - cadena.length();

            for (int i = 0; i < add; i++)
            {
                cadena.append(" ");
            }
        
        }
    }

};

int main ()
{
    string mensaje;
    cout << "Ingrese un mensaje: ";
    getline(cin, mensaje);

    algoritmo emisor;
    algoritmo receptor;

    /*
    algoritmo emisor(5,5);
    algoritmo receptor(5,5);
    algoritmo emisor(55);
    algoritmo receptor(55);
    */

    cout << "mensaje: " << mensaje << endl << endl;
    string msj_cifrado = emisor.encrypt(mensaje);
    cout << "mensaje cifrado: " << msj_cifrado << endl << endl;
    string msj_descifrado = receptor.decrypt(msj_cifrado);
    cout << "mensaje descifrado: " << msj_descifrado << endl << endl;

    return 0;
}
