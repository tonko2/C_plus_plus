#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){
   vector<int>v;
   for(int i=1; i<10; i++) v.push_back(i); // 1 2 3 4 5 6 7 8 9
   rotate(v.begin(),v.begin()+3,v.end()); //4 5 6 7 8 9 1 2 3  左に3個ずれる。

   for(int i=0; i<(int)v.size(); i++) cout << v[i] << " ";
   cout << endl;
   
   
   return 0;
}
