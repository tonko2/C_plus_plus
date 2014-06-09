#include <iostream>
#include <math.h>
using namespace std;

const int MAX_N = 1<<17;
const int INF = 1<<29;
int n,dat[2*MAX_N-1];

void init(int n_){
   // 簡単のため、要素数を２のべき乗に
   n = 1;
   while(n < n_) n *= 2;

   //すべての値をINFに
   for(int i=0; i<2*n-1; i++) dat[i] = INF;
}

//k番目の値(0-indexed)をaに変更
void update(int k, int a){
   // 葉の節点
   k += n - 1;
   dat[k] = a;
   //登りながら更新
   while(k > 0){
      k = (k-1) / 2; // kの親に移動
      dat[k] = min(dat[k*2+1],dat[k*2+2]); //kの二人の子供の最小を取る
   }
}

//深さh分まで木の中身を表示
void print(int h){
   int cnt = 0;
   for(int i=0; i<h; i++){
      for(int j=0; j<pow(2,i); j++){
         cout << dat[cnt+j] << " ";
      }
      cnt = cnt * 2 + 1;
      cout << endl;
   }
}

// [a,b)の最小値を求める
// 後ろのほうの引数は、計算の簡単のための引数
// kは節点の番号、l,rはその節点が[l,r)に対応づいていることを表す。
// したがって、外からはquery(a,b,0,0,n)として呼ぶ。
int query(int a, int b, int k, int l, int r){
   // [a,b)と[l,r)が交差しなければ、INFを返す。
   if(r <= a || b <= l) return INF;

   // [a,b)が[l,r)を完全に含んでいれば、この節点の値
   if(a <= l && r <= b) return dat[k];
   else {
      // そうでなければ、2つの子の最小値
      int vl = query(a,b,k*2+1,l,(l+r)/2);
      int vr = query(a,b,k*2+2,(l+r)/2,r);
      return min(vl,vr);
   }
  
}

int main(){
   int N = 8;
   init(N);
   int A[] = {5,3,7,9,6,4,1,2};
   for(int i=0; i<8; i++){
      update(i,A[i]);
   }

   //数列A[a]からA[b-1]までの最小を求める(logN)  
   cout << query(0,2,0,0,N) << endl;

   return 0;
}
