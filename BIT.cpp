int sum(int k){
  int s = 0;
  while(k >= 1){
    s += tree[k];
    k -= k&-k;
  }
}

int update(int s,int k){
  while(k <= n){
    tree[k] += s;
    k += k&-k;
  }
} 
