string toStr(int x){
   if(x == 0) return "0";
   string res = "";

   while(x){
	  res += (x % 10) + '0';
	  x /= 10;
   }
   reverse(res.begin(),res.end());
   return res;
}

