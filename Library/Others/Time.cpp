#include <bits/stdc++.h>
using namespace std;

#define debug(x) cout << #x << " = " << x << endl

const int INF = 1<<29;
typedef long long ll;
typedef pair<int,int> P;


int main(){
   int N;
   cin >> N;
   int hh = N / 3600;
   int mm = (N % 3600) / 60;
   int ss = N % 60;

   //1秒なら01と、出力
   printf("%02d:%02d:%02d\n",hh,mm,ss);
   return 0;
}
