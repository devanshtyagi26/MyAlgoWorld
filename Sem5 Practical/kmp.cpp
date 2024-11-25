#include <iostream>
#include <string>
#include <vector>

using namespace std;

// Function to compute the Longest Prefix Suffix (LPS) array for the pattern
// LPS array is used to store the length of the longest prefix which is also a
// suffix
void longestPrefixSuffix(string s, vector<int> &lps) {
  int pre = 0; // Pointer for the prefix
  int suf = 1; // Pointer for the suffix

  // Loop to calculate the LPS array values for the pattern string
  while (suf < s.size()) {
    if (s[pre] == s[suf]) { // If prefix and suffix match
      lps[suf] = pre + 1;   // Increment the length of the prefix
      pre++;
      suf++;
    } else {
      if (pre == 0) { // If no prefix match, set LPS for this position to 0
        lps[suf] = 0;
        suf++;
      } else {
        pre = lps[pre - 1]; // Use the previous LPS value to backtrack
      }
    }
  }
}

// Function to implement the Knuth-Morris-Pratt (KMP) pattern matching algorithm
// Returns the starting index of the first occurrence of the pattern in the text
// or -1 if the pattern is not found
int kmp(string a, string b) {
  vector<int> lps(b.size(), 0); // LPS array for the pattern string
  int first = 0;                // Pointer for the text
  int second = 0;               // Pointer for the pattern

  // Compute the LPS array for the pattern
  longestPrefixSuffix(b, lps);

  // Loop to search for the pattern in the text
  while (second < b.size() && first < a.size()) {
    if (a[first] == b[second]) { // If characters match
      first++;                   // Move both pointers forward
      second++;
    } else {
      if (second == 0) { // If pattern pointer is at the start
        first++;         // Move only the text pointer forward
      } else {
        second = lps[second -
                     1]; // Use the LPS value to backtrack the pattern pointer
      }
    }
  }

  // If the pattern pointer reaches the end, the pattern is found in the text
  if (second == b.size()) {
    return first -
           second; // Return the starting index of the pattern in the text
  }
  return -1; // Pattern not found
}

int main() {
  // Input strings
  string a = "aaaaab"; // Text string
  string b = "aaab";   // Pattern string

  // Find the first occurrence of the pattern in the text using KMP
  int answer = kmp(a, b);

  // Output the result
  if (answer == -1) {
    // If pattern is not found
    cout << "The pattern '" << b << "' is not present in string '" << a << "'"
         << endl;
  } else {
    // If pattern is found, print its starting index
    cout << "Pattern '" << b << "' in string '" << a
         << "' using the KMP algorithm is at index: " << answer;
  }
  return 0;
}
