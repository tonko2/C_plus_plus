#include <iostream>
#include <deque>
using namespace std;

int main(){
   deque<int>deq;
   deq.push_back(2); 
   deq.push_front(3);

   deq.pop_back();
   deq.pop_front();

   cout << deq.front() << endl;
   cout << deq.back() << endl;
   
   return 0;
}
