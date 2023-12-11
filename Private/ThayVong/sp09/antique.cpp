#include<bits/stdc++.h>
using namespace std;
const int maxn = 2*1e5 +5;
int n;
long long s = 0, t =0;
pair < int, int > a[maxn];
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    freopen("antique.inp","r",stdin);
    freopen("antique.out","w",stdout);
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i].first;
    for(int i=1;i<=n;i++) {cin>>a[i].second;t+=a[i].second;}
    sort(a+1,a+n+1);
    int n1=n;int k=(t+1)/2;
    while( t >= k )
    {
        t=t-a[n1].second;
        n1--;
    }
    n1++;
    for(int i=1;i<=n;i++)
    {
        s += a[i].second * abs( a[i].first - a[n1].first );
    }
    cout<<s;
}

