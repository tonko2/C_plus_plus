class BigInteger {
public:
   string a,b;
   int digit[1000];  //1000 digits
  
   BigInteger(){}
   BigInteger(string A, string B){
      if(A.size() < B.size()) swap(A,B);
      else{ a = A; b = B;}
   }

   string add(){
      string A = a, B = b;
      reverse(A.begin(),A.end());
      reverse(B.begin(),B.end());
      fill(digit,digit+1000,-1);
      int n = A.size(), m = B.size();
      for(int i=0; i<n; i++) digit[i] = A[i] - '0';
      for(int i=0; i<m; i++) digit[i] += B[i] - '0';
      string res = "";
      for(int i=0; digit[i]!=-1; i++){
         int up = digit[i] / 10;
         if(digit[i+1] == -1 && up) digit[i+1] = up;
         else digit[i+1] += up;
         digit[i] %= 10;
         res += digit[i] + '0';
      }
      reverse(res.begin(),res.end());
      return res;
   }

   string multiply(){
      fill(digit,digit+1000,-1);
      int n = a.size(), m = b.size();

      for(int i=m-1,k=0; i>=0; i--,k++){
         for(int j=n-1,l=0; j>=0; j--,l++){
            int valueA = a[j]-'0';
            int valueB = b[i]-'0';
            if(digit[k+l] == -1) digit[k+l] = valueA * valueB;
            else digit[k+l] += valueA * valueB;
         }
      }
     
      string res = "";
      for(int i=0; digit[i]!=-1; i++){
         int up = digit[i] / 10;
         if(digit[i+1] == -1 && up) digit[i+1] = up;
         else digit[i+1] += up;
         digit[i] %= 10;
         res += digit[i] + '0';
      }
     
      reverse(res.begin(),res.end());
      return res;
   }
};
