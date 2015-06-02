#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

string str;
int pos;

/*
BNF

<expr> ::= <term> | <term> (+ | -) <term>
<term> ::= <factor> | <factor> (* | /) <factor>
<factor> ::= <number> | ( <expr> )
<number> ::= 1つ以上の数字

*/


int exp(void);
int term(void);
int factor(void);
 
int main(){
  int n,ans;
  cin >> n;
  for(int i=0;i<n;i++){
    cin >> str;
    str.erase(str.size()-1);
    pos = 0;
    ans = exp();
    cout << ans << endl;
  }
  return 0;
}
 
int exp(void){
  int x = term();
  while(str[pos] == '+' || str[pos] == '-'){
    char op = str[pos++];
    if(op == '+') x += term();
    else if(op == '-') x -= term();
  }
  return x;
}
 
int term(void){
  int x = factor();
  while(str[pos] == '*' || str[pos] == '/'){
    char op = str[pos++];
    if(op == '*') x *= factor();
    else if(op == '/') x /= factor();
  }
  return x;
}
 
int factor(void){
  int x=0,c;
  if(str[pos] == '('){
    pos++;
    x = exp();
    pos++;
  }
  else{
    while(str[pos] >= '0' && str[pos] <= '9'){
      x *= 10;
      x += str[pos++] - '0';
    }
  }
  return x;
}
