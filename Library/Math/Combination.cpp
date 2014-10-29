vector<vector<int> > combination(int n){
  vector<vector<int> > C(n+1, vector<int>(n+1, 0));
 
  C[0][0] = 1;
  for(int i = 1 ; i <= n ; i++){
    for(int j = 0 ; j <= n ; j++){
      C[i][j] = 0;
      if(j-1 >= 0) C[i][j] += C[i-1][j-1];
      if(j <= i-1) C[i][j] += C[i-1][j];
    }
  }
  return C;
}
