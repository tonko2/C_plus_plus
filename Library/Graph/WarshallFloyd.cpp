#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl

const int INF = 1<<29;
typedef long long ll;
typedef pair<int,int> P;

int d[301][301];
int N;

void warshall_floyd(){

   for(int k=0; k<N; k++)
	  for(int i=0; i<N; i++)
		 for(int j=0; j<N; j++)
			d[i][j] = min(d[i][j],d[i][k] + d[k][j]);
   
}

int main(){
   fill(d[0],d[301],INF);
   
   return 0;
}
