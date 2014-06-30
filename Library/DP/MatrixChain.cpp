#include <iostream>
#include <algorithm>
using namespace std;

const int MAX = 110;
const int INF = 1<<29;

int size;
int R[MAX], M[MAX][MAX], S[MAX][MAX];

void initialization(){
   
   for(int i=0; i<=size; i++){
      for(int j=0; j<=size; j++){
	 if(i == j) M[i][i] = 0;
	 if(j > i)
	    M[i][j] = INF;
      }
   }
   
}

void rec(int i, int j){
   if(i == j) cout << "M" << i;
    else{
        cout << "(";
        rec(i,S[i][j]-1);
	rec(S[i][j],j);
        cout << ")";
    }
}

int main(){
   
   cin >> size;
   for(int i=1; i<=size+1; i++){
      cin >> R[i];
   }

   initialization();

    for (int j=1; j<=size-1; j++){
        for (int i=1; i<=size-j; i++){
            for (int k=i+1; k<=i+j; k++){
	       int cost = M[i][k-1] + M[k][i+j] + R[i]*R[k]*R[i+j+1];

	       /*
	       cout << "i = " << i << " k = " << k << " i+j+1 = " << i+j+1 << endl;
	       cout << "left = " << M[i][k-1] << endl;
	       cout << "bottom = " << M[k][i+j] << endl;
	       cout << "R[i] = " << R[i] << " R[k] = " << R[k] << " R[i+j+1] = " <<
		  R[i+j+1] << endl;
	       cout << "cost = " << cost << endl;
	       cout << endl;
	       */
	       
                if(M[i][i+j] > cost){
		   M[i][i+j] =  cost;
		   S[i][i+j] = k;
                }
            }
        }
    }

    cout << "Matrix M: " << endl;
    
    for(int i=1; i<=size; i++){
       for(int j=1; j<=size; j++){
	  printf("%8d",M[i][j]);
       }
       printf("\n");
    }

    cout << "Matrix S: " << endl;
    
    for(int i=1; i<=size; i++){
       for(int j=1; j<=size; j++){
	  printf("%8d",S[i][j]);
       }
       printf("\n");
    }

    
    cout << "minimum cost = " << M[1][size] << endl;
    cout << "optimal parenthesization : ";
    rec(1,size);
    cout << endl;

}
