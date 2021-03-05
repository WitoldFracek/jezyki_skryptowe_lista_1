#include <iostream>
#include <vector>
using namespace std;

string paramToString(char* arg)
{
    string s_ret = "";
    int iter = 0;
    while(arg[iter] != '\0')
    {
        s_ret += arg[iter];
        iter++;
    }
    return s_ret;
}

string getName(string env)
{
    int iter = 0;
    int i_len = env.length();
    string s_ret = "";
    while(iter < i_len)
    {
        if(env[iter] !=  '=')
        {
            s_ret += env[iter];
        }
        else{
            iter = i_len;
        }
        iter++;
    }
    return s_ret;
}

string getData(string env)
{
    string s_ret = "";
    bool b_equal_sig_found = false;
    int iter = 0;
    while(!b_equal_sig_found)
    {
        if(env[iter] == '=')
            b_equal_sig_found = true;
        
        iter ++;
    }

    for(int i=iter; i<env.length(); i++)
    {
        s_ret += env[i];
    }
    return s_ret;

}

vector<string> split(string data, char separator)
{
    vector<string> v_ret;
    string s_temp = "";
    for(int i=0; i<data.length(); i++)
    {
        if(data[i] == separator)
        {
            v_ret.push_back(s_temp);
            //cout << s_temp << endl;
            s_temp = "";
        }
        else
        {
            s_temp += data[i];
        }
    }
    v_ret.push_back(s_temp);
    return v_ret;
}

bool isSubstring(string egz, string data)
{
    int iter = 0;
    for(int i=0; i<data.length(); i++)
    {
        if(egz[iter] == data[i])
        {
            while(egz[iter] == data[iter+i] && iter<egz.length() && (iter+i) < data.length())
            {
                iter++;
            }
            if(iter == egz.length())
                return true;
        }
        else
        {
            iter = 0;
        }
    }
    return false;
}

bool isSilent(string arg)
{
    if((arg == "/s") || (arg == "/S"))
        return true;
    return false;
}




int main(int args, char** argv, char** env)
{
    bool b_at_least_one = false;
    vector<string> argsToString;
    for(int i=1; i<args; i++)
    {
        argsToString.push_back(paramToString(argv[i]));
    }
    bool b_is_silent = isSilent(argsToString[argsToString.size()-1]);

    int iter = 0;
    for(int i=0; i<argsToString.size()-b_is_silent; i++)
    {
        while(env[iter])
        {
            string s_name = getName(env[iter]);
            if(isSubstring(argsToString[i], s_name))
            {
                b_at_least_one = true;
                string s_data = getData(env[iter]);
                vector<string> v_data = split(s_data, ';');
                cout << s_name << endl << "=" << endl;
                for(int j=0; j<v_data.size(); j++)
                {
                    cout << "    " << v_data[j] << endl;
                }
                endl(cout);
            }
            iter++;
        }
    }
    if(!b_at_least_one && !b_is_silent) cout << "NONE" << endl;


    return 0;
}