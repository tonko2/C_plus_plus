#include <bits/stdc++.h>
using namespace std;

const int INF = 1<<29;

int main(){
   int n,m;
   int a[101][101];
   cin >> n >> m;
   
   for(int i=0; i<n; i++)
	  for(int j=0; j<m; j++) cin >> a[i][j];

   int acum[101][101];
   memset(acum,0,sizeof(acum));


   for(int i=1; i<=n; i++){
	  for(int j=1; j<=m; j++){
		 int x = a[i-1][j-1];
		 acum[i][j] = x + acum[i-1][j] + acum[i][j-1] - acum[i-1][j-1];
	  }
   }


   int ans = 0;

   for(int i=1; i<=n; i++){
	  for(int j=1; j<=m; j++){
		 for(int k=i; k<=n; k++){
			for(int l=j; l<=m; l++){
			   int sum = acum[k][l] - acum[i-1][l] - acum[k][j-1] + acum[i-1][j-1];
			   ans = max(ans,sum);
			}
		 }
	  }
   }

   cout << ans << endl;
  
   return 0;
}
