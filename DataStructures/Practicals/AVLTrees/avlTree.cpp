#include <iostream>
#include <conio.h>
using namespace std;

//Tree Node
class TreeNode
{
    public:
        TreeNode *left,*right;
        int data,balanceFactor;
        //constructor
        TreeNode(int data = 0, TreeNode* left = 0, TreeNode* right = 0)
        {
            this->data = data;
            this->left = left;
            this->right = right;
            balanceFactor = 0;
        }
        //destructor
        ~TreeNode()
        {
            cout<<"Deleting TreeNode with Data :  "<<this->data<<"\n";
        }
};

class AVLTree
{
    private:
    public:
        TreeNode *root;
        AVLTree()
        {
            root = 0;
        }
        ~AVLTree()
        {
            clear(this->root);
        }
        //member function
        TreeNode* returnRoot();
        void clear(TreeNode *root);
        int height(TreeNode *root);
        void setBalanceFactor(TreeNode *root);
        int getBalanceFactor(TreeNode *root);
        TreeNode *right(TreeNode* u);
        TreeNode *left(TreeNode* u);
        void display(TreeNode* root);
        TreeNode* insert(TreeNode *root,int data);
        TreeNode* _delete(TreeNode* root,int data);
};

//return Root TreeNode
TreeNode* AVLTree :: returnRoot()
{
    return root;
}

//clear function (used in Destructor)
void AVLTree :: clear(TreeNode *root)
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

//find the height of the tree
int AVLTree :: height(TreeNode* root)
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

//set the balance factor of all the nodes in the tree
void AVLTree :: setBalanceFactor(TreeNode *root)
{
    if(root != 0)
    {
        root->balanceFactor = height(root->left) - height(root->right);
        setBalanceFactor(root->left);
        setBalanceFactor(root->right);
    }
}

// get the balance factor of a particular node
int AVLTree :: getBalanceFactor(TreeNode *root)
{
    if(root == 0)
    {
        return 0;
    }
    return (height(root->left) - height(root->right));
}

//rotate left
TreeNode* AVLTree :: right(TreeNode* u)
{
    TreeNode *x = u->left;
    TreeNode *y = u;
    y->left = x->right;
    x->right = y;
    return x;
}

//rotate rirightght
TreeNode* AVLTree :: left(TreeNode* u)
{
    TreeNode *x = u->right;
    TreeNode *y = u;
    y->right = x->left;
    x->left = y;
    return x;
}

//diaplay function using preorder traversal to show (bf, data)
void AVLTree :: display(TreeNode* root)
{
    if(root != 0)
    {
        cout<<"("<<root->balanceFactor<<" "<<root->data<<") ";
        display(root->left);
        display(root->right);
    }
    return;
}

//insert a node
TreeNode* AVLTree :: insert(TreeNode* root,int data)
{
    if(root == 0)
    {
        return new TreeNode(data,0,0);
    }
    else
    {
        if(root->data < data)
        {
            root->right = insert(root->right,data);
        }
        else if(root->data > data)
        {
            root->left = insert(root->left,data);
        } 
    }

    if(root != 0)
    {
        int balanceFactor = getBalanceFactor(root);
        if(balanceFactor > 1 && data < root->left->data)
        {
            //Left Left Case
            //Right Rotation
            root = right(root);

        }
        else if(balanceFactor < -1 && data > root->right->data)
        {
            //Right Right Case
            //Left Rotation
            root = left(root);
        }
        else if(balanceFactor < -1 && data < root->right->data)
        {
            //Right Left Case
            //Right Rotation
            root->right = right(root->right);
            //Left Rotation
            root = left(root);
        }
        else if(balanceFactor > 1 && data > root->left->data)
        {
            //Left Right Case
            //left rotating 
            root->left = left(root->left);
            //right rotating
            root = right(root);
        }
    }
    return root;
}

//delete a node
TreeNode* AVLTree :: _delete(TreeNode* root,int data)
{
    if(root != 0)
    {
        if(root->data == data)
        {
            TreeNode *temp = 0;
            if(root->left != 0 && root->right == 0)
            {
                temp = root;
                root = root->left;
                delete temp;
            }
            else if(root->left == 0 && root->right != 0)
            {
                TreeNode *temp = root;
                root = root->right;
                delete temp;
            }
            else if(root->left != 0 && root->right != 0)
            {
                //getting the Left and Right Sub-Tree
                TreeNode *leftTree = root->left;
                //finding the rightmost Node of the Left Sub-Tree
                TreeNode *rightmostLeft = leftTree;
                while(rightmostLeft->right != 0)
                {
                    rightmostLeft = rightmostLeft->right;
                }
                //saving the value to be copied to traverseNode
                int d = rightmostLeft->data;
                root = _delete(root,rightmostLeft->data);
                root->data = d;
            }
            else if(root->left == 0 && root->right == 0)
            {
                delete root;
                root = 0;
            }            
            return root;
        }
        else if(root->data < data)
        {
            root->right = _delete(root->right,data);
        }
        else if(root->data > data)
        {
            root->left = _delete(root->left,data);
        }


        if(root != 0)
        {
            int balanceFactor = getBalanceFactor(root);
            int bfRight = getBalanceFactor(root->right);
            int bfLeft = getBalanceFactor(root->left);
            if(balanceFactor > 1 && bfLeft >= 0)
            {
                //Left Left Case
                //Right Rotation
                root = right(root);

            }
            else if(balanceFactor < -1 && bfRight <= 0)
            {
                //Right Right Case
                //Left Rotation
                root = left(root);
            }
            else if(balanceFactor < -1 && bfRight > 0)
            {
                //Right Left Case
                //Right Rotation
                root->right = right(root->right);
                //Left Rotation
                root = left(root);
            }
            else if(balanceFactor > 1 && bfLeft < 0)
            {
                //Left Right Case
                //left rotating 
                root->left = left(root->left);
                //right rotating
                root = right(root);
            }            
        }
    }
    return root;
}


int main()
{
    AVLTree *tree = new AVLTree();
    int flag = true;
    int choice = 0;
    int data = 0; 
    cout<<"Node -> (balance factor, data)\n";
    do
    {
        cout<<"AVL Tree : ";tree->display(tree->returnRoot());
        cout<<"\nOperations:\n"
            <<"1. Insert\n"
            <<"2. Delete\n"
            <<"Enter Operation : "; cin>>choice;
        switch (choice)
        {
            case 1:
                cout<<"Enter Data : "; cin>>data;
                tree->root = tree->insert(tree->returnRoot(),data);
                break;
            case 2:
                cout<<"Enter Data : "; cin>>data;
                tree->root = tree->_delete(tree->returnRoot(),data);
                break;
            default:
                flag = 0;
                break;
        }
        tree->setBalanceFactor(tree->returnRoot());
        // getch();
        // system("CLS");
        cout<<"\n";
    }
    while(flag);
    delete tree;
    return 0;
}

