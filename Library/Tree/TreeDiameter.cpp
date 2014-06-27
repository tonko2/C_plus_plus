typedef pair<int,int> P;
typedef pair<P,int> PP;

struct Edge {
   Edge(int _t, int _c):to(_t),cost(_c){}
   int to,cost;
};

vector<Edge> G[10001];

P visit(int p, int v){
  P r(0,v);
  for(int i=0; i<G[v].size(); i++){
    if(G[v][i].cost == 0)continue;
    if(G[v][i].to == p)continue;
    P t = visit(v,G[v][i].to);
    t.first += G[v][i].cost;
    if(r.first < t.first) r = t;
  }
  return r;
}
 
PP diameter(int s){
  P r = visit(-1,s);
  P t = visit(-1,r.second);
  return PP(P(r.second,t.second),t.first);
}
