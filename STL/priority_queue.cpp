#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl

const int INF = 1<<29;
typedef long long ll;
typedef pair<int,int> P;


int main(){
   
   //でフォルトだと大きい値からでてくる
   priority_queue<int>que;
   que.push(2);
   que.push(10);

   while(!que.empty()){
	  cout << que.top() << endl;
	  que.pop();
   }

   //これで小さい値からでてくる
   priority_queue<int,vector<int>,greater<int> >que2;

   que2.push(2);
   que2.push(10);

   while(!que2.empty()){
	  cout << que2.top() << endl;
	  que2.pop();
   }
   
   
   return 0;
}
