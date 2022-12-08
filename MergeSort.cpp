#include <stdio.h>

void merge(int arr[], int l, int m, int r)
{
    int i, j, k;
    int n1 = m - l + 1;
    int n2 = r - m;

    int L[n1], R[n2];

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];
    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = 0;
    j = 0;
    k = l;
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
    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }
}

void mergeSort(int arr[], int l, int r)
{
    if (l < r)
    {
        int m = l + (r - l) / 2;
        mergeSort(arr, l, m);
        mergeSort(arr, m + 1, r);

        merge(arr, l, m, r);
    }
}

unsigned long long sum(long long n)
{
    return n * (n - 1) / 2;
}

int main()
{
    long long n, Bino = 0;
    unsigned long long count = 0;
    scanf("%lld", &n);
    int x[n + 3], c[n + 3] = {};
    for (int i = 1; i <= n; i++)
        scanf("%d", &x[i]);

    mergeSort(x, 1, n);
    long long cnt = 1;
    for (int i = 2; i <= n; i++)
    {
        if (x[i] == x[i - 1])
            ++cnt;
        else
        {
            c[++Bino] = cnt;
            cnt = 1;
        }
    }
    c[++Bino] = cnt;
    for (int i = 1; i <= Bino; i++)
        count += sum(c[i]);

    printf("%llu", count);
}