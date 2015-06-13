#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl

const int INF = 1<<29;
typedef long long ll;
typedef pair<int,int> P;


int main(){
   int l,r,x;
   int array[101];
   cin >> l >> r >> x;


   /*
	 imos法
	 array[l]からarray[r]までにvずつ足したい場合、1つずる足す代わりに
	 array[l]だけにvを足し、array[r+1]の-vを足すようにする
	*/
   
   array[l] += x;
   array[r+1] -= x;

   
   
   return 0;
}
