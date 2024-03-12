#include <iostream>
#include <array>
using namespace std;

class A
{
public:
    int ar[10] = {3, 6, 1, 56, 34, 2, 600, 43, 5, 6};
    void quickSort(int low, int high)
    {
        if (low > high)
        {
            return;
        }

        int s = low;
        int e = high;
        int m = s + (e - s) / 2;
        int pivot = ar[m];

        while (s <= e)
        {
            while (ar[s] < pivot)
            {
                s++;
            }

            while (ar[e] > pivot)
            {
                e--;
            }

            if (s <= e)
            {
                int temp = ar[s];
                ar[s] = ar[e];
                ar[e] = temp;
                s++;
                e--;
            }
        }
        quickSort(low, e);
        quickSort(s, high);
    }

    void display(){
        for (int i = 0; i < sizeof(ar) / sizeof(ar[0]); i++)
        {
            cout << ar[i] << endl;
        }
    }
};

int main()
{
    A a;
    a.quickSort(0, 10);
    a.display();
    return 0;
}