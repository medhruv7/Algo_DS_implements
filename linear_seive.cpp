#include<bits/stdc++.h>
using namespace std;


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


// getting the prime factorisation

vector<int> getfc(int n){
	vector<int> fact;
	while(n != 1){
		int x = lp[n];
		fact.push_back(x);
		while(n%x == 0){
			n /= x;
		}
	}
	return fact;
}
