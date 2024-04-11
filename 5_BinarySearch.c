#include <stdio.h>
int BinarySearch(int arr[], int len, int target)
{
    int left = 0;
    int right = len - 1;
    while (left <= right)
    {
        int mid = left + (right - left) / 2;
        if (arr[mid] == target)
            return mid;
        else if (arr[mid] > target)
            right = mid - 1;
        else
            left = mid + 1;
    }
    return -1;
}
int main()
{
    int arr[] = {1, 2, 3, 4, 5, 6, 7};
    int len = sizeof(arr) / sizeof(arr[0]);
    int target = 5;
    int targetIndex = BinarySearch(arr, len, target);
    if (targetIndex != -1)
    {
        printf("Target Found At Index : %d\n", targetIndex);
    }
    else
    {
        printf("Target Not Found");
    }
    return 0;
}