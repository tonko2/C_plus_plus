#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl

const int INF = 1<<29;
typedef long long ll;
typedef pair<int,int> P;


int main(){
   //aという文字4つ連続で出す
   cout << string(4,'a') << endl;

   //文字列をcharの配列に置換
   string hoge = "aiueo";
   const char *hoge2 = hoge.c_str();
   printf("%s\n",hoge2);
   
   return 0;
}
