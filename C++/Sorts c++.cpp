#include<iostream>
#include<random>
#include<cmath>
#include<math.h>
#include<queue>
#include<ctime>

using namespace std;

void swap(int* a, int* b){
    int t = *a;
    *a = *b;
    *b = t;
}

void GenerateArray(int array[]){

    srand( (unsigned)time( NULL ) );

    for (int i = 0; i < 10; ++i) {

        array[i] = rand() % 100;

    }

}

void BubbleSort(int arr[], int n) {

    int i, j;
    for (i = 0; i < n-1; i++)

    for (j = 0; j < n-i-1; j++)
        if (arr[j] > arr[j+1])
            swap(&arr[j], &arr[j+1]);

}

void ShakerSort(int a[], int n){

    bool swapped = true;
    int start = 0;
    int end = n - 1;

    while (swapped) {
        swapped = false;

        for (int i = start; i < end; i++) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        if (!swapped)
            break;

        swapped = false;

        end--;

        for (int i = end - 1; i >= start; i--) {
            if (a[i] > a[i + 1]) {
                swap(a[i], a[i + 1]);
                swapped = true;
            }
        }

        start++;
    }

}

void SelectionSort(int arr[], int n) {
    int i, j, min_idx;

    for (i = 0; i < n-1; i++)  {
        min_idx = i;
        for (j = i+1; j < n; j++)
        if (arr[j] < arr[min_idx])
            min_idx = j;

        swap(&arr[min_idx], &arr[i]);
    }
}

void Merge(int arr[], int l, int m, int r){
    int i, j, k;
    int n1 = m - l + 1;
    int n2 =  r - m;

    /* create temp arrays */
    int L[n1], R[n2];

    /* Copy data to temp arrays L[] and R[] */
    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1+ j];

    /* Merge the temp arrays back into arr[l..r]*/
    i = 0; // Initial index of first subarray
    j = 0; // Initial index of second subarray
    k = l; // Initial index of merged subarray
    while (i < n1 && j < n2)
    {
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    /* Copy the remaining elements of L[], if there
       are any */
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }

    /* Copy the remaining elements of R[], if there
       are any */
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int l, int r){
    if (l < r)
    {
        // Same as (l+r)/2, but avoids overflow for
        // large l and h
        int m = l+(r-l)/2;

        // Sort first and second halves
        MergeSort(arr, l, m);
        MergeSort(arr, m+1, r);

        Merge(arr, l, m, r);
    }
}

void Heapify(int arr[], int n, int i){
    int largest = i; // Initialize largest as root
    int l = 2*i + 1; // left = 2*i + 1
    int r = 2*i + 2; // right = 2*i + 2

    // If left child is larger than root
    if (l < n && arr[l] > arr[largest])
        largest = l;

    // If right child is larger than largest so far
    if (r < n && arr[r] > arr[largest])
        largest = r;

    // If largest is not root
    if (largest != i)
    {
        swap(arr[i], arr[largest]);

        // Recursively heapify the affected sub-tree
        Heapify(arr, n, largest);
    }
}

void HeapSort(int arr[], int n){
    // Build heap (rearrange array)
    for (int i = n / 2 - 1; i >= 0; i--)
        Heapify(arr, n, i);

    // One by one extract an element from heap
    for (int i=n-1; i>=0; i--)
    {
        // Move current root to end
        swap(arr[0], arr[i]);

        // call max heapify on the reduced heap
        Heapify(arr, i, 0);
    }
}

void InsertionSort(int arr[], int n){
    int i, key, j;
    for (i = 1; i < n; i++)
    {
        key = arr[i];
        j = i - 1;

        while (j >= 0 && arr[j] > key)
        {
            arr[j + 1] = arr[j];
            j = j - 1;
        }
        arr[j + 1] = key;
    }
}

int Partition (int arr[], int low, int high)  {
    int pivot = arr[high]; // pivot
    int i = (low - 1); // Index of smaller element

    for (int j = low; j <= high - 1; j++)
    {
        // If current element is smaller than the pivot
        if (arr[j] < pivot)
        {
            i++; // increment index of smaller element
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void QuickSort(int arr[], int low, int high){
    if (low < high)
    {
        /* pi is partitioning index, arr[p] is now
        at right place */
        int pi = Partition(arr, low, high);

        // Separately sort elements before
        // partition and after partition
        QuickSort(arr, low, pi - 1);
        QuickSort(arr, pi + 1, high);
    }
}

void RadixSort_LSD(int arr[], int n){

    queue<int> queue[10];
    int power = 1;
    int number_of_digits = 0;

    for(int i = 0; i < n; i++){

        number_of_digits = (number_of_digits < (int)log10(arr[i]) + 1) ? number_of_digits = (int)log10(arr[i]) + 1 : number_of_digits = number_of_digits;

    }

    for(int i = 0; i < number_of_digits; i++){

        for(int j = 0; j < n; j++){

            queue[arr[j] / power % 10].push(arr[j]);

        }

        int index = 0;

        for(int j = 0; j < 10; j++){

            while(!queue[j].empty()){

                arr[index] = queue[j].front();
                queue[j].pop();
                index++;

            }

        }

        power *= 10;

    }

}

int main(){

    int array[10];
    GenerateArray(array);
    for(int i = 0; i < 10; i++){

        cout << array[i] << ' ';

    }

    cout << '\n';

    //MergeSort(array,array[0],array[10]);
    //ShakerSort(array, 10);
    //BubbleSort(array, 10);
    //SelectionSort(array, 10);
    //HeapSort(array, 10);
    //InsertionSort(array,10);
    //QuickSort(array,0,9);
    //RadixSort_LSD(array, 10);

    for(int i = 0; i < 10; i++){

        cout << array[i] << ' ';

    }

    cout << '\n';


}
