#include <iostream>
using namespace std;

class Heap
{
public:
    int arr[100];
    int size = 0;

    void insert(int value)
    {
        size += 1;
        int index = size;
        arr[index] = value;

        while (index > 1)
        {
            int parent = (index) / 2;
            if (arr[parent] < arr[index])
            {
                swap(arr[parent], arr[index]);
                index = parent;
            }
            else
            {
                return;
            }
        }
    }

    void deleteNode()
    {
        if (size == 0)
        {
            cout << "No node to be deleted\n";
            return;
        }

        arr[0] = arr[size - 1];
        size--;

        int i = 0;
        while (i < size)
        {
            int leftIdx = 2 * i;
            int rightIdx = 2 * i + 1;
            int largest = i;

            if (leftIdx < size && arr[leftIdx] > arr[largest])
            {
                largest = leftIdx;
            }
            if (rightIdx < size && arr[rightIdx] > arr[largest])
            {
                largest = rightIdx;
            }
            if (largest != i)
            {
                swap(arr[i], arr[largest]);
                i = largest;
            }
            else
            {
                return;
            }
        }
    }

    void print()
    {
        for (int i = 1; i <= size; i++)
        {
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};

void heapify(int arr[], int size, int i)
{
    int largest = i;
    int leftidx = i * 2;
    int rightidx = i * 2 + 1;

    if (leftidx < size && arr[leftidx] > arr[largest])
    {
        largest = leftidx;
    }
    if (rightidx < size && arr[rightidx] > arr[largest])
    {
        largest = rightidx;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, size, largest);
    }
}

int main()
{
    Heap h;
    h.insert(5);
    h.insert(24);
    h.insert(21);
    h.insert(84);
    h.insert(4);
    h.insert(12);
    h.insert(22);
    h.print();
    h.deleteNode();
    h.print();

    int arr[] = {-1, 54,53,55,52,50};
    int size = sizeof(arr) / sizeof(arr[0]);
    for (int i = 1; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    for(int i = size/2; i>0; i--){
        heapify(arr,size,i);

    }
    
    for (int i = 1; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    return 0;
}
