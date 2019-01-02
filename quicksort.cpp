#include <iostream>

void quicksort(int arr[], int left, int right)
{
    if (left >= right)
        return;

    int l = left, r = right;
    int guard = arr[l];
    int guardPostion = l;

    int p = guard;
    int pP = guardPostion;

    while (l < r)
    {
        if (arr[r] >= guard)
        {
            --r;
            continue;
        }

        if (arr[l] >= p)
        {
            p = arr[l];
            pP = l;
        }
        
        ++l;
    }

    int temp = arr[pP];
    arr[pP] = arr[r];
    arr[r] = temp;

    quicksort(arr, left, r);
    quicksort(arr, r+1, right);

    return;
}

int main()
{
    // int arr[10] = {10,9,8,7,6,6,4,3,2,1};
    int arr[10] = {5,1,2,3,4,10,6,7,8,9};
    quicksort(arr, 0, 9);

    for (int i = 0; i < 10; ++i)
    {
        std::cout << arr[i] << " ";
    }

    return 0;
}