#include <iostream>

using namespace std;

int division(int num, int code)
{
    if (num < 0) num*=-1;

    while (num - code > 0)
    {
        num-=code;
    }

    return num;    
}

int main()
{
    cout << division(-8, 5);
}