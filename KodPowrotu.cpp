#include <iostream>
using namespace std;

bool isSilent(int len, char** arg)
{
    for(int i=0; i< len; i++)
    {
        if(arg[i] == "/s" || arg[i] == "/S")
            return true;
    }
    return false;
}


int main(int args, char** argv, char** env)
{
    bool b_is_silent = isSilent(args, argv);
    int i_return_code = 0;
    if(args == 1)
    {
        if(!b_is_silent) puts("11");
        return 11;
    }
    if(args > 2 + b_is_silent)
    {
        if(!b_is_silent) puts("13");
        return 13;
    }
    try
    {
        int i_first_param = atoi(argv[1]);
        i_return_code = i_first_param;
        if(!b_is_silent) puts(argv[1]);
        return i_first_param;
    }
    catch(exception e)
    {
        return 12;
    }

}