#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
using namespace std;

/*

文字列が与えられ、その文字列に対してアルファベットの追加と削除が許される。
追加と削除にはそれぞれコストが存在し、それらを使って回文を作る。


abcからabcbaという回文を作るというのはabを消してcという回文を作ると同じなのでコストは
追加と削除の最小をとる。

前処理としてdp[i][i] = dp[i][i+1] = 0(文字列の長さ０と１は回文なので)

その後区間DPをする。
dp[i][i] = dp[i][i+1] = 0 (長さが 0, 1 の文字列は回文)
dp[i-1][j] := dp[i][j] + cost[i-1 番目の文字] (区間を左側にのばす)
dp[i][j+1] := dp[i][j] + cost[j 番目の文字] (区間を右側にのばす)
dp[i-1][j+1] := dp[i][j]  (i-1 番目の文字と j 番目の文字が等しいとき、コスト無しで区間を両側にのばす)

  
*/

const int INF = 1<<29;
int dp[2040][2040];

int main(){
   int N,M;
   while(cin >> N >> M){
      string s;
      cin >> s;

      int cost[26];
      fill(cost,cost+26,0);

      for(int i=0; i<N; i++){
	 string in;
	 int add,del;
	 cin >> in >> add >> del;
	 cost[in[0]-'a'] = min(add,del);
      }

      fill(dp[0],dp[2040],INF);

      for(int i=0; i<=M; i++) dp[i][i] = dp[i][i+1] = 0;

      for(int len=0; len<M; len++){
	 for(int i=0; i<M; i++){
	    int j = i + len;
	    if(i > 0 && j <= M){
	       dp[i-1][j] = min(dp[i-1][j],dp[i][j] + cost[s[i-1]-'a']);
	    }

	    if(j <= M){
	       dp[i][j+1] = min(dp[i][j+1],dp[i][j] + cost[s[j]-'a']);
	    }

	    if(i > 0 && len <= M && s[i-1] == s[j]){
	       dp[i-1][j+1] = min(dp[i-1][j+1],dp[i][j]);
	    }
	 }
      }

      cout << dp[0][M] << endl;
      
   }
   return 0;
}
