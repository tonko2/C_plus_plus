
エラトステネスの篩
const int MAX = 1001;
bool prime[MAX];



for(int i=0; i<MAX; i++) prime[i] = true;
prime[0] = prime[1] = false;
  
for(int i=2; i*i<MAX; i++){
   for(int j=i*2; j<MAX; j+=i){
      if(prime[j]) prime[j] = false;
   }
}
