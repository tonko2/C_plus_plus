
class Union_Find{
public:
   vector<int>par,rank;
   Union_Find(){}

   void init(int n){
      par.resize(n);
      rank.resize(n);
      for(int i=0; i<n; i++){
         par[i] = i;
         rank[i] = 0;
      }
   }

   int find(int x){
      if(abs(par[x]) == x) return x;
      return par[x] = find(abs(par[x])) * (par[x]>0?1:-1);
   }

   bool same(int x, int y){
      return abs(find(x)) == abs(find(y));
   }


//xとyが違うグループに属すようにする
   void dif(int x, int y){
      if(same(x,y)) return;
      x = find(x);
      y = find(y);

      par[abs(x)] = (x>0)?(-y):y;
   }
  
   void unite(int x, int y){
      x = find(x);
      y = find(y);
      if(x == y)return;


      if(rank[x] < rank[y]){
         par[x] = y;
      } else {
         par[y] = x;
         if(rank[x] == rank[y]) rank[x]++;
      }
   } 
};


diffの使い方
Union_Find uf;
uf.init(n);

if(uf.find(x) == uf.find(y)) //xとyが同じグループ
else if(uf.find(x) == -uf.find(y)) xとyが別のグループ
