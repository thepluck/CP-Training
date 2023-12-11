#include <bits/stdc++.h>
using namespace std;
 
#define FOR(i, a, b, x) for (int i = (a); i x (b); ++i)
#define FORD(i, a, b, x) for (int i = (a); i x (b); --i)
#define all(v) (v).begin(), (v).end()
#define lb lower_bound
#define ub upper_bound
 
void init(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);
}
 
template <class T>
using vec = vector <T>;
template <class T>
using vec2d = vec <vec <T>>;
template <class T>
using vec3d = vec <vec2d <T>>;
 
mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
template <class key>
struct col;
 
template <class key>
struct cell;
 
template <class key, class cmp = less <key>>
struct skip_list;
 
template <class key>
struct col{
    key val;
    vec <cell <key>> cells;
};
 
template <class key>
struct cell{
    col <key> *prev_col, *next_col;
    cell(){
        prev_col = next_col = nullptr;
    }
    cell(col <key> *prev_col, col <key> *next_col):
        prev_col(prev_col), next_col(next_col) {}
};
 
template <class key, class cmp>
struct skip_list{
    static const int max_lv = 20;
    vec <key> old_cont;
    col <key> *head, *tail;
    skip_list(); ~skip_list();
    col <key>* find(key);
    col <key>* lb(key); col <key>* ub(key);
    pair <col <key>*, bool> insert(key);
    bool erase(key); bool empty();  
};
 
template <class key, class cmp>
skip_list <key, cmp>::skip_list(){
    head = new col <key>;
    tail = new col <key>;
    FOR(i, 0, max_lv, <){
        head->cells.push_back(cell <key> (nullptr, tail));
        tail->cells.push_back(cell <key> (head, nullptr));
    }
}
 
template <class key, class cmp>
skip_list <key, cmp>::~skip_list(){
    for (key x : old_cont) erase(x);
    delete head; delete tail;
}
 
template <class key, class cmp>
bool skip_list <key, cmp>::empty(){
    return head->cells[0].next_col == tail;
}
 
template <class key, class cmp>
col <key>* skip_list <key, cmp>::lb(key val){
    col <key> *iter = head;
    FORD(lv, max_lv - 1, 0, >=){
        while (iter->cells[lv].next_col != tail && 
        cmp()(iter->cells[lv].next_col->val, val))
        iter = iter->cells[lv].next_col;
    }
    return iter->cells[0].next_col;
}
 
template <class key, class cmp>
col <key>* skip_list <key, cmp>::ub(key val){
    col <key> *iter = head;
    FORD(lv, max_lv - 1, 0, >=){
        while (iter->cells[lv].next_col != tail &&
        !cmp()(val, iter->cells[lv].next_col->val))
        iter = iter->cells[lv].next_col;
    }
    return iter->cells[0].next_col;
}
 
template <class key, class cmp>
col <key>* skip_list <key, cmp>::find(key val){
    col <key>* temp = lb(val);
    if (temp != tail && !cmp()(val, temp->val) && !cmp()(temp->val, val))
        return temp;
    return tail;
}
 
template <class key, class cmp>
pair <col <key>*, bool> skip_list <key, cmp>::insert(key val){
    col <key>* temp = lb(val);
    if (temp != tail && !cmp()(val, temp->val) && !cmp()(temp->val, val))
        return make_pair(temp, false);
    col <key>* ins_col = new col <key>;
    ins_col->val = val;
    ins_col->cells.push_back(cell <key> (nullptr, nullptr));
    while (ins_col->cells.size() < max_lv && rng() % 2 == 0)
        ins_col->cells.push_back(cell <key> (nullptr, nullptr));
    col <key> *iter = head;
    FORD(lv, max_lv - 1, 0, >=){
        while (iter->cells[lv].next_col != tail &&
        cmp()(iter->cells[lv].next_col->val, val))
        iter = iter->cells[lv].next_col;
        if (lv < ins_col->cells.size()){
            col <key> *next_iter = iter->cells[lv].next_col;
            iter->cells[lv].next_col = ins_col;
            next_iter->cells[lv].prev_col = ins_col;
            ins_col->cells[lv].next_col = next_iter;
            ins_col->cells[lv].prev_col = iter;
        }
    }
    old_cont.push_back(val);
    return make_pair(ins_col, true);
}
 
template <class key, class cmp>
bool skip_list <key, cmp>::erase(key val){
    col <key> *era_col = lb(val);
    if (era_col == tail || cmp()(val, era_col->val) || cmp()(era_col->val, val))
        return false;
    col <key> *iter = head;
    FORD(lv, max_lv - 1, 0, >=){
        while (iter->cells[lv].next_col != tail &&
        !cmp()(val, iter->cells[lv].next_col->val))
        iter = iter->cells[lv].next_col;
        if (iter == era_col){
            col <key> *prev_iter = iter->cells[lv].prev_col;
            col <key> *next_iter = iter->cells[lv].next_col;
            prev_iter->cells[lv].next_col = next_iter;
            next_iter->cells[lv].prev_col = prev_iter;
        }
    }
    delete era_col;
    return true;
}
 
skip_list <int> sl;
 
int main(){
    init(); //open();
    int cmd, val;
    while (cin >> cmd){
        if (cmd == 0) return 0;
        if (cmd != 3 && cmd != 4) cin >> val;
        if (cmd == 1) sl.insert(val);
        if (cmd == 2) sl.erase(val);
        if (cmd == 3){
            if (sl.empty()) cout << "empty";
            else cout << sl.head->cells[0].next_col->val;
            cout << '\n';
        }
        if (cmd == 4){
            if (sl.empty()) cout << "empty";
            else cout << sl.tail->cells[0].prev_col->val;
            cout << '\n';
        }
        if (cmd == 5){
            if (sl.empty()) cout << "empty";
            else {
                auto iter = sl.ub(val);
                if (iter == sl.tail) cout << "no";
                else cout << iter->val;
            }
            cout << '\n';
        }
        if (cmd == 6){
            if (sl.empty()) cout << "empty";
            else {
                auto iter = sl.lb(val);
                if (iter == sl.tail) cout << "no";
                else cout << iter->val;
            }
            cout << '\n';
        }
        if (cmd == 7){
            if (sl.empty()) cout << "empty";
            else {
                auto iter = sl.lb(val)->cells[0].prev_col;
                if (iter == sl.head) cout << "no";
                else cout << iter->val;
            }
            cout << '\n';
        }
        if (cmd == 8){
            if (sl.empty()) cout << "empty";
            else {
                auto iter = sl.ub(val)->cells[0].prev_col;
                if (iter == sl.head) cout << "no";
                else cout << iter->val;
            }
            cout << '\n';
        }
    }
} 