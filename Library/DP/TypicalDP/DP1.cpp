/*
  ナップザック問題に使っても良い個数の制限ついた版
  N(個数)
  W(入れられる重さ) K(入れていい個数)
  必ずK個使う必要はない
  
    Input
    10
    5 4
    9 10
    3 7
    3 1
    2 6
    4 5

	Output
	18

*/

#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl

const int INF = 1<<29;
typedef long long ll;
typedef pair<int,int> P;


int dp[51][10001];

int main(){
   int W,N,K;
   cin >> W;
   cin >> N >> K;
   int v[N],w[N];

   for(int i=0; i<N; i++){
	  cin >> w[i] >> v[i];
	  for(int j=K-1; j>=0; j--){
		 for(int k=0; k<=W; k++){
			if(k+w[i]>W)continue;
			dp[j+1][k+w[i]] = max(dp[j+1][k+w[i]],dp[j][k]+v[i]);
		 }
	  }
   }

   int ans = 0;
   for(int i=0; i<=K; i++)
	  for(int j=0; j<=W; j++) ans = max(ans,dp[i][j]);

   cout << ans << endl;

   return 0;
}
