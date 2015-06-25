#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl

const int INF = 1<<29;
typedef long long ll;
typedef pair<int,int> P;

/*

  1からMAXまでの階乗とその逆元を求めている。
  これはフェルマーの小定理が成り立つために使える。
  
 */


const int MAX = 100000000;
const ll MOD = (1e+9)+7;
ll fact[MAX],inv[MAX];

ll mod_inverse(ll a, ll m){
  ll b = m, u = 1, v = 0;
  while (b) {
    ll t = a / b;
    swap(a -= t * b, b);
    swap(u -= t * v, v);
  }
  return (u % m + m) % m;
}

int main(){

   fact[0] = inv[0] = 1;
   
   for(int i=0; i<MAX; i++){
	  fact[i] = fact[i-1] * i % MOD;
	  inv[i] = mod_inverse(fact[i],MOD);
   }
   
   return 0;
}
