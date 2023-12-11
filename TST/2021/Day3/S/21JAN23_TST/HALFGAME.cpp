#include<bits/stdc++.h>
using namespace std;
typedef long long ll;

int32_t main(int32_t argc,char** argv){
    if (argc>1) freopen(argv[1],"r",stdin);
    if (argc>2) freopen(argv[2],"w",stdout);
    for (int t=5;t--;){
        int n;
        scanf("%d",&n);
        ll g = 0;
        while(n--){
            ll a;
            scanf("%lld",&a);
            if (a&1) g ^= (a+1)/2;
            else {
                for (int cnt=0;cnt<2;){
                    cnt += (a&1)==0;
                    a>>=1;
                }
                g ^= a;
            }
        }
        if (g) printf("yes\n");
        else printf("no\n");
    }
}
