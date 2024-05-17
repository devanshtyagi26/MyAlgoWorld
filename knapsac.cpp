#include <iostream>

using namespace std;

// Function to solve the 0-1 knapsack problem
int knapsack(int weights[], int profits[], int n, int capacity, bool selectedItems[]) {
    int mem[n + 1][capacity + 1];

    for (int i = 0; i <= n; ++i) {
        for (int w = 0; w <= capacity; ++w) {
            if (i == 0 || w == 0) {
                mem[i][w] = 0;
            } else if (weights[i - 1] > w) {
                mem[i][w] = mem[i - 1][w];
            } else {
                int take = mem[i - 1][w - weights[i - 1]] + profits[i - 1];
                int not_take = mem[i - 1][w];
                if (take > not_take) {
                    mem[i][w] = take;
                    selectedItems[i * (capacity + 1) + w] = true; // Mark item i as selected for capacity w
                } else {
                    mem[i][w] = not_take;
                }
            }
        }
    }

    return mem[n][capacity];
}

int main() {
    int weights[] = {2, 3, 4, 5, 6};
    int profits[] = {10, 7, 12, 8, 9};
    int capacity = 10;
    int n = sizeof(weights) / sizeof(weights[0]);

    bool selectedItems[(n + 1) * (capacity + 1)] = {false};

    int max_profit = knapsack(weights, profits, n, capacity, selectedItems);
    cout << "Maximum profit that can be obtained: " << max_profit << endl;

    cout << "Items taken: ";
    int w = capacity;
    for (int i = n; i >= 1; --i) {
        if (selectedItems[i * (capacity + 1) + w]) {
            cout << i << " ";
            w -= weights[i - 1];
        }
    }
    cout << endl;

    return 0;
}
