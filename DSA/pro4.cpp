//Construct an expression tree from the given prefix expression eg. +--a*bc/def and traverse it using post order traversal (non-recursive) and then delete the entire tree.

// Expression Tree
#include <iostream>
#include <stack>
#include <string>
using namespace std;
class node
{
public:
    node *right;
    node *left;
    node *root;
    char data;
    node(char data, node *left, node *right)
    {
        this->data = data;
        this->left = left;
        this->right = right;
    }
    node(char data)
    {
        this->data = data;
    }
    node()
    {
        root = NULL;
    }
};
bool isOperator(char c)
{
    return (c == '+' || c == '-' || c == '*' || c == '/' || c == '^');
}
void postorder(node *root)


{
    if (root != NULL)
    {
        postorder(root->left);
        postorder(root->right);
        cout << " " << root->data;
    }
}
void inorder(node *root)
{
    if (root == NULL)
    {
        return;
    }
    if (isOperator(root->data))
    {
        cout << "(";
    }
    inorder(root->left);
    cout << root->data;
    inorder(root->right);
    if (isOperator(root->data))
    {
        cout << ")";
    }
}
node *exptree(string postfix)
{
    if (postfix.length() == 0)
    {


        return NULL;
    }
    // create an empty stack to store tree pointers
    stack<node *> s;
    // traverse the postfix exp
    for (char c : postfix)
    {
        if (isOperator(c))
        {
            node *x = s.top();
            s.pop();
            node *y = s.top();
            s.pop();
            node *nod = new node(c, y, x);
            s.push(nod);
        }
        else
        {
            s.push(new node(c));
        }
    }
    return s.top();
}
int main()
{
    // string postfix = "ab+cde+**";
    string postfix;
    cout << "Enter the expression:";
    cin >> postfix;
    node *root = exptree(postfix);
    cout << "Postfix Expression: ";
    postorder(root);
    cout << "\nInfix Expression: ";
    inorder(root);
    cout << "\n";
    return 0;
}
