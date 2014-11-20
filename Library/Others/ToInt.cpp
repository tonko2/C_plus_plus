
int toInt(string s){
   int res = 0;
   for(int i=0; i<s.size(); i++){
	  res *= 10;
	  res += s[i] - '0';
   }
   return res;
}

