#include <iostream>
#include <vector>
using namespace std;

int main(){
   vector<int>v;
   for(int i=0; i<5; i++) v.push_back(10);
   v.erase(unique(v.begin(),v.end()),v.end()); //[10,10,10,10,10] -> [10]になる。
   return 0;
}
