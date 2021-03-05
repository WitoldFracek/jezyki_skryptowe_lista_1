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

int parseInt(char* number, bool* contr)
{
    int i_ret = 0;
    int i_counter = 0;
    while(number[i_counter] != '\0')
    {
        if(number[i_counter] == '.')
            return i_ret;
        if(number[i_counter] >= '0' && number[i_counter] <= '9')
        {
            i_ret = i_ret *10;
            i_ret += number[i_counter] - '0';
        }
        else{
            *contr = false;
        }
        i_counter++;

    }
    return i_ret;
}


int main(int args, char** argv, char** env)
{
    bool b_is_silent = isSilent(args, argv);
    int i_return_code = 0;
    if(args == 1 + b_is_silent)
    {
        i_return_code = 11;
        if(!b_is_silent) cout << i_return_code << endl;
        return i_return_code;
    }
    if(args > 2 + b_is_silent)
    {
        i_return_code = 13;
        if(!b_is_silent) cout << i_return_code << endl;
        return i_return_code;
    }
    bool contr = true;
    i_return_code = parseInt(argv[1], &contr);
    if(contr)
    {
        if(!b_is_silent) cout << i_return_code << endl;
        return i_return_code;
    }
    else
    {
        i_return_code = 12;
        if(!b_is_silent) cout << i_return_code << endl;
        return i_return_code;
    }

}