vector<bool> primes(mxn + 1,true);

primes[0] = primes[1] = false;
for(int i = 2;i*i <= mxn; ++i){
	if(primes[i]){
		for(int j = i*i; j <= mxn; j += i){
			primes[j] = false;
		}
	}
}
