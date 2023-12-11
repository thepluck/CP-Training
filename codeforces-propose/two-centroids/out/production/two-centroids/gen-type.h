#include "testlib.h"
#include <bits/stdc++.h>
 
using namespace std;
 
vector <pair <int, int>> prufer_decode(const vector <int>& code){
    int n = (int)code.size() + 2;
    vector <int> degree(n, 1);
    for (int i: code){
        degree[i]++;
    }
 
    int ptr = 0;
    while (degree[ptr] != 1){
        ptr++;
    }
    int leaf = ptr;
 
    vector <pair <int, int>> edges;
    for (int v: code){
        edges.emplace_back(leaf, v);
        if (--degree[v] == 1 && v < ptr){
            leaf = v;
        }
        else{
            ptr++;
            while (degree[ptr] != 1){
                ptr++;
            }
            leaf = ptr;
        }
    }
    edges.emplace_back(leaf, n - 1);
    return edges;
}
 
void generate_binary_tree(int cur, int p, int n, vector <pair <int, int>>& edges, int bias) {
    if (n == 0) return;
    if (p != -1) edges.emplace_back(p, cur);
 
    int x = rnd.wnext(0, n / 2, bias);
    int l = n / 2 - x;
    int r = n - 1 - l;
 
    generate_binary_tree(cur + 1, cur, l, edges, bias);
    generate_binary_tree(cur + l + 1, cur, r, edges, bias);
}
 
vector <pair <int, int>> random_tree(int n, int bias, string tree_type){
    if (n == 1){
        return {};
    }
 
    if (tree_type == "normal") {
        vector <int> code(n - 2);
        if (bias == 0){
            for (auto &val: code){
                val = rnd.next(0, n - 1);
            }
        }
        else{
            int number_of_distinct_values = rnd.wnext(1, n, bias);
            vector <int> values = rnd.distinct(number_of_distinct_values, 0, n - 1);
            for (auto &val: code){
                val = values[rnd.next(0, number_of_distinct_values - 1)];
            }
        }
        vector <pair <int, int>> edges = prufer_decode(code);
        return edges;
    }
    else if (tree_type == "binary") {
        vector <pair <int, int>> edges;
        vector <int> nodes;
        for (int i = 0; i < n; i++) nodes.push_back(i);
        shuffle(nodes.begin(), nodes.end());
 
        generate_binary_tree(0, -1, n, edges, bias);
        return edges;
    }
    else if (tree_type == "caterpillar") {
        vector <pair <int, int>> edges;
        int line_length = rnd.wnext(1, n, bias);
        vector<int> line_nodes = rnd.distinct(line_length, 0, n - 1);
 
        for (int i = 1; i < (int)line_nodes.size(); i++) {
            edges.emplace_back(line_nodes[i - 1], line_nodes[i]);
        }
        sort(line_nodes.begin(), line_nodes.end());
 
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (cur < (int)line_nodes.size() && i == line_nodes[cur]) cur++;
            else {
                edges.emplace_back(i, rnd.any(line_nodes));
            }
        }
        return edges;
    }
    else if (tree_type == "sperm") {
        vector <pair <int, int>> edges;
        int line_length = rnd.wnext(1, n, bias);
        vector<int> line_nodes = rnd.distinct(line_length, 0, n - 1);
 
        for (int i = 1; i < (int)line_nodes.size(); i++) {
            edges.emplace_back(line_nodes[i - 1], line_nodes[i]);
        }
        int lst = line_nodes.back();
        sort(line_nodes.begin(), line_nodes.end());
 
        int cur = 0;
        for (int i = 0; i < n; i++) {
            if (cur < (int)line_nodes.size() && i == line_nodes[cur]) cur++;
            else {
                edges.emplace_back(i, lst);
            }
        }
        return edges;
    }
 
    return {};
}
 
int convert(int l, int r, double per) {
    int dcm = per * 4;
    if (dcm == 0) return l;
    if (dcm == 1) return -sqrt(r);
    if (dcm == 2) return 0;
    if (dcm == 3) return sqrt(r);
    return r;
}
 
void print_graph(vector<pair<int, int>> edges) {
    shuffle(edges.begin(), edges.end());
    for (auto &e : edges) if (rnd.next(0, 1)) swap(e.first, e.second);
 
    int n = (int)edges.size() + 1;
    cout << n << "\n";
    if (n != 1) {
        for (auto e : edges) cout << e.first + 1 << " " << e.second + 1 << "\n";
    }
}
 
void print_parents(vector<pair<int, int>> edges) {
    int n = edges.size() + 1;
    for (auto [u, v] : edges)
        assert(u < n && v < n);
    
    vector<vector<int>> adj(n);
    vector<int> par(n, -1);
    vector<int> ind(n);
    vector<int> ans(n - 1);
    
    for (auto e : edges) {
        adj[e.first].push_back(e.second);
        adj[e.second].push_back(e.first);
    }
    
    priority_queue<pair<int, int>> pq;
    pq.emplace(rnd.next(0, 1000000000), rnd.next(n));
    
    for (int id = 0; id < n; id++) {
        assert(pq.size());
        int u = pq.top().second; pq.pop();
        ind[u] = id;
        for (int v : adj[u])
            if (v != par[u]) {
                par[v] = u;
                pq.emplace(rnd.next(0, 1000000000), v);
            }
    }
    for (int u = 0; u < n; u++)
        if (ind[u]) ans[ind[u] - 1] = ind[par[u]] + 1;
    cout << n << '\n';
    for (int i = 0; i < n - 1; i++)
        cout << ans[i] << " \n"[i == n - 2];
}
 
vector<int> max_partition(int test_count, int sum_n, int min_part, int max_part) {
    vector<int> res;
    for (int i = 1; i <= test_count; i++) res.push_back(min_part);
    sum_n -= min_part * test_count;
    
    while (sum_n > 0) {
        int id = rnd.next(0, test_count - 1);
        if (res[id] == max_part) continue;
        res[id]++;
        sum_n--;
    }
 
    return res;
}
