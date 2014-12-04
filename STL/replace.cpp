#include <iostream>
#include <algorithm>
using namespace std;

//sは元の文字列, tは変える文字列, rは変えたい文字列
string myReplace(string s, string t, string r){
   if(s.find(t) == string::npos) return s;
   int pos = s.find(t);
   return s.replace(pos,t.size(),r);
}

int main(){
   string s = "aiueo";
   int length = 2;
   int pos = s.find("ai");
   string tmp = "aiueo";
   
   s.replace(pos,length,tmp); //取り替えたい文字列の始まり, 取り替える文字列数, 取り替える文字。
   cout << s << endl; // aiueo -> aiueoueoになる。

   return 0;
}
