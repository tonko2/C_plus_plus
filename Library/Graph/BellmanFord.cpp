
//ベルマンフォード法
void bellman_ford(int s){
   fill(d,d+401,INF);
   d[s] = 0;

   while(true){
      bool update = false;
      for(int i=0; i<E; i++){
         Edge e = v[i];
         if(d[e.from] != INF && d[e.to] > d[e.from] + e.cost){
            d[e.to] = d[e.from] + e.cost;
            update = true;
         }
      }
      if(!update)break;
   }
}
