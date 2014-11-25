#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl

const int INF = 1<<29;
typedef long long ll;
typedef pair<int,int> P;


int main(){
   string s = "hoge1 hoge2";
   string t;
   stringstream ss;
   ss << s;

   //ss >> t >> t2みたいな使い方もできる
   while(ss >> t){
	  cout << t << endl;
   }

   //次使うときは必ずclearが必要
   ss.clear();
   
   s = "hoge3 hoge4";
   ss << s;

   while(ss >> t){
	  cout << t << endl;
   }


   return 0;
}
