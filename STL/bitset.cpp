#include <iostream>
#include <bitset>
using namespace std;

int main(){
   int a = 100;
   bitset<32>bi(a);
   cout << bi.to_string() << endl; //例えばaが100の場合00000000000000000000000001100100となる。
   return 0;
}
