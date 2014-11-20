#include <iostream>
using namespace std;

const int INF = 1<<29;

int main(){
   int n;
   int a[101][101];
   int sum[102][102];
  
   while(cin >> n){
      fill(sum[0],sum[101],0);
      int ans = -INF;
      for(int i=1; i<=n; i++)
         for(int j=1; j<=n; j++) cin >> a[i][j];

      for(int i=1; i<=n; i++){
         for(int j=1; j<=n; j++){
            sum[i][j] = a[i][j] + sum[i][j-1] + sum[i-1][j] - sum[i-1][j-1];
         }
      }

      for(int i=1; i<=n; i++){
         for(int j=1; j<=n; j++){
            for(int k=1; k<=n; k++){
               for(int l=1; l<=n; l++){
                  if(i <= k && j <= l){
                     int value = sum[k][l] - sum[k][j-1] - sum[i-1][l] + sum[i-1][j-1];
                     ans = max(ans,value);
                  }
                 
               }
            }
         }
      }

     
      cout << ans << endl;
   }
  
   return 0;
}
