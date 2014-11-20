
//サイコロのライブラリ
int dx[] = {0,1,0,-1};
int dy[] = {-1,0,1,0};

class Dice{
public:
   int t,s,e,n,w,b; //t=top,s=south,e=east,n=north,w=west,b=bottom
   Dice(){}
   Dice(int _t, int _s, int _e, int _n, int _w, int _b){
       t = _t, s = _s,e = _e,n = _n,w = _w,b = _b;
   }
   //前に転がす
   Dice rotate_front(){
      return Dice(s,b,e,t,w,n);
   }
   //左に転がす
   Dice rotate_left(){
      return Dice(e,s,b,n,t,w);
   }
   //右に転がす
   Dice rotate_right(){
      return Dice(w,s,t,n,b,e);
   }
   //後ろに転がす
   Dice rotate_back(){
      return Dice(n,t,e,b,w,s);
   }
   //時計周りに動かす
   Dice move_right(){
      return Dice(t,e,n,w,s,b);
   }
   //反時計周りに動かす
   Dice move_left(){
      return Dice(t,w,s,e,n,b);
   }

   void print(){
      cout << "t=" << t << "s=" << s << "e=" << e << "n=" << n
           << "w=" << w << "b=" << b << endl;
   }
};

vector<Dice>all;
//ここで二つの組み合わせ(今回はfrontとsouth)によってDiceが得られる
Dice getDice(int top, int south){
   for(int i=0; i<24; i++){
      if(all[i].t == top && all[i].s == south){
         return all[i];
      }
   }
}

//ここで２４種類の状態を保存
void allState(){
   all.clear();
   Dice dice(1,3,5,4,2,6);
   for(int i=0; i<6; i++){
      for(int j=0; j<4; j++){
         all.push_back(dice);
         dice = dice.move_right();
      }
      if(i < 4) dice = dice.rotate_front();
      if(i == 3) dice = dice.rotate_right();
      if(i == 4) dice = dice.rotate_right().rotate_right();
   }
}
