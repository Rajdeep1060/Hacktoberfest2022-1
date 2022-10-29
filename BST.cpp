#include<iostream>
using namespace std;
class BST{
    public:
    int data;
    BST* left;
    BST* right;
    BST(int x){
        data=x;
        left=right=NULL;
    }
};
void inorder(BST* root){
    if(root==NULL){
        return;
    }
    inorder(root->left);
    cout << root->data << " ";
    inorder(root->right);
}
void preorder(BST* root){
    if(root==NULL){
        return;
    }
    cout << root->data << " ";
    preorder(root->left);
    preorder(root->right);
}
BST* search(BST* root,int val){
    while(root!=NULL && root->data!=val){
        if(val < root->data){
            root=root->left;
        }
        else{
            root=root->right;
        }
    }
    return root;
}
BST* finder(BST* root){
    if(root==NULL){
        return NULL;
    }
    while(root->right!=NULL){
        root=root->right;
    }
    return root;
}

BST* helper(BST* root){
    if(root->left==NULL){
        return root->right;
    }
    if(root->right==NULL){
        return root->left;
    }
    BST* rightchild=root->right;
    BST* lastright = finder(root->left);
    lastright->right=rightchild;
    return root->left;
}

void insert(BST* root,int data){
      BST* temp=root;
      if(temp==NULL){
        temp=new BST(data);
        return;
      }
      while(true){
          if(data < temp->data){
              if(temp->left==NULL){
                 temp->left=new BST(data);
                 break;
              }
              else{
                  temp=temp->left;
              }
          }
          else{
              if(temp->right==NULL){
                  temp->right=new BST(data);
                  break;
              }
              else{
                  temp=temp->right;
              }
          }
      }
}

BST* deletion(BST* root,int key){
    if(root==NULL){
        return NULL;
    }
    if(root->data==key){
        return helper(root);
    }
    else{
        while(root!=NULL){
            if(key < root->data){
                    if(root->left!=NULL && root->left->data==key){
                        return helper(root->left);
                    }
                    else{
                        root=root->left;
                    }
             }
             else{
                  if(root->right!=NULL && root->right->data==key){
                        return helper(root->right);
                    }
                    else{
                        root=root->right;
                    }
             }
        }
    }
   }

int main(){
   BST* root=new BST(6);
   insert(root,4);
   insert(root,5);
   insert(root,3);
   insert(root,7);
   insert(root,1);
    preorder(root);
   BST* dele=deletion(root,3) ;
   cout << endl;
   inorder(root); 
   cout << endl << dele->data ;
    return 0;
}
