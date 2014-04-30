#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;

int main(){
   vector<int>v;
   for(int i=0; i<10; i++) v.push_back(i);
   vector<int>v2;

   v2.resize(v.size());
   copy(v.begin(),v.end(),v2.begin()); //必ず最初に配列を確保する。
   
   for(int i=0; i<v2.size(); i++) cout << v2[i] << " ";
   cout << endl;
   
   return 0;
}
