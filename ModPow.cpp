
//繰り返し２乗法
ll mod_pow(ll x, ll n, ll mod){
   if(n == 0) return 1;
   ll res = mod_pow((x*x)%mod,n/2,mod);
   if(n & 1) res = (res * x) % mod;
   return res;
}

//繰り返し２乗法 (行列)
vector<int> multi(vector<int>& matrix, int k){
   if(k == 1) return matrix;

   vector<int> tmp = multi(matrix,k/2);
   if(k % 2){
      // 行列 * (行列*行列)という繰り返し２乗法
      return calc(matrix,calc(tmp,tmp));
   } else {
      // 繰り返し２乗法
      return calc(tmp,tmp);
   }
}
