#include <iostream>
using namespace std;

int main(int arg, char** argv, char** env)
{
    cout << "Zmienne srodowiska" << endl;
    int i = 0;
    while(env[i])
    {
        cout << env[i] << endl;
        i++;
    }
    endl(cout);

    cout << "Parametry programu:" << endl;
    for(int i=0; i<arg; i++)
    {
        cout << argv[i] << endl;
    }

}