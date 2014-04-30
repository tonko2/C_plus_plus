
//BIT
const int MAX = 101;
int bit[MAX];

//[1,i]の総和を返す
int sum(int i){
   int s = 0;
   while(i > 0){
      s += bit[i];
      i -= i&-i;
   }
   return s;
}

//bit[i] += xをする
void add(int i, int x){
   while(i <= n){
      bit[i] += 1;
      i += i&-i;
   }
}
