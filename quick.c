#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void PrintArray(int *A , int n) //Pointer of 1st element and size
{
    FILE * ptr = NULL;
    ptr = fopen("selection1.csv","a");
    for (int i = 0; i < n; i++)
    {
        fprintf(ptr,"%d\n",A[i]);
    }
    fprintf(ptr,"\n");
    fclose(ptr);
}

void swap(int *x, int *y) {
    int t = *x;
    *x = *y;
    *y = t;
}

int partition(int arr[], int low, int high)
{
    int pivot = arr[high];
    int i = (low - 1);
    for (int j = low; j <= high - 1; j++) {
        if (arr[j] < pivot) {
            i++;
            swap(&arr[i], &arr[j]);
        }
    }
    swap(&arr[i + 1], &arr[high]);
    return (i + 1);
}

void quickSort(int a[], int low, int high)
{
    int partitonindex;

    if (low < high)
    {
        partitonindex = partition(a, low, high);
        quickSort(a, low, partitonindex-1);  // left
        quickSort(a, partitonindex + 1, high); // right
    }
}

double qCort(int a[], int n) {
    FILE *fp = fopen("./quickSort.csv", "w+");
    double totalTime = 0;
    if(!fp) {
        printf("Error opening file\n");
        return -1;
    }
    fprintf(fp, "n, time\n");
    for (int i = 99; i <= n; i+=100)
    {
        clock_t start, end;
        double cpu_time_used;
        start = clock();
        quickSort(a, 0, i);
        end = clock();
        cpu_time_used = ((double) (end - start)) / CLOCKS_PER_SEC;
        totalTime += cpu_time_used;
        fprintf(fp, "%d, %f\n", i+1, cpu_time_used);
        printf("Sorted from 0 to %d in %.2fs\n", i, cpu_time_used);
    }
    fclose(fp);
    fp = fopen("./quickSort1.csv", "w+");
    for(int i = 0; i < n; i++) {
        fprintf(fp, "%d\n", a[i]);
    }
    fclose(fp);
    return totalTime;
}


int main()
{
    int n = 100000;
    int b[n];
    double quickT = qCort(b, n);
    printf("Time taken by  Merge Sort: %f\n", quickT);
    return 0;
}
