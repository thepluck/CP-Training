#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

using namespace std;
using namespace __gnu_pbds;

typedef tree<
    int, null_type,
    less <int>, rb_tree_tag,
    tree_order_statistics_node_update>
ordered_set;

ordered_set X;

int main(){
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int q; cin >> q;
    char type; int val;
    while (q--){
        cin >> type >> val;
        switch (type){
            case 'I' : X.insert(val); break;
            case 'D' : X.erase(val); break;
            case 'K' :
                if (val > X.size() || val < 1)
                    cout << "invalid\n";
                else cout << *X.find_by_order(val - 1) << '\n';
                break;
            case 'C' :
                cout << X.order_of_key(val) << '\n';
                break;
        }
    }
    return 0;
}
