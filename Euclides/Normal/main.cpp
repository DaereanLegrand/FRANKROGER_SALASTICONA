/*  ALGORITMO DE EUCLIDES
 *  r = a - ((a / b) * b) //Se debe de tener en cuenta que a / b es entero
 */

#include <iostream>
//#include <NTL/ZZ.h>

using namespace std;

//WHILE PARA HALLAR EL RESULTADO
int whiMcd(int a, int b)
{
    int res = a - ((a / b) * b);
    while (res != 0)
    {
       a = b;
       b = res;
       res = a - ((a / b) * b);
    }
    return b;
}

//RECURSIVIDAD PARA HALLAR EL RESULTADO
int mcd(int a, int b)
{
    int res = a - ((a / b) * b);
    if (res == 0)
    {
        return b;
    }
    else
    {
        a = b;
        b = res;
        return mcd(a, b);
    }

    return 0;
}

int main()
{
    int A = 12341264;
    int B = 6786;

    //cout << "Ingrese el primer numero: ";
    //cin >> A;
    //cout << "Ingrese el segundo numero: ";
    //cin >> B;

    //cout << mcd(A, B) << endl; //A simple vista con la funcion time del shell de Linux esta funcion es mas rapida
    cout << whiMcd(A, B) << endl;  // Y esta es mas lenta 
    return 0;
}
