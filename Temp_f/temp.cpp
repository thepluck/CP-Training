#include<bits/stdc++.h>
using namespace std;
#define ii pair<int,int>
#define iii pair<int,ii>
#define fi first
#define se second
#define pb push_back
#define mp make_pair
#define trash trash
#define ALL(x) x.begin(),x.end()
const int oo=1e9;
const int Mod=1e9+7;
const long long OO=1e18;
const int N=1e5+5;
int n, q;
string s;
int a[1<<17], Sure[5][50], Sure2[5][50], so[1<<17];
int xuat(int u, int v)
{
    cout << "XOR " << u <<" "<<v<<endl;
    int x; cin >> x;
    return x;
}
int xuat2(int u, int v)
{
    cout << "OR " << u <<" "<<v<<endl;
    int x; cin >> x;
    return x;
}
bool inBit(int x, int k)
{
    return x >> k & 1;
}
void in()
{
    cin >> n;
    int x = xuat2(1,2), y = xuat2(2,3);
    for(int i=1; i<n; i++)
    {
        a[i] = xuat(i,i+1);
    }
    for(int i=30; i>=0; i--)
    {
        int t1 = inBit(x,30);
        int t2 = inBit(a[1],30);
        if(t1 && !t2)Sure[1][i] = Sure[2][i] = 1, so[1] ^= 1<<i;
        else if(!t1)Sure[1][i] = Sure[2][i] = 0;
        else Sure[1][i] = Sure[2][i] = -1;
    }
    for(int i=30; i>=0; i--)
    {
        int t1 = inBit(y,30);
        int t2 = inBit(a[2],30);
        if(t1 && !t2)Sure2[2][i] = Sure2[3][i] = 1;
        else if(!t1)Sure2[2][i] = Sure2[3][i] = 0;
        else Sure2[2][i] = Sure2[3][i] = -1;
        if(Sure[1][i] == -1)
        {
            if(Sure2[2][i]!=-1)Sure[1][i]=0;
            if(Sure2[2][i]==0) so[1] ^= 1<<i;
            else if(Sure2[2][i]==1)continue;
        }
    }
    int z = xuat2(1,3);
    for(int i=30; i>=0; i--)
    {
        int t1 = inBit(x,30);
        if(Sure[1][i]==-1 && t1)so[1] ^=1<<i;
    }
    for(int i=2; i<=n; i++)so[i] =a[i-1]^so[i-1];
    cout <<"! ";
    for(int i=1; i<=n; i++)cout << so[i] << " ";
    cout << endl;
}
int main()
{
    //file();
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0); in();
}