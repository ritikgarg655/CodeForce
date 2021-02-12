int ans;
bool finda ,findb;
int find(Node* root,int a,int b){
    if(a==-1 and b==-1){
        return -1;
    }
    if(root==NULL){
        return -1;
    }
    int reta,retb;
    if(root->data == a){
        finda = true;
         reta= find(root->left,-1,b);
         retb= find(root->right,-1,b);
         if(reta==-1 and retb==-1){
            return 1;
         }
         else{
            if(retb!=-1){
                ans = retb;
            }
            if(reta!=-1){
                ans = reta;
            }
         }
         return -1;
    }
    else if(root->data ==b){
        findb = true;
         reta= find(root->left,a,-1);
         retb= find(root->right,a,-1);
         if(reta==-1 and retb==-1){
            return 1;
         }
         else{
            if(retb!=-1){
                ans = retb;
            }
            if(reta!=-1){
                ans = reta;
            }
         }
         return -1;
    }
    else{
         reta= find(root->left,a,b);
         retb= find(root->right,a,b);
        if(retb!=-1 and reta!=-1){
            ans = reta + retb;
        }
        else{
            return max(retb,reta);
        }
    }
}


/* A binary tree node
struct Node
{
    int data;
    Node* left, * right;
}; */

/* Should return minimum distance between a and b
   in a tree with given root*/
int findDist(Node* root, int a, int b) {
    int r = find(root,a,b);
    return ans;
}