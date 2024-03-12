#include <iostream>

using namespace std;

class maxheap
{
public:
    int *min_harr;
    int min_heap_size;

    void heapify_min(int curr, int min_heap_size)
    {
        int i;
        int l = (2 * curr + 1);
        int r = (2 * curr + 2);
        int smallest = curr;

        if (l < min_heap_size && min_harr[l] < min_harr[smallest])
        {
            smallest = l;
        }
        if (r < min_heap_size && min_harr[r] < min_harr[smallest])
        {
            smallest = r;
        }
        if (smallest != curr)
        {
            swap(min_harr[curr], min_harr[smallest]);
            heapify_min(smallest, min_heap_size);
        }
        for (i = 0; i < min_heap_size; i++)
        {
            cout << min_harr[i] << " ";
        }
        cout << "\n";
    }

    void min_heapsort()
    {
        for (int i = min_heap_size / 2 - 1; i >= 0; i--)
        {
            heapify_min(i, min_heap_size);
        }
        for (int i = min_heap_size - 1; i > 0; i--)
        {
            swap(min_harr[0], min_harr[i]);
            heapify_min(0, i);
        }
        for (int i = 0; i < min_heap_size / 2; i++)
        {
            swap(min_harr[i], min_harr[min_heap_size - i - 1]);
        }
    }

    void create_min()
    {
        int i;
        min_harr = new int[min_heap_size];
        for (i = 0; i < min_heap_size; i++)
        {
            cout << "Enter the element: ";
            cin >> min_harr[i];
        }
    }
};

int main()
{
    int s, choice, i;
    maxheap obj;

    cout << "Enter the size of the Min Heap: ";
    cin >> obj.min_heap_size;
    obj.create_min();
    obj.min_heapsort();
    for (i = 0; i < obj.min_heap_size; i++)
    {
        cout << obj.min_harr[i] << " ";
    }
}
