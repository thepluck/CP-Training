#include<bits/stdc++.h>
using namespace std;
const int nmax=100011, base=1000000007;

int c[100][100];

int32_t main(int32_t argc,char** argv){
    if (argc>1 && freopen(argv[1],"r",stdin));
    if (argc>2 && freopen(argv[2],"w",stdout));
    c[0][0]=1;
    for (int i=1;i<100;++i){
        c[0][i]=1;
        for (int j=1;j<=i;++j) c[j][i]=(c[j][i-1]+c[j-1][i-1])%base;
    }
    int n,g=0;
    vector<int> a;
    scanf("%d",&n);
    while(n--){
        long long k;
        scanf("%lld",&k);
        if (k==0) continue;
        a.push_back(__builtin_popcountll(k));
        g^=a.back();
    }
    int ans=0;
    for (int x:a){
        int k=g^x;
        if (k>=x) continue;
        ans=((1LL<<(63-x))%base*c[k][x]+ans)%base;
    }
    cout<<ans;
}
