/* The following function is a Shell sort for sorting an array of integers. The */
/* basic idea of this sorting algorithm, which was invented in 1959 by D. L. Shell, is that in early */
/* stages, far-apart elements are compared, rather than adjacent ones as in simpler interchange */
/* sorts. This tends to eliminate large amounts of disorder quickly, so later stages have less work */
/* to do. The interval between compared elements is gradually decreased to one, at which point */
/* the sort effectively becomes an adjacent interchange method. */

#include <stdio.h>

/* shellsort: sort v[0]...v[n-1] into increasing order */
void shellsort(int v[], int n)
{
    int gap, i, j, temp;
    for (gap = n/2; gap > 0; gap /= 2)
        for (i = gap; i < n; i++)
            for (j=i-gap; j>=0 && v[j]>v[j+gap]; j-=gap) {
                temp = v[j];
                v[j] = v[j+gap];
                v[j+gap] = temp;
            }
}

int main(void)
{
    int i;
    int list[] = {1, 2, 4, 5, 2, 1};

    for (i = 0; i < 7; i++)
        printf("%d, ", list[i]);
    printf("\n");

    shellsort(list, 7);

    for (i = 0; i < 7; i++)
        printf("%d, ", list[i]);
    printf("\n");

    return 0;
}
