#include<bits/stdc++.h>
using namespace std;

template<typename T>
T binpow(T a,T b){
	T res = 1;
	while(b){
		if(b&1){
			res *= a;
		}
		b >>= 1;
		a *= a;
	}
	return res;
}