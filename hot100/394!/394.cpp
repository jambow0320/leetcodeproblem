#include <string>

using std::string;

class Solution {
private:
    int ptr = 0;
    string src;

    int getnum()
    {
        int x = 0;
        while(ptr < src.size() && isdigit(src[ptr]))
        {
            x = x * 10 + src[ptr++] - '0';
        }
        return x;
    }

    string getstring()
    {
        if(ptr >= src.size() || src[ptr] == ']')
            return "";

        string str("");

        if(isdigit(src[ptr]))
        {
            int reptime = getnum();
            ++ptr;
            string tmp = getstring();
            while(reptime--) str += tmp;
        }
        else 
        {
            str += src[ptr];
        }

        ++ptr;
        return str + getstring();
    }

public:
    string decodeString(string s) {
        src = s;
        ptr = 0;
        return getstring();
    }
};