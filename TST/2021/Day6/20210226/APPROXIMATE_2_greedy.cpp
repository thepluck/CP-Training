#include <bits/stdc++.h>
using namespace std;
int n;
class point_t{
public:
    int x, y;
    point_t(){}
    point_t(int x, int y): x(x), y(y){}
};
point_t p[100000];
double get(double a, double b){
    double res=0;
    for(int i=0; i<n; i++) res+=abs(a*p[i].x+b-p[i].y);
    return res;
}
void improve_a(double &a, double &b){
    double low=-2e6, high=2e6, llh, lhh;
    for(int i=0; i<60; i++){
        llh=(low+low+high)/3;
        lhh=(low+high+high)/3;
        double l=get(llh, b);
        double r=get(lhh, b);
        if(l<r) high=lhh;
        else low=llh;
    }
    a=(low+high)/2;
}
void improve_b(double &a, double &b){
    double low=-2e12, high=2e12, llh, lhh;
    for(int i=0; i<120; i++){
        llh=(low+low+high)/3;
        lhh=(low+high+high)/3;
        double l=get(a, llh);
        double r=get(a, lhh);
        if(l<r) high=lhh;
        else low=llh;
    }
    b=(low+high)/2;
}
int main(){
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);
    cin>>n;
    for(int i=0; i<n; i++) cin>>p[i].x>>p[i].y;
    double a=0, b=0;
    for(int i=0; i<25; i++){
        improve_a(a, b);
        improve_b(a, b);
    }
    cout<<setprecision(8)<<fixed<<get(a, b);
}