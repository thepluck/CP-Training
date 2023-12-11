#define X first
#define Y second
#define pb push_back
#include <iostream>

using namespace std;
const int MAX=12,M=1024*30+2,MAX2=(1<<6) +2,inf=0x3f3f3f3f;
typedef pair < int, int > ii;
typedef pair < int , ii > iii;
using ll = long long;
using ld = long double;
void maxx(int &a,int b) {if(b>a) a=b;}
int dp[MAX][MAX][M];
int cnt(int n,int m,int c){
    //cout<<n<<' '<<m<<' '<<c<<'\n';
    if(c>M) return M;

    if(n>m) swap(n,m);
    if(dp[n][m][c]!=-1) return dp[n][m][c];
    if(!n || !m) {
        return dp[n][m][c]=c<<(n+m);
    }
    if(n==m){
        dp[n][m][c]=cnt(n-1,m,c);
        return dp[n][m][c];
    }
    else{
        for(int i=0;i<c;i++){
            maxx(dp[n][m][c],min(cnt(n,m-1,c+i),cnt(n-1,m,c-i)));
        }
        return dp[n][m][c];
    }

}
int main()
{
    ios::sync_with_stdio(0);cin.tie(0);cout.tie(0);
    //freopen("cardgame.inp","r",stdin);
    //freopen("cardgame.out","w",stdout);
    memset(dp,-1,sizeof dp);
    int n,m,c;
    while(cin>>n>>m>>c){
        if(n>m) swap(n,m);
        cout<<cnt(n,m,c)<<'\n';
    }


}
