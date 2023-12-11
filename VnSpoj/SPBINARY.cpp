#include <bits/stdc++.h>
using namespace std;

struct bigint{
    string val;
    bigint(string val) : val(val){}
    bigint () {}
    void print(){
        cout << val;
    }
};

bigint f[610];

bigint operator + (bigint x, bigint y){
    bigint ans;
    while (x.val.size() < y.val.size()) x.val = '0' + x.val;
    while (x.val.size() > y.val.size()) y.val = '0' + y.val;
    int carry = 0, sum;
    for (int i = x.val.size() - 1; i >= 0; i--){
        sum = x.val[i] + y.val[i] - 96 + carry;
        carry = sum / 10; sum %= 10;
        ans.val = char(sum + '0') + ans.val;
    }
    if (carry != 0) ans.val = char('0' + carry) + ans.val;
    return ans;
}

bigint operator - (bigint x, bigint y){
    bigint ans;
    while (x.val.size() < y.val.size()) x.val = '0' + x.val;
    while (x.val.size() > y.val.size()) y.val = '0' + y.val;
    int borrow = 0, sub;
    for (int i = x.val.size() - 1; i >= 0; i--){
        sub = x.val[i] - y.val[i] - borrow;
        if (sub < 0) sub += 10, borrow = 1;
        else borrow = 0;
        ans.val = char(sub + '0') + ans.val;
    }
    int i = 0;
    while (ans.val.size() > 1 && ans.val[i] == '0') ans.val.erase(0, 1);
    return ans;
}

int main(){
    int n, k; cin >> n >> k;
    k++;
    f[1] = bigint("2");
    for (int i = 2; i < k; i++)
        f[i] = f[i - 1] + f[i - 1];
    f[k] = f[k - 1] + f[k - 1] - bigint("2");
    for (int i = k + 1; i <= n; i++)
        f[i] = f[i - 1] + f[i - 1] - f[i - k];
    f[n].print();
}
