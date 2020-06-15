const int N = 10000000;
int lp[N + 1];
vector<int> pr;

void ls(){
	for(int i = 2;i <= N; ++i){
		// means prime
		if(lp[i] == 0){
			lp[i] = i;
			pr.push_back(i);
		}
		for(int j = 0;j < pr.size() && pr[j] <= lp[i]; j++){
			lp[i*pr[j]] = pr[j];
		}
	}
}

