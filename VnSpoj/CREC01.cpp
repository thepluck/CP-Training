	
#include <iostream>
#include <cstring>
#define MAXN 1001
 
int stack[MAXN],h[MAXN],m,n;
long long res,calc[MAXN];
char s[MAXN];
 
int main()
{
    int i,j,top,tmp;
    
    //freopen("crec01.inp","r",stdin);
    //freopen("crec01.out","w",stdout);
    
    scanf("%d%d", &m, &n);
    res = 0;
    gets(s);
    
    h[0] = -1;
    for (i = 1; i <= m; i++)
      {
           gets(s);
           for (j = 1; j <= n; j++)
             if (s[j - 1] == '1') h[j]++;
               else h[j] = 0;
               
           top = 0;
           for (j = 1; j <= n; j++)
             {
               while (h[stack[top]] >= h[j]) top--;
               tmp = stack[top];
               
               calc[j] = (j - tmp) * h[j] + calc[tmp];
               res += calc[j];
               
               top++;
               stack[top] = j;
             }
      }
      
    printf("%lld", res);
}