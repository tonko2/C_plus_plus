/*

  最大流
 
  O(F|E|)
  Fはcapacity
  
 */

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

const int MAX_V = 300;
const int INF = 1<<29;
typedef pair<int,int> P;
typedef long long ll;


//辺を表す構造体 (行き先, 容量, 逆辺)
struct edge { int to, cap, rev; };

vector<edge> G[MAX_V]; //グラフの隣接リスト表現
bool used[MAX_V]; //DFSですでに調べたかのフラグ

// fromからtoへ向かう容量capの辺をグラフに追加する
void add_edge(int from, int to, int cap){
   G[from].push_back((edge){to,cap,G[to].size()});
   G[to].push_back((edge){from,0,G[from].size()-1});
}

//増加パスをDFSで探す
int dfs(int v, int t, int f){
   if(v == t) return f;
   used[v] = true;

   for(int i=0; i<G[v].size(); i++){
      edge &e = G[v][i];
      if(!used[e.to] && e.cap > 0){
	 int d = dfs(e.to,t,min(f,e.cap));
	 if(d > 0){
	    e.cap -= d;
	    G[e.to][e.rev].cap += d;
	    return d;
	 }
      }
   }
   return 0;
}

//sからtへの最大流を求める
int max_flow(int s, int t){
   int flow = 0;
   for(;;){
      memset(used,0,sizeof(used));
      int f = dfs(s,t,INF);
      if(f == 0) return flow;
      flow += f;
   }
   return flow;
}

int main(){
   int V = 5;
   int E = 7;

   add_edge(0,1,10);
   add_edge(0,2,2);
   add_edge(1,2,6);
   add_edge(1,3,6);
   add_edge(2,4,5);
   add_edge(3,2,3);
   add_edge(3,4,8);

   cout << max_flow(0,4) << endl;
   
   return 0;
}
