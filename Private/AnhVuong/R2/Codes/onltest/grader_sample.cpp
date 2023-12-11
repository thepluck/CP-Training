#include <bits/stdc++.h>
#include "onltest.h"

using namespace std;

namespace fslnvffeklfanfnja {
    string _ans;
    int _X, _Y, _Z, _N;
    int _call_cnt;
    
    void output(string s) {
        cout << _call_cnt << "\n";
        cout << s << "\n";
        exit(0);
    }

    int count_char(string s, char c) {
        int res = 0;
        for(int i = 0; i < s.length(); ++i) res += (s[i] == c);
        return res;
    }

    int submit(string s) {
        if (s.length() != _N) output("");
        if (count_char(s, 'A') != _X) output("");
        if (count_char(s, 'B') != _Y) output("");
        if (count_char(s, 'C') != _Z) output("");
        
        int score = 0;
        for(int i = 0; i < _N; ++i) score += (s[i] == _ans[i]);
        _call_cnt += 1;
        
        return score;
    }
    
    void init() {
        cin >> _ans;
        _X = count_char(_ans, 'A');
        _Y = count_char(_ans, 'B');
        _Z = count_char(_ans, 'C');
        _N = _ans.length();
        
        _call_cnt = 0;
    }
    
    void doit() {
        init();
        string s = online_test(_X, _Y, _Z);
        output(s);
    }
}

int submit(string s) {
    return fslnvffeklfanfnja::submit(s);
}

int main()
{
    fslnvffeklfanfnja::doit();   
    return 0;
}
