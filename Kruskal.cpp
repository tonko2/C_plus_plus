
クラスカル法
#include <iostream>
using namespace std;

const int MAX = 100;
int p[MAX];
int rank[MAX];

struct edge{
   int u,v,cost;
};

bool compare(const edge& e1, const edge& e2){
   return e1.cost < e2.cost;
}

edge es[MAX];
int V,E;

void init(int n){
   for(int i=0; i<n; i++){
      p[i] = i;
      rank[i] = 0;
   }
}

int find(int x){
   if(p[x] == x) return x;
   return p[x] = find(p[x]);
}

bool same(int x, int y){
   return find(x) == find(y);
}

void unite(int x, int y){
   x = find(x);
   y = find(y);
   if(x == y) return;
   if(rank[x] < rank[y]){
      p[x] = y;
   } else {
      p[y] = x;
      if(rank[x] == rank[y]) rank[x]++;
   }
}

int kruskal(){
   sort(es,es+E,compare);
   init(V);
   int res = 0;

   for(int i=0; i<E; i++){
      edge e = es[i];
      if(!same(e.u,e.v)){
         unite(e.u,e.v);
         res += e.cost;
      }
   }
   return res;
}

int main(int argc, char *argv[])
{
   cin >> V >> E;
   for(int i=0; i<E; i++){
      edge tmp;
      cin >> tmp.u >> tmp.v >> tmp.cost;
      es[i] = tmp;
   }
   cout << kruskal() << endl;
   return 0;
}
