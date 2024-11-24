#include <iostream>
#include <cstdlib> // For rand()
#include <time.h>  // For seeding the random number generator with time

using namespace std;

// Function to swap two elements
void swap(int &a, int &b)
{
    int temp = a;
    a = b;
    b = temp;
}

// Partition function for QuickSort
// Divides the array into two parts: elements less than or equal to the pivot on the left
// and elements greater than the pivot on the right
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;       // Index for the smaller element

    for (int j = low; j < high; j++)
    { // Traverse the array
        if (arr[j] <= pivot)
        {                         // If the current element is less than or equal to the pivot
            i++;                  // Increment the index for smaller element
            swap(arr[i], arr[j]); // Swap the smaller element with the current element
        }
    }
    swap(arr[i + 1], arr[high]); // Place the pivot in its correct position
    return i + 1;                // Return the pivot index
}

// Randomized partition function
// Chooses a random pivot to improve the performance of QuickSort on average
int randomizedPartition(int arr[], int low, int high)
{
    srand(time(NULL));                                 // Seed the random number generator
    int randomIndex = low + rand() % (high - low + 1); // Generate a random index within the range
    swap(arr[randomIndex], arr[high]);                 // Swap the randomly chosen pivot with the last element
    return partition(arr, low, high);                  // Partition the array using the new pivot
}

// Randomized Select function
// Finds the i-th smallest element in an array (1-based index) using a randomized approach
int randomizedSelect(int arr[], int low, int high, int i)
{
    if (low == high)
    {                    // If the array contains only one element
        return arr[low]; // Return that element
    }

    int q = randomizedPartition(arr, low, high); // Partition the array
    int k = q - low + 1;                         // Determine the position of the pivot in the sorted array

    if (i == k)
    {                  // If the pivot is the i-th smallest element
        return arr[q]; // Return the pivot
    }
    else if (i < k)
    {                                                // If the i-th smallest element is on the left of the pivot
        return randomizedSelect(arr, low, q - 1, i); // Recur on the left subarray
    }
    else
    {                                                     // If the i-th smallest element is on the right of the pivot
        return randomizedSelect(arr, q + 1, high, i - k); // Recur on the right subarray
    }
}

int main()
{

    int n, i;
    // Prompt the user to enter the number of elements in the array
    cout << "Enter the number of elements in the array: ";
    cin >> n;

    int arr[n]; // Create an array of size 'n'
    // Input the elements of the array
    cout << "Enter the elements of the array.\n";
    for (int i = 0; i < n; i++)
    {
        cout << "Enter element " << i + 1 << " : ";
        cin >> arr[i];
    }

    // Prompt the user to enter the value of i (1-based index)
    cout << "Enter the value of i (1-based index): ";
    cin >> i;

    // Validate the value of i
    if (i < 1 || i > n)
    {
        cout << "Invalid value of i. Please enter a value between 1 and " << n << "." << endl;
        return 1; // Exit the program with an error code
    }

    // Find the i-th smallest element using the Randomized Select algorithm
    int ithSmallest = randomizedSelect(arr, 0, n - 1, i);
    // Output the result
    cout << "The " << i << "-th smallest element is: " << ithSmallest << endl;

    return 0; // Exit the program
}
