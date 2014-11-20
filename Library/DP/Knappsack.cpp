
void solve(){
   const int MAX = 1000;
   int N,W;
   int w[MAX],v[MAX];
   int dp[MAX+1][MAX+1];
   fill(dp[0],dp[MAX+1],0);

   for(int i=0; i<N; i++){
	  for(int j=0; j<=W; j++){
		 dp[i+1][j] = max(dp[i+1][j],dp[i][j]);
		 if(w[i] + j <= W){
			dp[i+1][j+w[i]] = max(dp[i+1][j+w[i]], dp[i][j] + v[i]);
		 }
	  }
   }
}
   
