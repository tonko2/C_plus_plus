#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){
   vector<int>v;
   for(int i=0; i<5; i++) v.push_back(i);

   cout << *max_element(v.begin(),v.end()) << endl; //最大値。
   cout << max_element(v.begin(),v.end()) - v.begin() << endl; //最大値があるindex。
   
   return 0;
}
