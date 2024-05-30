// A Dictionary stores keywords and its meanings. Provide facility for adding new keywords, deleting keywords, updating values of any entry. Provide facility to display whole data sorted in ascending/ Descending order. Also find how many maximum comparisons may require for finding any keyword. Use Binary Search Tree for implementation.

//BST Dictionary 
#include <iostream>
#include <string>


using namespace std;
string key;
int flag = 0;
class node
{


public:
    node *left;
    string wdata, mean;
    node *right;
};


class binary
{
public:
    node *root;
    node *temp;


    binary()
    {
        root = NULL;
    }
    void create();
    void insert(node *, node *);
    void Display();
    void ascending(node *);
    void descending(node *);
    void search(node *, string key);
    void update(node *, string key);
    int DeleteNode(node *, string key);
};


// Create Dictionary
void binary::create()
{
    int op;
    do
    {
        temp = new node;


        cout << "Enter the word :";
        cin >> temp->wdata;
        cout << "Enter the Meaning of word :";
        cin >> temp->mean;
        temp->left = NULL;
        temp->right = NULL;


        if (root == NULL)
        {
            root = temp;
        }
        else
        {
            insert(root, temp);
        }
        cout << "Do you want to continue, press 1 : ";
        cin >> op;
    } while (op == 1);
}


// Insert in Dictionary
void binary::insert(node *root, node *temp)
{
    char ch;
    // cout<<"Root Node:-"<<root->data;
    if (temp->wdata < root->wdata)
    {
        if (root->left == NULL)
        {
            root->left = temp;
        }
        else
            insert(root->left, temp);
    }
    else if (temp->wdata > root->wdata)
    {


        if (root->right == NULL)
        {
            root->right = temp;
        }
        else
            insert(root->right, temp);
    }
}


// Display Dictionary
void binary::Display()
{
    cout << "=============Dictionary===============";
    cout << "\nAscending :\n";
    ascending(root);
    cout << "\nDescending :\n";
    descending(root);
}
// Ascending Order
void binary::ascending(node *root)
{
    if (root != NULL)
    {
        ascending(root->left);
        cout << "Word:" << root->wdata << "   Meaning:" << root->mean << "\n";
        ascending(root->right);
    }
}
// Decending Order
void binary::descending(node *root)
{
    if (root != NULL)
    {
        descending(root->right);
        cout << "Word:" << root->wdata << "   Meaning:" << root->mean << "\n";
        descending(root->left);
    }
}
// Search meaning by word
void binary::search(node *root, string key)
{


    if (root != NULL)
    {


        if (key == root->wdata)
        // if(key.compare(root->wdata))


        {
            cout << "---------------Word Found------------\n";
            cout << "Word:" << root->wdata << " Meaning:" << root->mean << "\n";
        }
        else if (key < root->wdata)
        {
            search(root->left, key); // Traverse to left
        }
        else if (key > root->wdata)
        {
            search(root->right, key); // Traverse to right
        }
    }


    else
    {
        cout << "--------Word not Found----------\n";
    }
}


// Update Word meaning in dictionary
void binary::update(node *root, string key)
{


    if (root != NULL)
    {


        if (key == root->wdata)
        // if(key.compare(root->wdata))


        {
            cout << "\nEnter New Meaning of Keyword:";
            cin >> root->mean;
            cout << "Word:" << root->wdata << " Meaning:" << root->mean << "\n";
            flag = 1;
        }
        else if (key < root->wdata)
        {
            update(root->left, key);
        }
        else if (key > root->wdata)
        {
            update(root->right, key);
        }
    }
    else
    {
        cout << "Element is not found...\n";
    }
}


node *DeleteNode(node *root, string key)
{
    if (root == NULL)
        return NULL;


    if (key < root->wdata)
        root->left = DeleteNode(root->left, key);


    else if (key > root->wdata)
        root->right = DeleteNode(root->right, key);


    else
    {
        // Leaf node.
        if (root->left == NULL && root->right == NULL)
        {
            free(root);
            return NULL;
        }


        // Node has right child.
        if (root->left == NULL)
        {
            node *curr = root->right;
            free(root);
            return curr;
        }


        // Node has left child.
        else if (root->right == NULL)
        {
            node *curr = root->left;
            free(root);
            return curr;
        }


        // Node has both left and right children.
        else
        {


            node *curr = root->right;


            while (curr->left != NULL)
                curr = curr->left;
            root->wdata = curr->wdata;
            root->right = DeleteNode(root->right, curr->wdata);
        }
    }
    return root;
}
int main()
{
    binary nd;
    int ch;


    while (1)
    {
        cout << "=============Dictionary Using BST===============";
        cout << "\n1)Insert\n2)Display\n3)Search\n4)Update\n5)Delete\n6)Exit";
        cout << "\nEnter your choice:";
        cin >> ch;
        switch (ch)
        {
        case 1:
            nd.create();
            break;


        case 2:
            nd.Display();
            break;


        case 3:
            cout << "Enter word to search meaning: ";
            cin >> key;
            nd.search(nd.root, key);
            break;


        case 4:
            cout << "\nEnter a word to update meaning: ";
            cin >> key;
            nd.update(nd.root, key);
            break;


        case 5:
            cout << "\nEnter a word to delete: ";
            cin >> key;
            DeleteNode(nd.root, key);
            break;


        case 6:
            cout << "Thank you...!!";
            break;


        default:
            cout << "Invalid choice..\n";
        }
    }
    return 0;
}
