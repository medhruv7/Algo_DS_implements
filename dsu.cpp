#include<bits/stdc++.h>
using namespace std;

vector<int> par,sz;

int getPar(int n){
    return (n == par[n] ? n : par[n] = getPar(par[n]));
}

void unite(int x,int y){
    x = getPar(x);
    y = getPar(y);
    if(x == y) return;
    if(sz[x] < sz[y]) swap(x,y);
    par[y] = x;
    sz[y] += sz[x];
    sz[x] = 1;
    return;
}

void init(int n){
    par.resize(n);
    sz.resize(n);
    for(int i = 0; i < n; ++i){
        par[i] = i;
        sz[i] = 1;
    }
}
