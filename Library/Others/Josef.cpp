
//ヨセフの芋

int f(int n, int k){
   if(n == 1) return 0;
   return (f(n-1,k)+k) % n;
}

int main(int argc, char *argv[])
{
   int n,m;
   cin >> n >> m;
   cout << f(n,m)%n+1 << endl;
   return 0;
}
