#include <string>
#include <cstring>
#include <cstdio>
#include <vector>
#include <cmath>
#include <iostream>
#include <cstdlib>

using namespace std;

const int maxn = 1e6 + 10;
char s[maxn], t[maxn];
int pre[maxn], n, m;

void kmp(){
    for (int i = 1, j = 0; t[i]; i++){
        while (j > 0 && t[i] != t[j]) j = pre[j - 1];
        if (t[i] == t[j]) j++; pre[i] = j;
    }
}

void match(){
    for (int i = 0, j = 0; s[i]; i++){
        while (j > 0 && s[i] != t[j]) j = pre[j - 1];
        if (s[i] == t[j]) j++;
        if (j == m){
            printf("%d ", i - m + 2); j = pre[j - 1];
        }
    }
}

int main(){
    scanf("%s", s); scanf("%s", t);
    n = strlen(s); m = strlen(t);
    kmp(); match();
}
