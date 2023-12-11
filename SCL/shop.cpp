#define X first
#define Y second
#define pb push_back
#include<bits/stdc++.h>
using namespace std;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());
int randint(int l,int r){return uniform_int_distribution < int > (l,r) (rng);}
///shuffle(a.begin(), a.end(), rng)
#define int long long
const int MAX=5000+4,inf=1e9,M=10000+20,mod=1e9+7;
using ii = pair < int ,int >;
void maxx(int &a,int b){if(b>a) a=b;}
void minn(int &a,int b){if(b<a) a=b;}
template <class X, class Y>
bool cmin(X &a, const Y &b) {
    return a > b ? a = b, 1 : 0;
}
bool cmax(int &a,int b){
    if(b>a){a=b;return 1;} else return 0;
}
int a[22];
int dp[22][M*2];
signed main(){
    ///g++ grader.cpp .cpp -std=c++14 -O2 -Wl,--stack,10485760
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("1648E.inp","r",stdin);freopen("1648E.out","w",stdout);
    int n;
    cin>>n;
    for(int i=1;i<=n;i++) cin>>a[i];
    memset(dp,-0x3f,sizeof dp);
    //return 0;
    dp[0][MAX]=0;
    for(int i=1;i<=n;i++){
        for(int j=1;j<M;j++){

            dp[i][j]=dp[i-1][j];
            if(j>a[i])maxx(dp[i][j],dp[i-1][j-a[i]]+a[i]);
            if(j+a[i]<M) maxx(dp[i][j],dp[i-1][j+a[i]]);
        }
    }
    cout<<dp[n][MAX];

}
