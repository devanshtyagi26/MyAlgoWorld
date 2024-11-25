#include <iostream>
using namespace std;

// TreeNode class represents a single node in the B-Tree
class TreeNode {
  int *keys;    // Array to store keys in the node
  int t;        // Minimum degree of the B-Tree
  TreeNode **C; // Array of child pointers
  int n;        // Current number of keys in the node
  bool leaf;    // True if the node is a leaf

public:
  TreeNode(int temp, bool bool_leaf);

  void insertNonFull(int k);           // Insert a key into a non-full node
  void splitChild(int i, TreeNode *y); // Split a child node when it's full
  void traverse(); // Print the keys in the subtree rooted at this node
  TreeNode *
  search(int k); // Search for a key in the subtree rooted at this node

  friend class BTree; // Grant BTree access to private members
};

// BTree class encapsulates the B-Tree functionality
class BTree {
  TreeNode *root; // Pointer to the root node
  int t;          // Minimum degree of the B-Tree

public:
  BTree(int temp) {
    root = NULL; // Initially, the tree is empty
    t = temp;    // Set the minimum degree
  }

  void traverse() {
    if (root != NULL)
      root->traverse(); // Traverse the tree if the root is not NULL
  }

  TreeNode *search(int k) {
    return (root == NULL)
               ? NULL
               : root->search(k); // Search for a key starting from the root
  }

  void insert(int k); // Insert a new key into the B-Tree
};

// Constructor for TreeNode
TreeNode::TreeNode(int t1, bool leaf1) {
  t = t1;                    // Set the minimum degree
  leaf = leaf1;              // Set whether the node is a leaf
  keys = new int[2 * t - 1]; // Allocate memory for the maximum number of keys
  C = new TreeNode *[2 * t]; // Allocate memory for child pointers
  n = 0;                     // Initialize the number of keys to 0
}

// Traverse the subtree rooted at this node
void TreeNode::traverse() {
  int i;
  // Print all keys in this node and recursively traverse child nodes
  for (i = 0; i < n; i++) {
    if (!leaf)
      C[i]->traverse();
    cout << " " << keys[i];
  }

  // Traverse the last child
  if (!leaf)
    C[i]->traverse();
}

// Search for a key in the subtree rooted at this node
TreeNode *TreeNode::search(int k) {
  int i = 0;
  // Find the first key greater than or equal to k
  while (i < n && k > keys[i])
    i++;

  // If the key is found, return this node
  if (keys[i] == k)
    return this;

  // If the key is not found and this is a leaf node, return NULL
  if (leaf)
    return NULL;

  // Recur to the appropriate child
  return C[i]->search(k);
}

// Insert a new key into the B-Tree
void BTree::insert(int k) {
  if (root == NULL) {
    // If the tree is empty, create a new root
    root = new TreeNode(t, true);
    root->keys[0] = k; // Insert the key into the root
    root->n = 1;       // Update the number of keys in the root
  } else {
    // If the root is full, split it and create a new root
    if (root->n == 2 * t - 1) {
      TreeNode *s = new TreeNode(t, false); // Create a new root
      s->C[0] = root; // Old root becomes the first child of the new root
      s->splitChild(0, root); // Split the old root

      // Determine which child will receive the new key
      int i = (s->keys[0] < k) ? 1 : 0;
      s->C[i]->insertNonFull(k);

      root = s; // Update the root
    } else {
      // If the root is not full, insert the key into the root
      root->insertNonFull(k);
    }
  }
}

// Insert a key into a non-full node
void TreeNode::insertNonFull(int k) {
  int i = n - 1; // Start from the rightmost key

  if (leaf) {
    // If this is a leaf node, shift keys to make space for the new key
    while (i >= 0 && keys[i] > k) {
      keys[i + 1] = keys[i];
      i--;
    }

    // Insert the new key at the found position
    keys[i + 1] = k;
    n = n + 1;
  } else {
    // If this is not a leaf, find the child where the key should be inserted
    while (i >= 0 && keys[i] > k)
      i--;

    // Check if the found child is full
    if (C[i + 1]->n == 2 * t - 1) {
      splitChild(i + 1, C[i + 1]); // Split the child

      // Determine which of the two children will receive the key
      if (keys[i + 1] < k)
        i++;
    }
    C[i + 1]->insertNonFull(k); // Recur to the appropriate child
  }
}

// Split a full child node
void TreeNode::splitChild(int i, TreeNode *y) {
  TreeNode *z = new TreeNode(y->t, y->leaf); // Create a new node
  z->n = t - 1; // Update the number of keys in the new node

  // Move the last (t-1) keys of y to z
  for (int j = 0; j < t - 1; j++)
    z->keys[j] = y->keys[j + t];

  // Move the last t children of y to z
  if (!y->leaf) {
    for (int j = 0; j < t; j++)
      z->C[j] = y->C[j + t];
  }

  y->n = t - 1; // Update the number of keys in y

  // Shift children of this node to make space for the new child
  for (int j = n; j >= i + 1; j--)
    C[j + 1] = C[j];

  // Link the new child to this node
  C[i + 1] = z;

  // Shift keys of this node to make space for the new key
  for (int j = n - 1; j >= i; j--)
    keys[j + 1] = keys[j];

  // Insert the middle key of y into this node
  keys[i] = y->keys[t - 1];
  n = n + 1; // Update the number of keys in this node
}

int main() {
  BTree t(5); // Create a B-Tree with minimum degree 5
  t.insert(4);
  t.insert(5);
  t.insert(50);
  t.insert(21);
  t.insert(5);
  t.insert(3);
  t.insert(15);
  t.insert(75);
  t.insert(2);
  t.insert(3);

  cout << "The B-tree is: ";
  t.traverse();

  int k = 3;
  (t.search(k) != NULL) ? cout << endl
                               << k << " is found"
                        : cout << endl
                               << k << " is not Found";

  k = 25;
  (t.search(k) != NULL) ? cout << endl
                               << k << " is found"
                        : cout << endl
                               << k << " is not Found\n";

  return 0;
}