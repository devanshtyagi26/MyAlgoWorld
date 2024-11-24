#include <iostream>
#include <string>
#include <vector>

using namespace std;

void longestPrefixSuffix(string s, vector<int> &lps) {
  int pre = 0;
  int suf = 1;

  while (suf < s.size()) {
    if (s[pre] == s[suf]) {
      lps[suf] = pre + 1;
      pre++;
      suf++;
    } else {
      if (pre == 0) {
        lps[suf] = 0;
        suf++;
      } else {
        pre = lps[pre - 1];
      }
    }
  }
}

int kmp(string a, string b) {
  vector<int> lps(b.size(), 0);
  int first = 0, second = 0;
  longestPrefixSuffix(b, lps);

  while (second < b.size() && first < a.size()) {
    if (a[first] == b[second]) {
      first++;
      second++;
    } else {
      if (second == 0) {
        first++;
      } else {
        second = lps[second - 1];
      }
    }
  }

  if (second == b.size()) {
    return first - second;
  }
  return -1;
}

int main() {
  string a = "aaaaab";
  string b = "aaab";

  int answer = kmp(a, b);

  if (answer == -1) {
    cout << "The pattern '" << b << "' is not present in string '" << a << "'" << endl;
  } else {
    cout << "Pattern '" << b << "' in string '" << a
         << "' using the KMP algorithm is at index: " << answer;
  }
  return 0;
}