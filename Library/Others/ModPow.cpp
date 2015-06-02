
//繰り返し２乗法
ll mod_pow(ll x, ll n, ll mod){
   if(n == 0) return 1;
   ll res = mod_pow((x*x)%mod,n/2,mod);
   if(n & 1) res = (res * x) % mod;
   return res;
}

//繰り返し２乗法 (行列)
typedef vector<vector<ll> > Matrix;

Matrix calc(Matrix a, Matrix b){
   int N = a.size();
   Matrix res(N,vector<ll>(N)); //最初に0で初期化されている
   
   for(int i=0; i<N; i++){
	  for(int j=0; j<N; j++){
		 for(int k=0; k<N; k++){
			res[i][j] += a[i][k] * b[k][j];
		 }
	  }
   }
   return res;
}
     
Matrix modpow(Matrix g, int n){

   
   if(n == 0){
	  Matrix unit(g.size(),vector<ll>(g.size()));
	  for(int i=0; i<g.size(); i++) unit[i][i] = 1;
	  return unit;
   }
     
   Matrix res = modpow(g,n/2);
   if(n & 1) return calc(g,calc(res,res)); 
   else return calc(res,res);
       
}


void display(Matrix a){
   int N = a.size();
   for(int i=0; i<N; i++){
	  for(int j=0; j<N; j++){
		 cout << a[i][j] << " ";
	  }
	  cout << endl;
   }
}
     
int main(){
     
   Matrix a(3,vector<ll>(3));
   
   for(int i=0; i<3; i++)
	  for(int j=0; j<3; j++) a[i][j] = i*3 + (j+1);

   Matrix b = calc(a,a);
   Matrix c = calc(b,b);

   display(modpow(a,1));
   display(modpow(a,2));
   display(modpow(a,3));
   display(modpow(a,4));
   
   display(c);
     
       
   return 0;
}
