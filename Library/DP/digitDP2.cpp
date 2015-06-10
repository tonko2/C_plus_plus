/*
  区間 [A,B] に含まれる禁止された数(4と7)がいくつ含まれているかを 1 行に出力せよ。
  1 <= A <= B <= 10^18
*/


#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl

const int INF = 1<<29;
const int MOD = (int)(1e+9) + 7;
typedef long long ll;
typedef pair<int,int> P;

ll dp[20][10][2];

ll count(ll n){
   if(n == 0) return 0;


   int len = log10(n) + 1;
   int num[len];

   for(int i=0; i<len; i++){
	  num[len-i-1] = n % 10;
	  n /= 10;
   }

   memset(dp,0,sizeof(dp));   
   dp[0][0][0] = 1;

   for(int i=0; i<len; i++){
	  for(int j=0; j<10; j++){
		 if(j == 4 || j == 9)continue;
		 for(int k=0; k<=1; k++){
			if(!dp[i][j][k])continue;

			//制限あり
			if(k == 0){
			   int lim = num[i];
			   for(int l=0; l<lim; l++){
				  if(l == 4 || l == 9)continue;
				  dp[i+1][l][1] += dp[i][j][0];
			   }
			   dp[i+1][lim][0] += dp[i][j][0];
			}

			//制限なし
			else {
			   for(int l=0; l<10; l++){
				  if(l == 4 || l == 9) continue;
				  dp[i+1][l][1] += dp[i][j][1];
			   }
			}
		 }
	  }
   }

   ll res = 0;
   for(int i=0; i<10; i++){
	  if(i == 4 || i == 9)continue;
	  res += dp[len][i][0] + dp[len][i][1];
   }
   return res - 1;
}

int main(){
   ll A,B;
   cin >> A >> B;
   cout << (B - A + 1) - (count(B) - count(A-1)) << endl;
   return 0;
}
