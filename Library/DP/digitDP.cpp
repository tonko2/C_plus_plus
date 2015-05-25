/*
  N以下の正整数で、各桁の数の和がDの倍数であるものの個数を mod 1,000,000,007 で求めよ。
  1 <= N <= 10^100000
  1 <= D <= 100
*/

#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl

const int INF = 1<<29;
const int MOD = (int)(1e+9) + 7;
typedef long long ll;
typedef pair<int,int> P;

int D;
string N;

/*
  dp[pos][sum][sml] := pos桁目まで見た時、各桁の和modDがsumで、与えられた数より
  小さいかどうか(sml)であるような数の個数
*/

int dp[10001][101][2];

int main(){
   cin >> D >> N;
   memset(dp,sizeof(dp),0);
   int len = N.size();

   dp[0][0][0] = 1;

   for(int pos=0; pos<len; pos++){
	  for(int sum=0; sum<D; sum++){
		 for(int sml=0; sml<=1; sml++){
			if(!dp[pos][sum][sml]) continue; //ここまでのパスが存在しない場合

			//次へのパスに制限がない場合
			if(sml == 1){
			   int lim = 10;
			   for(int d=0; d<lim; d++)
				  dp[pos+1][(sum+d)%D][1] = (dp[pos+1][(sum+d)%D][1] + dp[pos][sum][1]) % MOD;
			}

			//次へのパスに制限がある場合
			//直前の頂点でパスの制限を受けているか受けていないかによって選べる頂点が異なる
			else { 
			   int lim = N[pos] - '0';
			   for(int d=0; d<lim; d++){
				  dp[pos+1][(sum+d)%D][1] = (dp[pos+1][(sum+d)%D][1] + dp[pos][sum][0]) % MOD;
			   }
			   dp[pos+1][(sum+lim)%D][0] = (dp[pos+1][(sum+lim)%D][0] + dp[pos][sum][0]) % MOD;				  
			}

		 }
	  }
   }

   //真ん中の配列は0(割り切れるため)
   //Dの倍数で制限のある場合とない場合の和が答え
   int ans = (dp[len][0][0] + dp[len][0][1]) % MOD;
   
   //0は任意のDの倍数となり答えにカウントされるので答えから1引く
   cout << ans - 1 << endl;

   return 0;
}
