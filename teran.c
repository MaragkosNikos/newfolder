#include <stdio.h>
#include <stdlib.h>
typedef void *Pointer;
typedef int (*CompareFunc)(int a[], int size);
int max(int array[], int size, CompareFunc comp)
{
    int x = comp(array, size);
    return x;
}
int cmax(int array[], int size)
{
    int max = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] > max)
        {
            max = array[i];
        }
    }
    return max;
}
int cmin(int array[], int size)
{
    int min = array[0];
    for (int i = 1; i < size; i++)
    {
        if (array[i] < min)
        {
            min = array[i];
        }
    }
    return min;
}
int main(int argc, char **argv)
{
    int array[argc - 1];
    for (int i = 1; i < argc; i++)
    {
        array[i - 1] = atoi(argv[i]);
    }
    int max_a = max(array, argc - 1, cmax);
    printf("%d\n", max_a);
    int min_a = max(array, argc - 1, cmin);
    printf("%d\n", min_a);
}