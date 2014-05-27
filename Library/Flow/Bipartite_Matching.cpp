#include <iostream>
#include <algorithm>
#include <map>
#include <set>
#include <vector>
#include <string>
#include <cstdlib>
#include <cmath>
#include <climits>
#include <cstdio>
#include <queue>
#include <sstream>
using namespace std;

const int INF = 1<<29;
typedef pair<int,int> P;
typedef long long ll;

const int MAX_V = 200;


int V;

vector<int> G[MAX_V];
int match[MAX_V];
bool used[MAX_V];

//uとvを結ぶ辺をグラフに追加する
void add_edge(int u, int v){
   G[u].push_back(v);
   G[v].push_back(u);
}

//増加パスをDFSで探す
bool dfs(int v){
   used[v] = true;
   for(int i=0; i<G[v].size(); i++){
      int u = G[v][i], w = match[u];
      if(w < 0 || (!used[w] && dfs(w))){
	 match[v] = u;
	 match[u] = v;
	 return true;
      }
   }
   return false;
}

// 二部グラフの最大マッチングを求める
int bipartite_matching(){
   int res = 0;
   memset(match,-1,sizeof(match));
   
   for(int v=0; v<V; v++){
      if(match[v] < 0){
	 memset(used,0,sizeof(used));
	 if(dfs(v))res++;
      }
   }
      
      return res;
}

int main(){


   return 0;
}
