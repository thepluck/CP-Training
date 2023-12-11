#include <bits/stdc++.h>
using namespace std;
#define int long long
const int mod=1e9+7;
using ll = long long;
using ii = pair <int, int>;
int mpow(int x, int k) {
    int res = 1;
    for (; k; k >>= 1, x = ll(x) * x % mod)
        if (k & 1) res = ll(res) * x % mod;
    return res;
}
int dp[1002][6];
signed main(){
    int n,k;
    cin>>n>>k;
    if(k==2){
        cout<<(n-1)/2;return 0;
    }
    
    if(k==1){
        cout<<1;return 0;
    }
    if(k==3){
        int ans=1;
        for(int i=1;i<=2;i++){
            ans=ans*(n-i)%mod;
        }
        ans=ans*mpow(2,mod-2)%mod;
        //cout<<ans<<'\n';
        ans-=(n-1)/2*3;
        //else ans-=(n/2)*3-3;
        if(n%3==0) ans+=2;
        ans = (ans % mod + mod) % mod;
        cout<<ans*mpow(6,mod-2)%mod;
        return 0;
    }
    
    if(n<=1000){
        dp[0][0]=1;
        for(int i=1;i<=n;i++){
            for(int j=n;j>=i;j--){
                for(int u=1;u<=k;u++){
                    (dp[j][u]+=dp[j-i][u-1])%=mod;
                }
                
            }
        }
        cout<<dp[n][k];
        return 0;
    }
    if(k==4){
        int ans=1;
        for(int i=1;i<=3;i++){
            ans=ans*(n-i)%mod;
        }
        ans=ans*mpow(6,mod-2)%mod;
        int m=n-(n&1)-2;
        int b=n-3,e=n-m-1;
        ans-=(b+e)*((b-e)/2+1)/2*6;
        m=(n-1)/3;
        ans+=2*m*4;
        if(n%4==0) ans-=3;
        ans = (ans % mod + mod) % mod;
        cout<<ans*mpow(24,mod-2)%mod;
        return 0;
    }
    if(k==5){
        int ans=1;
        for(int i=1;i<=4;i++){
            ans=ans*(n-i)%mod;
        }
        ans=ans*mpow(24,mod-2)%mod;
        int b=n%3+3;
        int e=n-3;
        /// c 2 b-1  =>  c 2 e-1
        if(b<=e){
            ans-=(b+e)*((e-b)/3+1)/2;
            ans-=()
        }
        int m=n-(n&1)-2;
        int b=n-3,e=n-m-1;
        ans-=(b+e)*((b-e)/2+1)/2*6;
        m=(n-1)/3;
        ans+=2*m*4;
        if(n%4==0) ans+=4;
        ans = (ans % mod + mod) % mod;
        cout<<ans*mpow(120,mod-2)%mod;
        return 0;
    }

}