#include <stdlib.h>
#include <stdio.h>
#include <stdbool.h>
#include <time.h>

// Inorder = Left Root Right 
// Preorder = Root Left Right 
// Post Order = Left Right Root 

struct Node{
    int data;
    struct Node* left;
    struct Node* right;
};

struct Node* CreateNode(int data){
    struct Node* newnode = (struct Node*)malloc(sizeof(struct Node));
    newnode->data = data;
    newnode->left = NULL;
    newnode->right = NULL;
    return newnode;
}

struct Node* insert(struct Node* root,int data){
    if(root==NULL) return CreateNode(data);

    if (data<root->data){
        root->left = insert(root->left,data);
    }
    else root->right = insert(root->right,data);
    return root;
}

void inorder(struct Node* root){
    if(root!=NULL){
        inorder(root->left);
        printf("%d ",root->data);
        inorder(root->right);
    }
}

void postorder(struct Node* root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        printf("%d ",root->data);
    }
}

void preorder(struct Node* root){
    if(root!=NULL){
        printf("%d ",root->data);
        preorder(root->left);
        preorder(root->right);
    }
}

struct Node* minvalue(struct Node* node){
    struct Node* curr = node;
    while(curr && curr->left!=NULL){
        curr=curr->left;
    }
    return curr;
}

struct Node* DeleteNode(struct Node* root, int key){
    if(root==NULL) return root;
    if(key<root->data) root->left = DeleteNode(root->left,key);
    else if(key>root->data) root->right = DeleteNode(root->right,key);
    else{
        if(root->left == NULL){
            struct Node* temp = root->right;
            free(root);
            return temp;
        }

        else if(root->right == NULL){
            struct Node* temp = root->left;
            free(root);
            return temp;
        }

        struct Node* temp = minvalue(root->right);
        root->data=temp->data;
        root->right = DeleteNode(root->right,temp->data);
    }
    return root;
    }

int main(){
    struct Node* root = NULL;
    root = insert(root, 50);
    root = insert(root, 30);
    root = insert(root, 20);
    root = insert(root, 40);
    root = insert(root, 70);
    root = insert(root, 60);
    root = insert(root, 80);

    printf("In-order traversal: ");
    inorder(root);
    printf("\n");

    printf("Post-order traversal: ");
    postorder(root);
    printf("\n");

    root = DeleteNode(root, 20);
    printf("In-order traversal after deleting 20: ");
    inorder(root);
    printf("\n");

    root = DeleteNode(root, 30);
    printf("In-order traversal after deleting 30: ");
    inorder(root);
    printf("\n");

    root = DeleteNode(root, 50);
    printf("In-order traversal after deleting 50: ");
    inorder(root);
    printf("\n");

    return 0;



}