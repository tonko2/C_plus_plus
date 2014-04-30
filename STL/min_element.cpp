#include <iostream>
#include <deque>
#include <vector>
using namespace std;

int main(){
   vector<int>v;
   for(int i=0; i<5; i++) v.push_back(i);

   cout << *min_element(v.begin(),v.end()) << endl; //最小値。
   cout << min_element(v.begin(),v.end()) - v.begin() << endl; //最小値があるindex。
   
   return 0;
}
