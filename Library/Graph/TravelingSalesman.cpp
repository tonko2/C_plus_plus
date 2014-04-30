#include <iostream>
using namespace std;

const int INF = 1<<29;
int dp[1<<16][16];
int d[16][16];
int V,E;

int main(){

   fill(dp[0],dp[1<<15],INF);
   fill(d[0],d[15],INF);
  
   cin >> V >> E;
   for(int i=0; i<E; i++){
      int from,to,cost;
      cin >> from >> to >> cost;
      d[from][to] = cost;
   }

   dp[(1<<V)-1][0] = 0;

   for(int S=(1<<V)-2; S>=0; S--){
      for(int i=0; i<V; i++){
         for(int j=0; j<V; j++){
            if(!(S & (1<<j))){
               dp[S][i] = min(dp[S][i],dp[S|(1<<j)][j] + d[i][j]);
            }
         }
      }
   }
   cout << dp[0][0] << endl;
   return 0;
}
