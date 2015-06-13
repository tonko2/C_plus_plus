#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl

const int INF = 1<<29;
typedef long long ll;
typedef pair<int,int> P;

const int DAT_SIZE = (1<<18)-1;
int N,Q;

//セグメント木
ll data[DAT_SIZE], datb[DAT_SIZE];

// [a,b)にxを加算する
// kは節点の番号で、区間[l,r)に対応する

void add(int a, int b, int x, int k, int l, int r){
   if(a <= l && r <= b) data[k] += x;
   else if(l < b && a < r){
	  datb[k] += (min(b,r) - max(a,l)) * x;
	  add(a,b,x,k*2+1,l,(l+r)/2);
	  add(a,b,x,k*2+2,(l+r)/2,r);
   }
}

// [a,b)の和を計算する
// kは節点の番号で、区間[l,r)に対応する
ll sum(int a, int b, int k, int l, int r){
   if(b <= l || r <= a) return 0;
   else if(a <= l && r <= b) return data[k] * (r-l) + datb[k];
   else {
	  ll res = (min(b,r) - max(a,l)) * data[k];
	  res += sum(a,b,k*2+1,l,(l+r)/2);
	  res += sum(a,b,k*2+2,(l+r)/2,r);
	  return res;
   }
}



void solve(){
   
   //[0,3)の範囲に4を足す
   add(0,3,4,0,0,N);

   //[0,3)の範囲の和を計算する
   cout << sum(0,3,0,0,N) << endl;

   
}
int main(){
   return 0;
}
