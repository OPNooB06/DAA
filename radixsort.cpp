#include <iostream>
#include <cmath>
using namespace std;
int max(int arr[], int size)
{
    int max = arr[0];
    for (int i = 0; i < size; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }
    return max;
}
void countsort(int arr[], int size, int divisor)
{
    int maxi = arr[0] % divisor;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] % divisor > maxi)
        {
            maxi = arr[i] % divisor;
        }
    }
    int count_arr[maxi + 1] = {0};
    for (int i = 0; i < size; i++)
    {
        count_arr[arr[i] % divisor]++;
    }
    for (int i = 1; i < maxi + 1; i++)
    {
        count_arr[i] = count_arr[i] + count_arr[i - 1];
    }
    int sorted_arr[size];
    for (int i = size - 1; i >= 0; i--)
    {
        int index = count_arr[arr[i] % divisor] - 1;
        sorted_arr[index] = arr[i];
        count_arr[arr[i] % divisor]--;
    }
    int getmax = max(arr, size);
    for (int i = 0; i < size; i++)
    {
        arr[i] = sorted_arr[i];
    }
}
void radixsort(int arr[], int size)
{
    int maxi = max(arr, size);
    int digit = 1;
    while (maxi > 10)
    {
        maxi = maxi / 10;
        digit++;
    }
    for (int i = 1; i <= digit; i++)
    {
        int divisor = pow(10, i);
        countsort(arr, size, divisor);
    }
}
int main()
{
    int n;
    cout << "Enter size of array: ";
    cin >> n;
    int arr[n];
    for (int i = 0; i < n; i++)
    {
        int element;
        cout << "Enter elements: ";
        cin >> element;
        arr[i] = element;
    }
    radixsort(arr, n);
    cout << "Sorted array is: " << endl;
    for (int i = 0; i < n; i++)
    {
        cout << arr[i] << endl;
    }
    return 0;
}