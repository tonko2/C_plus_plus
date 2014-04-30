int prim(){
   fill(dis,dis+MAX,INF);
   fill(used,used+MAX,false);
   dis[0] = 0;
   int res = 0;
  
   priority_queue<P,vector<P>,greater<P> >que;
   que.push(P(0,0));

   while(!que.empty()){
      pair<int,int>p = que.top();
      que.pop();
      int from = p.second, cost = p.first;

      if(dis[from] < cost)continue;
      if(used[from])continue;
      used[from] = true;
      res += cost;
      for(int i=0; i<v[from].size(); i++){
         int d = v[from][i].cost;
         int to = v[from][i].to;
         if(used[to])continue;
         if(dis[to] > d){
            dis[to] = d;
            que.push(P(dis[to],to));
         }
      }
     
   }
   return res;  
}
