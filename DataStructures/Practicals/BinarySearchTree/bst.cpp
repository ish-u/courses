#include <iostream>
#include <conio.h>
#include <iomanip>
using namespace std;
#include "queue.h"
#include "stack.h"

//Tree Node
class TreeNode
{
    public:
        TreeNode *left,*right;
        int data;
        //constructor
        TreeNode(int data = 0, TreeNode* left = 0, TreeNode* right = 0)
        {
            this->data = data;
            this->left = left;
            this->right = right;
        }
        //destructor
        ~TreeNode()
        {
            cout<<"Deleting TreeNode with Data :  "<<this->data<<"\n";
        }
};

class BST
{
    private:
        TreeNode *root;
    public:
        //constructor
        BST()
        {
            root = 0;
        }
        //destructor
        ~BST()
        {
            cout<<"Deleting Tree\n";
            clear(root);
        }
        TreeNode* returnRoot();
        void insert(int data);
        int search(int data);
        void inorderRecursive(TreeNode *root);
        void preorderRecursive(TreeNode *root);
        void postorderRecursive(TreeNode *root);
        void inorderIterative();
        void preorderIterative();
        void postorderIterative();
        void bfsTraversal();
        int leafNodes(TreeNode* root);
        int internalNodes(TreeNode *root);
        int height(TreeNode *root);
        void deleteNodeMerging(int value);
        void deleteNodeCopying(int value);
        void findAndReplace(int x,int y);
        void clear(TreeNode *root);
        
};

//return Root TreeNode
TreeNode* BST :: returnRoot()
{
    return root;
}

//insert function
void BST :: insert(int data)
{
    TreeNode *temp = new TreeNode(data,0,0);
    if(root == 0)
    {
        root = temp;
    }
    else
    {
        TreeNode *traverseNode,*insertNode;
        traverseNode = root;
        insertNode = 0;
        while(traverseNode != 0)
        {
            insertNode = traverseNode;
            if(data > traverseNode->data)
            {
                traverseNode = traverseNode->right;
            }
            else
            {
                traverseNode = traverseNode->left;
            }
            
        }
        if(data > insertNode->data)
        {
            insertNode->right = temp;
        }
        else 
        {
            insertNode->left = temp;
        }
    }
}

//search function
int BST :: search(int data)
{
    if(root == 0)
    {
        cout<<"Tree is Empty";
        return 0;
    }
    else
    {
        TreeNode *traverseNode = root;
        while (traverseNode != 0 )
        {
            if(traverseNode->data == data)
            {
                cout<<"Found in the Tree\n";
                return 1;
            }
            else if(data > traverseNode->data)
            {
                traverseNode = traverseNode->right;
            }
            else if(data < traverseNode->data)
            {
                traverseNode = traverseNode->left;
            }
        }
        cout<<"Element is not in the Tree\n";
        return 0;
    }
}

//inorder + Display function
void BST :: inorderRecursive(TreeNode* root)
{
    if(root != 0)
    {
        inorderRecursive(root->left);
        cout<<root->data<<" ";
        inorderRecursive(root->right);
    }
    return;
}

//preorder function
void BST :: preorderRecursive(TreeNode* root)
{
    if(root != 0)
    {
        cout<<root->data<<" ";
        preorderRecursive(root->left);
        preorderRecursive(root->right);
    }
    return;
}

//postorder function
void BST :: postorderRecursive(TreeNode* root)
{
    if(root != 0)
    {
        postorderRecursive(root->left);
        postorderRecursive(root->right);
        cout<<root->data<<" ";
    }
    return;
}

//inorder function (Iterative)
void BST :: inorderIterative()
{
    /*
        Algorithm from :- https://www.geeksforgeeks.org/inorder-tree-traversal-without-recursion/
    */
    TreeNode* traverseNode = root;
    StackLL<TreeNode*> *stack = new StackLL<TreeNode*>();
    while(stack->isEmpty() || (traverseNode != 0))
    {
        if(traverseNode != 0)
        {
            stack->push(traverseNode);
            traverseNode = traverseNode->left;
        }
        else
        {
            traverseNode = stack->topElement();
            cout<<traverseNode->data<<" ";
            stack->pop();
            traverseNode = traverseNode->right;
        }
    }
    delete stack;
}

//preorder function (Iterative)
void BST :: preorderIterative()
{
    /*
        Algorithm:- 
        1. Create an Empty Stack and Push root Node to the Stack
        2. While the Stack is not Empty:-
            2.1 Pop the Top of Stack
            2.2 Print the Top of Stack 
            2.3 Push the Top of Stack's Right Child if it exists (i.e not NULL)
            2.4 Push the Top of Stack's Left Child if it exits (i.e not NULL)
    */
    TreeNode *traverseNode = root;    
    StackLL<TreeNode*> *stack = new StackLL<TreeNode*>();
    stack->push(traverseNode);
    while(stack->isEmpty())
    {   
        traverseNode = stack->topElement();
        cout<<traverseNode->data<<" ";
        stack->pop();
        if(traverseNode->right != 0)
        {
            stack->push(traverseNode->right);
        }
        if(traverseNode->left != 0)
        {
            stack->push(traverseNode->left);
        }
    }
    traverseNode = 0;
    delete traverseNode;
    delete stack;
}

//inorder function (Iterative)
void BST :: postorderIterative()
{
    /*
        Algorithm:-
        1. Create Two Stacks and Push the root to First Stack.
        2. While the First Stack is not empty :
            2.1 Pop the Top of Stack of First Stack and Push it to Second Stack.
            2.3 Push the Left Child and Right Child of the First Stack respectively.
        3. Print the Second Stack. 
    */
   TreeNode* traverseNode = root;
   StackLL<TreeNode*> *stack_1 = new StackLL<TreeNode*>();
   StackLL<TreeNode*> *stack_2 = new StackLL<TreeNode*>();
   stack_1->push(traverseNode);
   while(stack_1->isEmpty())
   {
       traverseNode = stack_1->topElement();
       stack_1->pop();
       stack_2->push(traverseNode);
       if(traverseNode->left != 0)
       {
           stack_1->push(traverseNode->left);
       }
       if(traverseNode->right != 0)
       {
           stack_1->push(traverseNode->right);
       }
   }
   traverseNode = 0;
   while (stack_2->isEmpty())
   {
       cout<<stack_2->topElement()->data<<" ";
       stack_2->pop();
   }
   delete stack_1;
   delete stack_2;
}

//bfsTraversal
void BST :: bfsTraversal()
{
    TreeNode *traverseNode = root;
    queueLL<TreeNode*>* queue = new queueLL<TreeNode*>();
    queue->enqueue(traverseNode);
    while(!queue->isEmpty())
    {
        traverseNode = queue->firstEle();
        cout<<traverseNode->data<<" ";
        if(traverseNode->left != 0)
        {
            queue->enqueue(traverseNode->left);
        }
        if(traverseNode->right != 0)
        {
            queue->enqueue(traverseNode->right);
        }
        queue->dequeue();
    }
    traverseNode = 0;
    delete traverseNode;
    delete queue;
}

//count the number of leaf node and internal nodes
int BST :: leafNodes(TreeNode* root)
{
    if(root == 0)
    {
        return 0;
    }
    else if(root->left == 0 && root->right == 0)
    {
        return 1;
    }
    else
    {
        return leafNodes(root->left) + leafNodes(root->right);
    }
}

//count the number of internal Nodes
int BST :: internalNodes(TreeNode *root)
{
    if(root == 0 || (root->left == 0 && root->right == 0))
    {
        return 0;
    }
    return 1 + internalNodes(root->left) + internalNodes(root->right);

}

//find the height of the tree
int BST :: height(TreeNode* root)
{
    if(root == 0)
    {
        return -1;
    }
    //Lheight - Height of left sub tree Rheight - Height of right subtree
    int Lheight = height(root->left);
    int Rheight = height(root->right);
    int height = (Lheight > Rheight) ? Lheight : Rheight;
    return height + 1;
    
}

//delete node by merging
void BST :: deleteNodeMerging(int value)
{
    TreeNode *traverseNode = root;
    TreeNode *prevNode = root;
    //checking if the Tree is EMPTY
    if(traverseNode == 0)
    {
        cout<<"Tree is Empty\n";
        return;
    }
    else
    {
        //flag will decide whether the value exist in BST or not
        int flag = 0;
        //searching for the node->data == value
        while(traverseNode != 0)
        {
            if(traverseNode->data == value)
            {
                flag = 1;
                break;
            }
            else if (value > traverseNode->data)
            {
                prevNode = traverseNode;
                traverseNode = traverseNode->right;
            }
            else if (value < traverseNode->data)
            {
                prevNode = traverseNode;
                traverseNode = traverseNode->left;
           }
        }
        if(flag)
        {
            //Delete Leaf Node
            if(traverseNode->right == 0 && traverseNode->left == 0)
            {
                if(traverseNode == root)
                {
                    root = 0;
                }
                else
                {
                    if(prevNode->right == traverseNode)
                    {
                        prevNode->right = 0;
                    }
                    else if(prevNode->left == traverseNode)
                    {
                        prevNode->left = 0;
                    }
                }                
            }
            //Delete Node only One Sub-Tree or Child (Left)
            else if(traverseNode->left == 0 && traverseNode->right != 0)
            {
                //checking if the Node to be deleted is root Node
                if(traverseNode == prevNode)
                {
                    root = traverseNode->right;
                }

                if(prevNode->right == traverseNode)
                {
                    prevNode->right = traverseNode->right;
                }
                else
                {
                    prevNode->left = traverseNode->right;
                }
                    
            }
            //Delete Node only One Sub-Tree or Child (Right)
            else if(traverseNode->left != 0 && traverseNode->right == 0)
            {
                //checking if the Node to be deleted is root Node
                if(traverseNode == prevNode)
                {
                    root = traverseNode->left;
                }

                if(prevNode->right == traverseNode)
                {
                    prevNode->right = traverseNode->left;
                }
                else
                {
                    prevNode->left = traverseNode->left;
                }
            }
            else if(traverseNode->left != 0 && traverseNode->right != 0)
            {
                //getting the Left and Right Sub-Tree
                TreeNode *leftTree = traverseNode->left;
                TreeNode *rightTree = traverseNode->right;
                //finding the rightmost Node of the Left Sub-Tree
                TreeNode *rightmostLeft = leftTree;
                while(rightmostLeft->right != 0)
                {
                    rightmostLeft = rightmostLeft->right;
                }
                //connecting the Left Sub-Tree to Parent of traverseNode (i.e. Node to be deleted)
                if(prevNode == traverseNode)
                {
                    root = leftTree;
                }
                else if(prevNode->right == traverseNode)
                {
                    prevNode->right = leftTree;
                }
                else
                {
                    prevNode->left = leftTree;
                }
                //connecting the Right Sub-Tree to rightmost Node of Left Sub-Tree
                rightmostLeft->right = rightTree;
                leftTree = rightTree = rightmostLeft = 0;
            }
            delete traverseNode;
            traverseNode  = 0;
            prevNode = 0;    
        }
        else
        {
            cout<<"The Node with that Data doesn't exist in BST\n";
            return;
        }       
    }
    
}

//delete node using copying
void BST :: deleteNodeCopying(int value)
{
    TreeNode *traverseNode = 0;
    traverseNode = root;
    int data = value;
    //checking if the Tree is Empty
    if(traverseNode == 0)
    {
        cout<<"Tree is Empty\n";
        return;
    }
    else
    {
        //flag will decide whether the value exist in BST or not
        int flag = 0;
        //searching for the node->data == value
        while(traverseNode != 0)
        {
            if(traverseNode->data == value)
            {
                flag = 1;
                break;
            }
            else if (value > traverseNode->data)
            {
                traverseNode = traverseNode->right;
            }
            else if (value < traverseNode->data)
            {
                traverseNode = traverseNode->left;
           }
        }
        if(flag)
        {
            TreeNode* subtreeRoot = root;
            if(traverseNode->left != 0 && traverseNode->right != 0)
            {
                //getting the Left and Right Sub-Tree
                TreeNode *leftTree = traverseNode->left;
                //finding the rightmost Node of the Left Sub-Tree
                TreeNode *rightmostLeft = leftTree;
                while(rightmostLeft->right != 0)
                {
                    rightmostLeft = rightmostLeft->right;
                }
                //saving the value to be copied to traverseNode
                data = rightmostLeft->data;
            }
            cout<<"(Inorder Succesor) ";
            deleteNodeMerging(data);
            //copying the Inorder Successor to the Node to be deleted
            traverseNode->data = data;
        }
        else
        {
            cout<<"The Node with that Data doesn't exist in BST\n";
            return;
        }
        
    }
    
}

//find and replace an element x with y
void BST :: findAndReplace(int x,int y)
{
    if(search(x))
    {
        deleteNodeMerging(x);
        insert(y);
    }
}

//clear function (used in Destructor)
void BST :: clear(TreeNode *root)
{
    TreeNode *temp = 0;
    if(root != 0)
    {
        clear(root->left);
        clear(root->right);
        temp = root;
        delete temp;
    }
    return;
}

int main()
{
    BST *tree = new BST();
    int flag = true;
    int choice = 0;
    int data = 0; 
    do
    {
        cout<<"================================================\n"
            <<"Binary Search Tree : ";tree->inorderRecursive(tree->returnRoot());
        cout<<"\n================================================\n"
            <<"Operations:\n"
            <<"1. Insert\n"
            <<"2. Search\n"
            <<"3. Inorder Traversal (recursive)\n"
            <<"4. Preorder Traversal (recursive)\n"
            <<"5. Postorder Traversal (recursive)\n"
            <<"6. Inorder Traversak (iterative)\n"
            <<"7. Preorder Traversal (iterative)\n"
            <<"8. Postorder Traversal (iterative)\n"
            <<"9. BFS Traversal\n"
            <<"10. Number of Leaf and Non-Leaf Node\n"
            <<"11. Height of Tree\n"
            <<"12. Delete a Node (by Merging\n"
            <<"13. Delete a Node (by Copying)\n"
            <<"14. Find and Replace a Value\n"
            <<"Enter Operation : "; cin>>choice;
        switch (choice)
        {
            case 1:
                cout<<"Enter Data : "; cin>>data;
                tree->insert(data);
                break;
            case 2:
                cout<<"Enter Data : "; cin>>data;
                tree->search(data);
                break;
            case 3:
                tree->inorderRecursive(tree->returnRoot());
                break;
            case 4:
                tree->preorderRecursive(tree->returnRoot());
                break;
            case 5:
                tree->postorderRecursive(tree->returnRoot());
                break;
            case 6:
                tree->inorderIterative();
                break;
            case 7:
                tree->preorderIterative();
                break;
            case 8:
                tree->postorderIterative();
                break;
            case 9:
                tree->bfsTraversal();
                break;
            case 10:
                cout<<"Leaf Nodes : "<<tree->leafNodes(tree->returnRoot())<<"\n";
                cout<<"Internal Nodes : "<<tree->internalNodes(tree->returnRoot())<<"\n";
                cout<<"Total Nodes : "<<tree->leafNodes(tree->returnRoot()) + tree->internalNodes(tree->returnRoot());
                break;
            case 11:
                cout<<"Height of Tree : "<<tree->height(tree->returnRoot())<<"\n";
                break;
            case 12:
                cout<<"Enter the Value to be deleted : "; cin>>data;
                tree->deleteNodeMerging(data);
                break;
            case 13:
                cout<<"Enter the Value to be deleted : "; cin>>data;
                tree->deleteNodeCopying(data);
                break;
            case 14:
                int x,y;
                cout<<"Value to be Replaced : "; cin>>x;
                cout<<"Value to Replace : "; cin>>y;
                tree->findAndReplace(x,y);
                break;
            default:
                flag = 0;
                break;
        }
        // getch();
        // system("CLS");
    }
    while (flag);
    delete tree;
    return 0;
}