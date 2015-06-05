#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl

const int INF = 1<<29;
typedef long long ll;
typedef pair<int,int> P;

const int DAT_SIZE = (1<<18)-1;
int N,Q;
int A[101];

int L[101], R[101], X[101];

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

int main(){
   return 0;
}
