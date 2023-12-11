#include <bits/stdc++.h>
using namespace std;
 
bool get_bit(int x, int i){
    return (x >> i) & 1;
}
 
using ii = pair <int, int>;
bool used[70000]; 
queue <ii> q; char x;
int first, last, curr, step;
 
int main(){
    for (int i = 0; i < 16; i++){
        cin >> x; first = first * 2 + x - '0';
    }
    for (int i = 0; i < 16; i++){
        cin >> x; last = last * 2 + x - '0';
    }
    used[first] = true; q.push({first, 0});
    while (!q.empty()){
        tie(curr, step) = q.front(); q.pop();
        if (curr == last) return cout << step << '\n', 0;
        for (int i = 0, nxt; i < 16; i++){
            if (i >= 4){
                nxt = curr ^ (1 << i) ^ (1 << (i - 4));
                if (!used[nxt] && get_bit(curr, i) && !get_bit(curr, i - 4)){
                    used[nxt] = true; q.push({nxt, step + 1});
                }
            }
            if (i < 12){
                nxt = curr ^ (1 << i) ^ (1 << (i + 4));
                if (!used[nxt] && get_bit(curr, i) && !get_bit(curr, i + 4)){
                    used[nxt] = true; q.push({nxt, step + 1});
                }
            }
            if (i % 4 != 0){
                nxt = curr ^ (1 << i) ^ (1 << (i - 1));
                if (!used[nxt] && get_bit(curr, i) && !get_bit(curr, i - 1)){
                    used[nxt] = true; q.push({nxt, step + 1});
                }
            }
            if (i % 4 != 3){
                nxt = curr ^ (1 << i) ^ (1 << (i + 1));
                if (!used[nxt] && get_bit(curr, i) && !get_bit(curr, i + 1)){
                    used[nxt] = true; q.push({nxt, step + 1});
                }
            }
        }
    }
    
}