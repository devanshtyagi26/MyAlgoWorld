#include <iomanip>
#include <iostream>
#include <string>

using namespace std;

// TrieNode class represents a single node in the Trie
class TrieNode {
public:
  char data;              // The character stored in this node
  TrieNode *children[26]; // Array to store references to child nodes (for A-Z)
  bool isTerminal;        // Indicates if this node marks the end of a suffix
  int startIndex; // Stores the starting index of the suffix in the string

  // Constructor for initializing a TrieNode
  TrieNode(char data) {
    this->data = data; // Initialize the node with the given character
    for (int i = 0; i < 26; i++) {
      children[i] = NULL; // Initialize all child pointers to NULL
    }
    isTerminal = false; // Initially, the node is not terminal
    startIndex = -1;    // Default value for the start index
  }
};

// SuffixTree class encapsulates the Trie functionality for building the suffix
// tree
class SuffixTree {
private:
  TrieNode *root; // Root node of the Trie
  string text;    // The string for which the suffix tree is built

  // Helper function to insert a suffix into the Trie
  void insertSuffix(string suffix, int startIndex) {
    TrieNode *current = root; // Start at the root of the Trie

    // Traverse the Trie and insert characters of the suffix
    for (char ch : suffix) {
      int index = ch - 'A'; // Convert character to an index (0-25 for A-Z)

      // If the current character doesn't exist, create a new node
      if (current->children[index] == NULL) {
        current->children[index] = new TrieNode(ch);
      }

      // Move to the child node corresponding to the current character
      current = current->children[index];
    }

    // Mark the last node as terminal and store the starting index of the suffix
    current->isTerminal = true;
    current->startIndex = startIndex;
  }

  // Helper function to recursively print the suffix tree
  void printTree(TrieNode *node, string currentSuffix) {
    if (node == NULL)
      return; // Base case: If node is NULL, return

    // If the node is terminal, print the suffix and its starting index
    if (node->isTerminal) {
      cout << left << setw(20) << ("Suffix: " + currentSuffix) << setw(15)
           << "Start Index:" << node->startIndex << endl;
    }

    // Recursively visit all children of the current node
    for (int i = 0; i < 26; i++) {
      if (node->children[i] != NULL) {
        // Append the character of the child node to the current suffix
        printTree(node->children[i], currentSuffix + node->children[i]->data);
      }
    }
  }

public:
  // Constructor for initializing the suffix tree
  SuffixTree(string text) {
    this->text = text;         // Store the input string
    root = new TrieNode('\0'); // Create the root node with a null character

    // Insert all suffixes of the string into the Trie
    for (int i = 0; i < text.size(); i++) {
      insertSuffix(text.substr(i), i); // Insert suffix starting at index i
    }
  }

  // Function to print the entire suffix tree
  void printSuffixTree() {
    cout << "Suffix Tree for string '" << text << "':\n";
    printTree(root, ""); // Start recursive printing from the root
  }
};

int main() {
  string input;
  cout << "Enter a string: ";
  cin >> input;

  // Build a suffix tree for the input string
  SuffixTree suffixTree(input);

  // Print the suffix tree
  suffixTree.printSuffixTree();

  return 0;
}
