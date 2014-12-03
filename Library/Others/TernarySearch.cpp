#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl

const int INF = 1<<29;
typedef long long ll;
typedef pair<int,int> P;


bool f(double x){
   return x;
}

int main(){

   double left = 0.0, right = 1e10;
   for(int i=0; i<100; i++){
	  double t1 = (2 * left + right) / 3.0;
	  double t2 = (left + 2 * right) / 3.0;
	  if(f(t1) < f(t2)) right = t2;
	  else left = t1;
	  
   }

   cout << left << endl;
   
   return 0;
}
