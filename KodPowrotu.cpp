#include <iostream>
using namespace std;

bool isSilent(int len, char** arg)
{
    for(int i=0; i<len; i++)
    {
        if(arg[i][0] != '\0' && arg[i][1] != '\0' && arg[i][2] == '\0')
        {
            if(arg[i][0] == '\\')
            {
                if(arg[i][1] == 's' || arg[i][1] == 'S')
                    return true;
            }
        }
    }
    return false;
}

string toStringArray(int len, char** arg)
{
    string s_ret[len];
    for(int i = 0; i<len; i++)
    {
        
    }
}


int main(int args, char** argv, char** env)
{
    bool b_is_silent = isSilent(args, argv);
    cout << "is silent: " << b_is_silent << endl;
    int i_return_code = 0;
    return 0;
    /*if(args == 1)
    {
        puts("11");
        return 11;
    }
    if(args > 2 + b_is_silent)
    {
        puts("13");
        return 13;
    }
    try
    {
        int i_first_param = atoi(argv[1]);
        i_return_code = i_first_param;
        puts(argv[1]);
        return i_first_param;
    }
    catch(exception e)
    {
        return 12;
    }*/

}