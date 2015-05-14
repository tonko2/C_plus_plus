#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl

const int INF = 1<<29;
typedef long long ll;
typedef pair<int,int> P;

const int MAX_W = 1000;
const int MAX_N = 100;
const int MAX_V = 100;

//通常のナップザック問題
void solve(){
   int N,W;
   int w[MAX_N],v[MAX_N];
   int dp[MAX_N+1][MAX_W+1];
   fill(dp[0],dp[MAX_N+1],0);

   for(int i=0; i<N; i++){
	  for(int j=0; j<=W; j++){
		 dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
		 if(w[i] + j <= W){
			dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]], dp[i][j] + v[i]);
		 }
	  }
   }
   cout << dp[N][W] << endl;
}

//一次元のナップサック(個数制限ある場合は右から左)
void solve2(){
   int N,W;
   int w[MAX_N],v[MAX_N];
   int dp[MAX_W+1];
   fill(dp,dp+MAX_W+1,0);

   for(int i=0; i<N; i++){
	  for(int j=W; j>=w[i]; j--){
		 dp[j] = max(dp[j],dp[j-w[i]] + v[i]);
	  }
   }
   
   cout << dp[W] << endl;
   
}

//個数制限なしナップサック(個数制限ない場合はループは左から右、ただし、dp[i+1] = max(dp[i] + hogeみたいな場合は
//左から右でもOK)
void solve3(){
   int N,W;
   int w[MAX_N],v[MAX_N];
   int dp[MAX_N+1][MAX_W+1];
   fill(dp[0],dp[MAX_N+1],0);

   for(int i=0; i<N; i++){
	  for(int j=0; j<=W; j++){
		 if(j < w[i]) dp[i+1][j] = dp[i][j];
		 else dp[i+1][j] = max(dp[i][j],dp[i+1][j-w[i]] + v[i]);
	  }
   }
   
   cout << dp[N][W] << endl;
   
}

//Wが10^7になったナップサック問題
void solve4(){
   int N,W;
   int w[MAX_N],v[MAX_N];
   int dp[MAX_N+1][MAX_N * MAX_V + 1];
   fill(dp[0],dp[MAX_N+1],0);

   for(int i=0; i<N; i++){
	  for(int j=0; j<=MAX_N * MAX_V; j++){
		 if(j < v[i]) dp[i+1][j] = dp[i][j];
		 else dp[i+1][j] = min(dp[i+1][j],dp[i][j-v[i]] + w[i]);
	  }
   }

   int res = 0;
   for(int i=0; i<=MAX_N*MAX_V; i++) if(dp[N][i] <= W) res = i;
   cout << res << endl;
}

int main(){
   solve();
   solve2();
   solve3();
   solve4();
}

   
