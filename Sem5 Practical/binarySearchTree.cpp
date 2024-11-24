#include <iostream>
using namespace std;

class Node {

public:
  int data;
  Node *left;
  Node *right;

  Node(int data) {
    this->data = data;
    this->left = nullptr;
    this->right = nullptr;
  }
};

Node *insert(Node *&root, int data) {
  // Base case: If the root is nullptr, create and return a new node
  if (root == nullptr) {
    root = new Node(data);
    return root;
  }

  // Recursive case: Traverse the tree to find the correct position
  if (data > root->data) {
    // If data is greater, insert it in the right subtree
    root->right = insert(root->right, data);
  } else {
    // If data is smaller or equal, insert it in the left subtree
    root->left = insert(root->left, data);
  }

  // Return the unchanged root
  return root;
}

bool search(Node *root, int data) {
  if (root == nullptr) {
    return false;
  }
  if (root->data == data) {
    return true;
  }

  if (data > root->data) {
    return search(root->right, data);
  } else {
    return search(root->left, data);
  }
}

int main() {
  cout << "Enter the number of nodes to enter : ";
  int n;
  cin >> n;

  cout << "Enter Node 1 : ";
  int rootValue;
  cin >> rootValue;

  Node *root = new Node(rootValue);
  for (int i = 1; i < n; i++) {
    unsigned int temp;
    cout << "Enter Node " << i + 1 << " : ";
    cin >> temp;
    insert(root, temp);
  }

  cout << "\nEnter the node you want to search in the tree: ";
  unsigned int searchNode;
  cin >> searchNode;

  bool result = search(root, searchNode);

  if (result) {
    cout << "Node is present in the Tree";
  } else {
    cout << "Node is not present in the Tree";
  }

  return 0;
}