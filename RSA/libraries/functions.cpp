#pragma once
#include "../libraries/functions.cpp"

int extMcd(int a, int b, int& x)
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

    return b;
}

int mcd(int a, int b)
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

bool isPrime (int a)
{
    for (int i = 2; i < a; i++)
    {
        if (a % i == 0) return false;
    }
    return true;
}
