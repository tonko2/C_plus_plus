#include <iostream>
#include <set>
using namespace std;

int main(){
   set<int>s;
   s.insert(1); //挿入。
   set<int>::iterator it = s.find(3); //検索。
   if(it == s.end()) cout << "not found" << endl;  //見つけられない。

   s.erase(2); //値２を削除する。
   if(s.count(1)) cout << "found" << endl; //見つけられる。

   it = s.lower_bound(1); //setでlower_bound
   if(it == s.end()){
	  cout << "not found" << endl; //見つけられない
   } else {
	  cout << "found" << endl;    //見つけられる
	  cout << *it << endl;
   }
   
   return 0;
}
