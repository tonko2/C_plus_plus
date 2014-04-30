#include <iostream>
#include <string>
using namespace std;

int main(){
   string s = "aiueo";
   cout << s.substr(0,3) << endl; //引数の左は始まり。 右は文字数。
   cout << s.substr(1) << endl; //始まりから終わりまで。 iueoが表示される。
}
