//２つの文字列の最大共通分文字列を求める

#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl

const int INF = 1<<29;
typedef long long ll;
typedef pair<int,int> P;

const int MAX_N = 1000;
const int MAX_M = 1000;

int main(){
   int n,m;
   string s,t;
   cin >> n >> m >> s >> t;

   int dp[MAX_N+1][MAX_M+1];

   for(int i=0; i<n; i++){
	  for(int j=0; j<m; j++){
		 if(s[i] == t[j]) dp[i+1][j+1] = dp[i][j] + 1;
		 else dp[i+1][j+1] = max(dp[i+1][j],dp[i][j+1]);
	  }
   }

   cout << dp[n][m] << endl;

   
   return 0;
}
