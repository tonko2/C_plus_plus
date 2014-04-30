#include <iostream>
#include <algorithm>
using namespace std;

int main(){
   string s = "aiueo";
   int length = 2;
   int pos = s.find("ai");
   string tmp = "aiueo";
   
   s.replace(pos,length,tmp); //取り替えたい文字列の始まり, 取り替える文字列数, 取り替える文字。
   cout << s << endl; // aiueo -> aiueoueoになる。

   return 0;
}
