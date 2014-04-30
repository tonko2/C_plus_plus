

for(int i=0; i<n; i++){
      for(int j=0; j<n; j++){
         for(int k=0; k<n; k++){
               res[i][j] = (mat[i][k] * mat2[k][j]);
          }
      }
   }


for(int i=0; i<n; i++) mat2[i][i] = 1とすることで単位行列を作ることができる
