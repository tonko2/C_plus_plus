#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl

const int INF = 1<<29;
typedef long long ll;
typedef pair<int,int> P;

int comb[40][40];

void create(){

   memset(comb,0,sizeof(comb));
   comb[0][0] = 1;

   for(int i=1; i<=20; i++){
	  for(int j=0; j<=i; j++){
		 if(j == 0 || j == i) comb[i][j] = 1;
		 else comb[i][j] = comb[i-1][j-1] + comb[i-1][j];
	  }
   }   
}

int main(){
   create();
   int n = 4, r = 2;
   cout << comb[n][r] << endl; //nCr


   
   return 0;
}
