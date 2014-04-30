#include <iostream>
#include <cstdlib>
#include <string>
#include <cstdio>
#include <queue>
using namespace std;

typedef struct TNode{
   int have_value; //存在していれば1, 存在していなければ0
   int v; //Nodeの番号
   struct TNode *left, *right;
} Node;

Node* root;

int failed;

//新しいNodeを作る
Node* newnode() {
   Node* u = (Node*) malloc(sizeof(Node)); 
   u->have_value = 0; 
   u->left = u->right = NULL;
   return u;
}

//指定した場所にnodeを作る
void addnode(int v, string s){

   Node* u = root;
   for(int i=0; i<(int)s.size(); i++){
      if(s[i] == 'L'){
      if(u->left == NULL) u->left = newnode();
      u = u->left;     
      } else {
      if(u->right == NULL) u->right = newnode();
      u = u->right;
      }
   }

   if(u->have_value){failed = 1;} //既に値が入ってる場合上書きせずに失敗する
   u->v = v;
   u->have_value = 1;

}

void init(){
   failed = 0;
   root = (Node*)malloc(sizeof(Node));
   root = newnode();
}

void bfs(){
   queue<Node*>que;
   que.push(root);

   while(!que.empty()){
      Node* u = que.front();
      que.pop();
      if(u == NULL) continue;
      cout << u->v << endl;
      que.push(u->left);
      que.push(u->right);
   }

}
int main(){
   init();
   addnode(3,"L");
   addnode(1,"");
   addnode(2,"R");
   bfs();
  
}
