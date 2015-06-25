
//ax + by = gcd(a,b) のxとyを求める
   
int extgcd(int a, int b, int &x, int &y){
   int d = a;
   if(b != 0){
      d = extgcd(b,a%b,y,x);
      y -= (a/b) * x;
   } else {
      x = 1, y = 0;
   }
   return d; // b == 0 then return a
}

   
