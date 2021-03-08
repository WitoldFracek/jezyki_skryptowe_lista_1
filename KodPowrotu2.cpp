#include <iostream>
using namespace std;

bool isSilent(int len, char** arg)
{
    for(int i=0; i<len; i++)
    {
        if(arg[i][0] != '\0' && arg[i][1] != '\0' && arg[i][2] == '\0')
        {
            if(arg[i][0] == '/')
            {
                if(arg[i][1] == 's' || arg[i][1] == 'S')
                    return true;
            }
        }
    }
    return false;
}

bool isInt(char* input)
{
    int iter = 0;
    while(input[iter] != '\0')
    {
        if(input[iter] < '0' || input[iter] > '9')
            return false;

        iter++;
    }
    return true;
}

bool isDouble(char* input)
{
    bool b_sep_occ = false;
    int iter = 0;
    while(input[iter] != '\0')
    {
        if(input[iter] < '0' || input[iter] > '9')
        {
            if(input[iter] == '.' || input[iter] == ',')
            {
                if(b_sep_occ)
                    return false;
                b_sep_occ = true;
            }
            else return false;
        }

        iter++;
    }
    return true;
}



int main(int arg, char** argv, char** env)
{
    int i_ret = 0;
    bool b_is_silent = isSilent(arg, argv);
    bool b_wrong_param = false;

    for(int i=1; i<(arg - b_is_silent); i++)
    {
        if(!isDouble(argv[i]))
        {
             b_wrong_param = true;
        }
    }
    if(arg == 1 + b_is_silent)
    {
        i_ret = 1;
        if(!b_is_silent) cout << i_ret << endl;
        return i_ret;
    }
    else if(b_wrong_param)
    {
        i_ret = 2;
        if(!b_is_silent) cout << i_ret << endl;
        return i_ret;
    }
    if(!b_is_silent) cout << i_ret << endl;
    return i_ret;
}