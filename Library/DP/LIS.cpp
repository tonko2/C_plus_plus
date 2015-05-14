#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl

const int INF = 1<<29;
typedef long long ll;
typedef pair<int,int> P;


int main(){
   int N;
   int a[1001];
   int dp[1001];
   fill(dp,dp+1001,0);

   cin >> N;
   for(int i=0; i<N; i++) cin >> a[i];
   
   int ans = 1;
   for(int i=0; i<N; i++){
	  dp[i] = 1;
	  for(int j=0; j<i; j++){
		 if(a[j] < a[i])
			dp[i] = max(dp[i],dp[j]+1);
	  }
	  ans = max(ans,dp[i]);
   }

   cout << ans << endl;
   
   return 0;
}
