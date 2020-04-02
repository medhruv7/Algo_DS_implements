vector<vector<int>> st[mxn][k + 1];

for(int i = 0;i < n; ++i){
	st[i][0] = f(a[i]);
}

for(int j = 1;j <= k; ++j){
	for(int i = 0;(i + 1<<(j - 1)) < n; ++i){
		st[i][j] = f(st[i][j - 1],st[i + (1<<(j - 1))][j - 1]);
	}
}

int sum(int l,int r){
	int ans = 0;
	for(int j = k;j >= 0;--j){
		if((1<<j) <= (l - r + 1)){
			ans += st[l][j];
			l += (1<<j);
		}
	}
}



