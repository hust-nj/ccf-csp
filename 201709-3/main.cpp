#include<string>
#include<map>
#include<iostream>
using namespace std;

inline void shortfather(string &fatherkey)
{
    size_t pos = fatherkey.rfind('.');
    if(pos == string::npos)
        fatherkey.clear();
    else
        fatherkey.resize(pos);
}

int main()
{
    int n, m;
    cin >> n >> m;
    string s;
    string strjson;
    getline(cin, s);
    while(n--)
    {
        getline(cin, s);
        strjson += s;
    }
    int state = 0;
    //0: before 1, to find the key
    //1: process in the key string
    //2: before 3, to find the value
    //3: process in the value string
    string fatherkey;
    string currentword;
    map<string, string> json;
    for(size_t i = 0; i < strjson.length(); ++i)
    {
        switch(state)
        {
        case 0:
            if(strjson[i] == '"')
            {
                state = 1;
                currentword.clear();
            }
            else if(strjson[i] == '}')
            {
                shortfather(fatherkey);
            }
            break;

        case 1:
            if(strjson[i] == '"')
            {
                state = 2;
                if(fatherkey.length())
                    fatherkey += "." + currentword;
                else
                    fatherkey = currentword;
            }
            else
            {
                if(strjson[i] == '\\') ++i;//jump one
                currentword.push_back(strjson[i]);
            }
            break;

        case 2:
            if(strjson[i] == '"')
            {
                state = 3;
                currentword.clear();
            }
            else if(strjson[i] == '{')
            {
                state = 0;
                json[fatherkey] = "OBJECT";
            }
            break;

        case 3:
            if(strjson[i] == '"')
            {
                state = 0;
                json[fatherkey] = "STRING " + currentword;
                shortfather(fatherkey);
            }
            else
            {
                if(strjson[i] == '\\') ++i;
                currentword.push_back(strjson[i]);
            }

        }
    }
    while(m--)
    {
        string s;
        cin >> s;
        map<string, string>::iterator p = json.find(s);
        if(p == json.end())
            cout << "NOTEXIST" << endl;
        else
            cout << p->second << endl;
    }
    return 0;
}
