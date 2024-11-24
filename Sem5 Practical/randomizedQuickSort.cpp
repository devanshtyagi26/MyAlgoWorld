#include <iostream>
#include <cstdlib> // For rand() function
#include <time.h>  // For seeding the random number generator with time

using namespace std;

// Global variable to track the number of comparisons made during sorting
int comparisonCount = 0;

// Function to swap two elements in the array
void swap(int &a, int &b)
{
    int temp = a; // Store the value of 'a' in a temporary variable
    a = b;        // Assign the value of 'b' to 'a'
    b = temp;     // Assign the temporary value to 'b'
}

// Partition function for the QuickSort algorithm
// This function partitions the array around a pivot element and places
// smaller elements to the left and larger elements to the right
int partition(int arr[], int low, int high)
{
    int pivot = arr[high]; // Choose the last element as the pivot
    int i = low - 1;       // Index for the smaller element

    // Traverse through the array and compare each element with the pivot
    for (int j = low; j < high; j++)
    {
        comparisonCount++; // Increment the comparison counter
        if (arr[j] <= pivot)
        {
            i++;                  // Increment index for smaller element
            swap(arr[i], arr[j]); // Swap the smaller element with the current element
        }
    }
    swap(arr[i + 1], arr[high]); // Place the pivot in the correct position
    return i + 1;                // Return the partition index
}

// Function to randomize the pivot for better performance
int randomizedPartition(int arr[], int low, int high)
{
    srand(time(NULL));                                 // Seed the random number generator
    int randomIndex = low + rand() % (high - low + 1); // Generate a random index
    swap(arr[randomIndex], arr[high]);                 // Swap the random pivot with the last element
    return partition(arr, low, high);                  // Call the standard partition function
}

// Recursive QuickSort function with randomized pivot
void randomizedQuickSort(int arr[], int low, int high)
{
    if (low < high)
    {                                                   // Base case: stop if the array has one or zero elements
        int temp = randomizedPartition(arr, low, high); // Get the partition index
        randomizedQuickSort(arr, low, temp - 1);        // Recursively sort the left subarray
        randomizedQuickSort(arr, temp + 1, high);       // Recursively sort the right subarray
    }
}

int main()
{
    int n;
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

    // Display the original array
    cout << "\nOriginal array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Sort the array using randomized QuickSort
    randomizedQuickSort(arr, 0, n - 1);

    // Display the sorted array
    cout << "\nSorted array: ";
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << " ";
    }

    // Display the number of comparisons made during sorting
    cout << "\nNumber of comparisons: " << comparisonCount << endl;

    return 0; // Exit the program
}