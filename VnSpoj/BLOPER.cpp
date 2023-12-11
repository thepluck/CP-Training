#include<stdio.h>
bool Check(long L,long R,long S)
{
    if(S>R || S<L || S==R-2 || S==L+2) return false;
    return true;
}
void Print(long L,long R,long n,long S)
{
    if(n==1) {printf("1");return;}
    if(Check(L+n,R-n,S-n)) {Print(L+n,R-n,n-1,S-n);printf("+%ld",n);}
    else {Print(L+n,R-n,n-1,S+n);printf("-%ld",n);}
}
int main()
{
    long n,S,L,R;
    scanf("%ld%ld",&n,&S);
    R=(n+1)*n/2;
    L=2-R;
    if((S+R)%2) printf("Impossible");
    else if(!Check(L,R,S)) printf("Impossible");
    else Print(L,R,n,S);
}