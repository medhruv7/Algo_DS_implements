#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> tr,a;
// 1 indexed BIT
int sum(int i){
    int sm = 0;
    while(i >= 1){
        sm += tr[i];
        i -= (i&-i);
    }
    return sm;
}

int sumr(int l,int r){
    return sum(l) - sum(r - 1);
}

void upd(int i,int del){
    while(i < n){
        tr[i] = del;
        i += (i&-i);
    }
}

void build(){
    for(int i = 0;i < n; ++i){
        upd(i + 1,a[i]);
    }
}

