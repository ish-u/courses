#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
#include "bst.h"


bool complete(TreeNode *root)
{
    TreeNode *traverseNode = root;
    queueLL<TreeNode*>* queue = new queueLL<TreeNode*>();
    queue->enqueue(traverseNode);
    int flag = 0;
    while(!queue->isEmpty())
    {
        traverseNode = queue->firstEle();
        queue->dequeue();

        if(flag == 1 && (traverseNode->left != 0 || traverseNode->right != 0))
        {
            return false;
        }

        if(traverseNode->left == 0 && traverseNode->right != 0)
        {
            return false;
        }

        if(traverseNode->left != 0)
        {
            queue->enqueue(traverseNode->left);
        }
       

        if(traverseNode->right != 0)
        {
            queue->enqueue(traverseNode->right);
        }
        else
        {
            flag = 1;
        }
        

        
    }
    traverseNode = 0;
    delete traverseNode;
    delete queue;
    return true;
}



int main()
{
    //creating a BST tree
    BST *tree = new BST();
    int n;
    int data = 0;
    cout<<"Number of Inputs : "; cin>>n;
    //taking input of tree
    for(int i = 0; i < n; i++)
    {
        cin>>data;
        tree->insert(data);
    }
    tree->bfsTraversal();
    tree->
    cout<<"\n"<<complete(tree->returnRoot());

}