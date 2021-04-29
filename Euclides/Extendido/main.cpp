/*  ALGORITMO DE EUCLIDES
 *  r = a - ((a / b) * b) //Se debe de tener en cuenta que a / b es entero
 *
 *  Teniendo en cuenta los numeros A = 999, B = 321
 *  mcd(999,321) = 3
 *  extendido(999,321) =  
 */

#include <iostream>
//#include <NTL/ZZ.h>

using namespace std;

//WHILE PARA HALLAR EL RESULTADO
int whiMcd(int a, int b, int &x, int &y)
{
    int q = a / b;
    int res = a - (q * b);

    int s1 = 1;
    int s2 = 0;
    int s = s1 - (q * s2);

    int t1 = 0;
    int t2 = 1;
    int t = t1 - (q * t2);

    while (res > 0)
    {
        a = b;
        b = res;
        q = a / b;
        res = a - (q * b);

        s1 = s2;
        s2 = s;
        s = s1 - (q * s2);

        t1 = t2;
        t2 = t;
        t = t1 - (q * t2);

    }
    
    x = s2;
    y = t2;

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
    int i = 0;
    while (i < 1000000)
    {
        i++;
        int A = rand();
        int B = rand();
        int x = 0;
        int y = 0;
        //cout << "Ingrese el primer numero: ";
        //cin >> A;
        //cout << "Ingrese el segundo numero: ";
        //cin >> B;

        //cout << mcd(A, B) << endl; //A simple vista con la funcion time del shell de Linux esta funcion es mas rapida
        //cout << whiMcd(A, B, x, y) << "\tx: " << x << "\ty: " << y << endl;  // Y esta es mas lenta 
        int mcd = whiMcd(A, B, x, y);
        if ((A * x) + (B * y) == mcd)
        {
            cout << "correct\t" << "A: " << A << "\tB: " << B << "\tmcd:" << mcd << endl;
        }
        else 
        {
            cout << "BRUTAL ERROR, ABORTING\n";
            break;
        }




    }
    return 0;
}
