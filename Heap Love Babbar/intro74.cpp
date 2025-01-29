#include <bits/stdc++.h>
using namespace std;

class heap
{
public:
    int arr[100];
    int size;

    heap()
    {
        arr[0] = -1;
        size = 0;
    }

    void insert(int val)
    {
        size = size + 1;
        int ind = size;
        arr[ind] = val;

        while (ind > 1)
        {
            int par = ind / 2;

            if (arr[par] < arr[ind])
            {
                swap(arr[par], arr[ind]);
            }
            else
            {
                return;
            }
        }
    }

    void deletefromHeap()
    {
        if (size == 0)
        {
            cout << "nothing to delete" << endl;
            return;
        }

        arr[1] = arr[size];
        size--;

        // take root node to its correct pos
        int i = 1;
        while (i < size)
        {
            int left = 2 * i;
            int right = 2 * i + 1;

            if (left < size && arr[i] < arr[left])
            {
                swap(arr[i], arr[left]);
                i = left;
            }

            else if (right < size && arr[i] < arr[right])
            {
                swap(arr[i], arr[right]);
                i = right;
            }
            else
                return;
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

void heapify(int arr[], int n, int i)
{

    int largest = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    // since 1 based ind to <= n
    if (left <= n && arr[largest] < arr[left])
    {
        largest = left;
    }

    if (right <= n && arr[largest] < arr[right])
    {
        largest = right;
    }

    if (largest != i)
    {
        swap(arr[largest], arr[i]);
        heapify(arr, n, largest);
    }
}

void heapsort(int arr[], int n) {
    int size = n;

    while(size > 1) {
        swap(arr[size], arr[1]);
        size--;

        heapify(arr, size, 1);
    }
}

int main()
{
    heap h;
    h.insert(50);
    h.insert(55);
    h.insert(48);
    h.print();
    h.deletefromHeap();
    h.print();

    int arr[6] = {-1, 2, 34, 54, 64, 99};
    int n = 5;
    for (int i = n / 2; i > 0; i--)
    {
        heapify(arr, n, i);
    }

    for (int i = 1; i < n; i++)
    {
        cout << arr[i] << "  ";
    }
    cout << endl;

    //maxheap;
    priority_queue<int> maxheap;

    //minheap;
    priority_queue<int, vector<int>, greater<int> > minheap;

    return 0;
}