#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl

const int INF = 1<<29;
typedef long long ll;
typedef pair<int,int> P;


int main(){
   map<int,int> m;

   m[1] = 1;

   //iteratorの回し方
   for(map<int,int>::iterator it = m.begin(); it != m.end(); it++){
	  cout << it->first << " " << it->second << endl;
   }

   //mapに保存されてるかの確認
   if(m.count(1)){}

   
   //mapで配列を取る方法
   map<int,int> dp[100];

   //配列版のiteratorの回し方
   for(int i=0; i<100; i++){
	  for(map<int,int>::iterator it = dp[i].begin(); it != dp[i].end(); it++){
		 cout << it->first << " " << it->second << endl;
	  }
   }
   return 0;
}
