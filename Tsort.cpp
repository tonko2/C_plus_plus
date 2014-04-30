
//トポロジカルソート
void Tsort(int s){
   used[s] = true;
   for(int i=0; i<V; i++){
      if(!used[i] && a[s][i] > 0) Tsort(i);
   }
   v.push_back(s);
}

最後にvをreverseする
