#include <iostream>
using namespace std;

int main(){
   
//１になってるビットの数を返す関数
   int a = 20;
   int b = 100;
   int c = __builtin_popcount(a&b);
   cout << c << endl;
   
   return 0;
}
