#include <iostream>
#include <string>
#include <vector>
using namespace std;

int main(){
   string s = "abcd";
   s.erase(2); //index番目以降を消す。 abcd -> ab

   vector<int>v;
   for(int i=0; i<10; i++) v.push_back(i);

   
   return 0;
}
