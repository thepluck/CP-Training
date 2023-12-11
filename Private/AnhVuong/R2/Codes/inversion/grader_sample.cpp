#include <cstdio>
#include <cstdlib>
#include <algorithm>
#include "inversion.h"
using namespace std;

const int maxN = 100001;
const int maxSwaps = 200000;
int __a[maxN+1];


int __N;
long long __Inv;
int __swapsCount=0;

long long CountInv()
{
    long long invcount=0;
    for (int i=1;i<__N;i++)
       for (int j=i+1;j<=__N;j++)
          if (__a[i]>__a[j]) invcount++;
    return invcount;
}

long long doswap(int i, int j){
   if ((i==j) || (i < 1) || (j < 1) || (i > __N) || (j > __N)){
      printf("Invalid swap query! %d %d\n", i, j);
      exit(0);
   }
   __swapsCount++;
   if (__swapsCount > maxSwaps){
      printf("Over 200000 swaps!\n");
      exit(0);
   }
   swap(__a[i], __a[j]);

   return CountInv();
}

void answer(int p[]){

   for (int q=1;q<__N;q++)
      printf("%d ",p[q]);
   printf("%d\n", p[__N]);
}

int main() {
    scanf("%d", &__N);
    for (int i=1;i<=__N;i++)
        scanf("%d", &__a[i]);

    play(__N, CountInv());

    return 0;
}
