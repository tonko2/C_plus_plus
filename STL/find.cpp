#include <iostream>
#include <algorithm>
using namespace std;

int main(){
   string s = "aiueo";
   int pos = s.find("ai"); //aiが見つかった最初のindexを返す。この場合0。
   if(pos == string::npos) cout << "not found" << endl;
   else cout << pos << endl;

   return 0;
}
