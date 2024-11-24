#include <iostream>
#include <vector>
using namespace std;

class disjointSets {
  vector<int> rank, parent;

public:
  disjointSets(int n) {
    rank.resize(n + 1, 0);
    parent.resize(n + 1);
    for (int i = 0; i <= n; i++) {
      parent[i] = i;
    }
  }
  int findParent(int node) {
    if (node == parent[node]) {
      return node;
    }
    return parent[node] = findParent(parent[node]);
  }
  void unionByRank(int u, int v) {
    int ult_Par_u = findParent(u);
    int ult_Par_v = findParent(v);
    if (ult_Par_u == ult_Par_v) {
      return;
    }
    if (rank[ult_Par_u] < rank[ult_Par_v]) {
      parent[ult_Par_u] = ult_Par_v;
    } else if (rank[ult_Par_v] < rank[ult_Par_u]) {
      parent[ult_Par_v] = ult_Par_u;
    } else {
      parent[ult_Par_v] = ult_Par_u;
      rank[ult_Par_u]++;
    }
  }
};

int main() {
  disjointSets ds(7);
  ds.unionByRank(1, 2);
  ds.unionByRank(2, 3);
  ds.unionByRank(4, 5);
  ds.unionByRank(6, 7);
  ds.unionByRank(5, 6);

  if (ds.findParent(3) == ds.findParent(7)) {
    cout << "Same\n";
  } else {
    cout << "Different\n";
  }

  ds.unionByRank(3, 7);

  if (ds.findParent(3) == ds.findParent(7)) {
    cout << "Same\n";
  } else {
    cout << "Different\n";
  }
  
  return 0;
}