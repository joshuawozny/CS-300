//============================================================================
// Name         : BinarySearchTree.cpp
//Last Updated  : February 5, 2023
// Author       : Joshua Wozny
// Version      : 1.0
// Copyright    : Copyright © 2023,  portions Copyright © 2017 SNHU COCE
// Description  : Binary Tree Project, CS-300: Binary Search Tree object
//============================================================================

#include <iostream>

#include "BinarySearchTree.h"

using namespace std;

//============================================================================
// Global definitions visible to all methods and classes
//============================================================================


Node* minValueNode(Node* node);

/**
 * Default constructor
 */
BinarySearchTree::BinarySearchTree() {
    // FixMe (1): initialize housekeeping variables
    //root is equal to nullptr
    root = nullptr;
}

/**
 * Destructor
 */
BinarySearchTree::~BinarySearchTree() {
    // recurse from root deleting every node
    delete root;
}

/**
 * Traverse the tree in order
 */
void BinarySearchTree::InOrder() {
    // FixMe (2): In order root
    // call inOrder fuction and pass root 
    inOrder(root);
}

/**
 * Traverse the tree in post-order
 */
void BinarySearchTree::PostOrder() {
    // FixMe (3): Post order root
    // postOrder root
    postOrder(root);
}

/**
 * Traverse the tree in pre-order
 */
void BinarySearchTree::PreOrder() {
    // FixMe (4): Pre order root
    // preOrder root
    preOrder(root);
}

/**
 * Insert a bid
 */
void BinarySearchTree::Insert(Bid bid) {
    // FIXME (5) Implement inserting a bid into the tree
    // if root equarl to null ptr
        // root is equal to new node bid
    if (root == nullptr)
        root = new Node(bid);
  // else
      // add Node root and bid
    else
        addNode(root, bid);
}

/**
 * Remove a bid
 */
void BinarySearchTree::Remove(string bidId) {
    // FIXME (6) Implement removing a bid from the tree
    // remove node root bidID
    removeNode(root, bidId);
}

/**
 * Search for a bid
 */
Bid BinarySearchTree::Search(string bidId) {
    // FIXME (7) Implement searching the tree for a bid
    // set current node equal to root
    // keep looping downwards until bottom reached or matching bidId found
        // if match found, return current bid
        // if bid is smaller than current node then traverse left
        // else larger so traverse right
    int depth = 0;
    Node* temp = new Node();
    temp = this->root;
    // Run the loop untill temp points to a NULL pointer.
    while (temp != NULL)
    {
        if (temp->key() == bidId)
        {
            return temp->bid;
        }
        // Shift pointer to left child.
        else if (temp->key() > bidId)
            temp = temp->left;
        // Shift pointer to right child.
        else
            temp = temp->right;
    }

    cout << "\n Data not found\n" << endl;
    return Bid();
}

/**
 * Add a bid to some node (recursive)
 *
 * @param node Current node in tree
 * @param bid Bid to be added
 */
Node* BinarySearchTree::addNode(Node* node, Bid bid) {
    // FIXME (8) Implement inserting a bid into the tree
    // Return a new node if the tree is empty
    if (node == nullptr) return new Node(bid);

    // Traverse to the right place and insert the node
    if (bid.bidId < node->key())
        node->left = addNode(node->left, bid);
    else
        node->right = addNode(node->right, bid);

    return node;


}
void BinarySearchTree::inOrder(Node* node) {
      // FixMe (9): Pre order root
      //if node is not equal to null ptr
    if (node==nullptr) 
        return;
    //InOrder left
    inOrder(node->left);
      //output bidID, title, amount, fund
    cout << node->bid.bidId << " | " << node->bid.title << " | " << node->bid.amount << " | " << node->bid.fund << endl;
      //InOder right
    inOrder(node->right);
}

void BinarySearchTree::postOrder(Node* node) {
      // FixMe (10): Pre order root
      //if node is not equal to null ptr
    if (node == nullptr)
        return;
      //postOrder left
    postOrder(node->left);
      //postOrder right
    postOrder(node->right);
      //output bidID, title, amount, fund
    cout << node->bid.bidId << " | " << node->bid.title << " | " << node->bid.amount << " | " << node->bid.fund;

}

void BinarySearchTree::preOrder(Node* node) {
      // FixMe (11): Pre order root
      //if node is not equal to null ptr
    if (node == nullptr)
        return;
      //output bidID, title, amount, fund
    cout << node->bid.bidId << " | " << node->bid.title << " | " << node->bid.amount << " | " << node->bid.fund;
      //preOrder left
    preOrder(node->left);
      //preOrder right    
    preOrder(node->left);
}

Node* BinarySearchTree::removeNode(Node* root, string bidId) {
    // base case
    if (root == nullptr)
        return root;

    // If the key to be deleted is
    // smaller than the root's
    // key, then it lies in left subtree
    if (bidId < root->key())
        root->left = removeNode(root->left, bidId);

    // If the key to be deleted is
    // greater than the root's
    // key, then it lies in right subtree
    else if (bidId > root->key())
        root->right = removeNode(root->right, bidId);

    // if key is same as root's key, then This is the node
    // to be deleted
    else {
        // node has no child
        if (root->left == nullptr and root->right == nullptr)
            return nullptr;

        // node with only one child or no child
        else if (root->left == nullptr) {
            Node* temp = root->right;
            delete root;
            return temp;
        }
        else if (root->right == nullptr) {
            Node* temp = root->left;
            delete root;
            return temp;
        }

        // node with two children: Get the inorder successor
        // (smallest in the right subtree)
        Node* temp = minValueNode(root->right);

        // Copy the inorder successor's content to this node
        root->bid = temp->bid;

        // Delete the inorder successor
        root->right = removeNode(root->right, temp->key());
    }
    return root;
}