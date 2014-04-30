#include <iostream>
#include <set>
using namespace std;

int main(){
   set<int>s;
   s.insert(1); //挿入。
   set<int>::iterator it = s.find(3); //検索。
   if(it == s.end()) cout << "not found" << endl;  //見つけられない。

   s.erase(2); //値２を削除する。
   if(s.count(1)) cout << "find" << endl; //見つけられる。
      
   return 0;
}
