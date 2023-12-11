#include <bits/stdc++.h>
using namespace std;

void downHeap(vector <int>& heap, int i){
    int x = heap[i], c;
    while (true){
        c = i << 1 | 1;
        if (c + 1 < (int)heap.size() && heap[c + 1] > heap[c]) c++;
        if (c >= (int)heap.size() || heap[c] <= x) break;
        heap[i] = heap[c]; i = c;
    }
    heap[i] = x;
}

void upHeap(vector <int>& heap, int i){
    int x = heap[i], c = heap.size();
    while (c > 0){
        c = (i - 1) >> 1;
        if (heap[c] >= x) break;
        heap[i] = heap[c]; i = c;
    }
    heap[i] = x;
}

void Heapify(vector <int>& heap, int i, int n){
    int lar = i, l = i << 1 | 1, r = (i + 1) << 1;
    if (l < n && heap[l] > heap[lar]) lar = l;
    if (r < n && heap[r] > heap[lar]) lar = r;
    if (lar != i){
        swap(heap[i], heap[lar]);
        Heapify(heap, lar, n);
    }
}

void buildHeap(vector <int>& heap){
    for (int i = (int)heap.size() / 2 - 1; i >= 0; i--)
        Heapify(heap, i, (int)heap.size());
}

void heapSort(vector <int>& heap){
    buildHeap(heap);
    for (int i = (int)heap.size() - 1; i >= 0; i--)
        swap(heap[i], heap[0]),
        Heapify(heap, 0, i);
}

void pushHeap(vector <int>& heap, int x){
    heap.push_back(x);
    upHeap(heap, (int)heap.size() - 1);
}

void popHeap(vector <int>& heap, int i){
    int y = heap.back(); heap.pop_back();
    int x = heap[i]; heap[i] = y;
    if (x < y) upHeap(heap, i);
    else downHeap(heap, i);
}

int main(){
    int n; cin >> n;
    vector <int> heap(n);
    for (int i = 0; i < n; i++)
        cin >> heap[i];
    buildHeap(heap); pushHeap(heap, 12);
    popHeap(heap, 4);
    for (int i = 0; i < (int)heap.size(); i++)
        cout << heap[i] << ' ';
}
