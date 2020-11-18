/*
* Title: hw8_1.cpp
* Abstract: Program contains inorder, preorder, levelorder, postorder traversals and can tell if tree is BST
            and retrieve height of tree.
* Author: Roy Morla
* ID: 0327
* Date: 10/29/20
*/
#include <iostream>
#include<string>
#include <queue>
#include <climits>
#include <algorithm>

using namespace std;

struct Node 
{
	// Data part for a node. 
    int data;
    Node* left;
    Node* right;

    // Constructor for a new node.
    Node(int d) 
    {
        data = d;
        left = nullptr;
        right = nullptr;
    }
};
 
void inorder(Node* node) {
    if (node == NULL)
        return;
 
    inorder(node->left);
    cout << node->data << " ";
    inorder(node->right);
}

void preorder(Node* node) {
    if (node == NULL) 
        return; 
  
    cout << node->data << " "; 
    preorder(node->left);  
    preorder(node->right); 
}

void postorder(Node* node) { 
    if (node == NULL) 
        return; 

    postorder(node->left); 
    postorder(node->right); 
    cout << node->data << " "; 
} 

void levelorder(Node* root) {
    if (root == NULL)  
        return;
 
    queue<Node*> q;
 
    q.push(root);
 
    while (!q.empty()) {
        Node* node = q.front();
        cout << node->data << " ";
        q.pop();
 
        if (node->left != NULL)
            q.push(node->left);

        if (node->right != NULL)
            q.push(node->right);
    }
}

int height(Node* node) { 
	if(node==NULL)
		return 0;
	else
	{
		int left_height=height(node->left);
		int right_height=height(node->right);
		return max(left_height,right_height)+1;
	}
}

Node* append(Node* root, int data) {

    if (root == NULL) {
        root = new Node(data);
        return root;
    }
 

    queue<Node*> q;
    q.push(root);
 
    while (!q.empty()) {
        Node* t = q.front();
        q.pop();
 
        if (t->left != NULL)
            q.push(t->left);
        else {
            t->left = new Node(data);
            return root;
        }
 
        if (t->right != NULL)
            q.push(t->right);
        else {
            t->right = new Node(data);
            return root;
        }
    }
}

int findFirstNode(Node* node) {
    if (node->left != NULL) {
        return findFirstNode(node->left);
    }
    else if (node->right != NULL) {
        return findFirstNode(node->right); 
    }         
    return node->data;
}

bool isBSThelper(Node* root , int& last) { 
    if (root) { 
        if (!isBSThelper(root->left, last)) 
            return false; 
  
        if (root->data <= last) 
            return false; 
  
        last = root->data; 
        return isBSThelper(root->right, last); 
    } 
    return true; 
} 
  
bool isBST(Node* root) 
{ 
    int last = INT_MIN; 
    return isBSThelper(root, last); 
} 


int main() 
{
    int root;
    int commands;
    cin >> root;
    Node* rootNode = new Node(root);
    cin >> commands;
    int data;
    string command;
    for (int i = 0; i < commands; i++) {
        cin >> command;
        if (command == "append") {
            cin >> data;
            append(rootNode,data);
        }
        else if (command == "isBST") {
            cout << boolalpha << isBST(rootNode) << endl;
        }
        else if (command == "inOrder") {
            inorder(rootNode);
            cout << endl;
        }
        else if (command == "preOrder") {
            preorder(rootNode);
            cout << endl;
        }
        else if (command == "postOrder") {
            postorder(rootNode);
            cout << endl;
        }
        else if (command == "levelOrder") {
            levelorder(rootNode);
            cout << endl;

        }
        else if (command == "height") {
            cout << height(rootNode)-1;
            cout << endl;
        }
        else if (command == "findFirstNode") {
            cout << findFirstNode(rootNode);
             cout << endl;
        }
    }    
    return 0;
}


