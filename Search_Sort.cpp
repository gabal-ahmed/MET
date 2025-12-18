#include <iostream>

using namespace std;

void BubuleSort(int size, int arr[])
{

    for (int i = 0; i < size; i++)
    {
        for (int j = 0; j < size - 1; j++)
        {
            if (arr[j] > arr[j + 1])
            {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
            }
        }
    }
}

void BinarySearch(int size, int arr[], int target)
{
    int first = 0;
    int last = size - 1;
    while (first <= last)
    {
        int middel = (first + last) / 2;

        if (arr[middel] > target)
        {
            --last;
        }
        else if (target == arr[middel])
        {
            cout << "element in index " << middel << endl;
            return;
        }
        else
        {
            first = middel + 1;
        }
    }
    cout << "Element Not Found" << endl;
}
void SelectionSort(int size, int arr[])
{
    for (int i = 0; i < size; i++)
    {
        int minIndex = i;
        for (int j = i + 1; j < size; j++)
        {
            if (arr[j] < arr[minIndex])
            {
                minIndex = j;
            }
        }
        int temp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = temp;
    }
}

void LinearSearch(int size, int arr[], int target)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == target)
        {
            cout << "element in index " << i << endl;
            return;
        }
    }
    cout << "Element Not Found" << endl;
};
int main()
{
    int size = 7;
    int arr[size] = {10, 8, 9, 5, 3, 4, 1};
    // BubuleSort(size, arr);
    // BinarySearch(size, arr, 9);
    // SelectionSort(size, arr);
    // LinearSearch(size, arr, 9);

    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }

    return 0;
}