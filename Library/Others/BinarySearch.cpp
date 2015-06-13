#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl

const int INF = 1<<29;
typedef long long ll;
typedef pair<int,int> P;


int binarysearch(int l, int r, int x){
   
   while(r-l > 0){
	  int mid = (l+r)/2;
	  if(x <= mid) r = mid;
	  else l = mid+1;
   }
   return r;
}

int main(){

   cout << binarysearch(0,13,2) << endl;
   
   return 0;
}
