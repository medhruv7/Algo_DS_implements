compute_hash(string const&a){
  const int p = 31;
  const int m = 1e9 + 9;
  long long p_pow = 1;
  long long hash_val = 0;
  for(auto x : a){
    hash_val = (hash_val + (a - 'a' + 1)*p_pow)%m;
    p_pow = (p*p_pow)%m;
   }
   return hash_value;
}
