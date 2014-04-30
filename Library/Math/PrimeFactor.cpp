map<ll,int> prime_factor(ll x){
   map<ll,int>res;
   for(ll i=2; i*i<=x; i++){
      while(x % i == 0){
         res[i]++;
         x /= i;
      }
   }
   if(x != 1) res[x] = 1;
   return res;
}
