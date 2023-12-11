#include <iostream>
#include <vector>
using namespace std;
 
int n;
vector<int> a;
 
void Init()
{
    cin>>n;
    a.resize(n+2);
    for(int i=1;i<=n;i++) cin>>a[i];
}
 
void Solve()
{
    int res=0;
    for(int i=5;i<=n-5;i++)
    {
        int len=1;
        for(int j=n;j>i;j--)
            if(a[j]-a[j-1]==a[j-i]-a[j-i-1])
            {
                len++;
                if(len>res) res=len;
                if(len==i) break;
            }
            else
                len=1;
    }
    if (res < 5)
        cout << '0';
    else
        cout << res;
}
 
int main()
{
    Init();
    Solve();
}