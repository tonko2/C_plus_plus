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



   /*
	 高速なLIS
	 O(N*logN)
   */

   vector<int> dp2(N+10,INF);
   for(int i=0; i<N; i++)
	  *lower_bound(dp2.begin(),dp2.end(),a[i]) = a[i];

   cout << lower_bound(dp2.begin(),dp2.end(),INF) - dp2.begin() << endl;
   
   return 0;
}
