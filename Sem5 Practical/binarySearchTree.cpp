#include <iostream>
using namespace std;

// Define the Node class for the binary search tree (BST)
class Node {
public:
  int data;     // Data stored in the node
  Node *left;   // Pointer to the left child
  Node *right;  // Pointer to the right child

  // Constructor to initialize a new node with data and nullptr for left and right pointers
  Node(int data) {
    this->data = data;    // Set the data of the node
    this->left = nullptr;  // Set the left child to nullptr
    this->right = nullptr; // Set the right child to nullptr
  }
};

// Function to insert a node in the correct position in the BST
Node* insert(Node *&root, int data) {
  // Base case: If the root is nullptr, create and return a new node
  if (root == nullptr) {
    root = new Node(data);  // Create a new node with the given data
    return root;            // Return the new node as the root
  }

  // Recursive case: Traverse the tree to find the correct position
  if (data > root->data) {
    // If data is greater, insert it in the right subtree
    root->right = insert(root->right, data);  // Recursively insert in the right subtree
  } else {
    // If data is smaller or equal, insert it in the left subtree
    root->left = insert(root->left, data);  // Recursively insert in the left subtree
  }

  // Return the unchanged root pointer after the insertion
  return root;
}

// Function to search for a node in the BST
bool search(Node *root, int data) {
  // If the root is nullptr, the tree is empty or we've reached the end without finding the data
  if (root == nullptr) {
    return false;  // Node not found
  }

  // If the current node's data matches the search data, return true
  if (root->data == data) {
    return true;  // Node found
  }

  // If the data is greater than the current node's data, search in the right subtree
  if (data > root->data) {
    return search(root->right, data);  // Recursively search the right subtree
  } else {
    // If the data is smaller, search in the left subtree
    return search(root->left, data);   // Recursively search the left subtree
  }
}

int main() {
  // Prompt the user for the number of nodes to insert
  cout << "Enter the number of nodes to enter : ";
  int n;
  cin >> n;  // Read the number of nodes

  // Ask the user for the value of the root node
  cout << "Enter Node 1 : ";
  int rootValue;
  cin >> rootValue;  // Read the value for the root node

  // Create the root node of the tree
  Node *root = new Node(rootValue);

  // Insert the remaining nodes into the tree
  for (int i = 1; i < n; i++) {
    unsigned int temp;
    cout << "Enter Node " << i + 1 << " : ";
    cin >> temp;  // Read the value of the next node
    insert(root, temp);  // Insert the node into the tree
  }

  // Ask the user for a value to search in the tree
  cout << "\nEnter the node you want to search in the tree: ";
  unsigned int searchNode;
  cin >> searchNode;  // Read the value to search

  // Perform the search and store the result
  bool result = search(root, searchNode);

  // Output whether the node was found or not
  if (result) {
    cout << "Node is present in the Tree";
  } else {
    cout << "Node is not present in the Tree";
  }

  return 0;
}