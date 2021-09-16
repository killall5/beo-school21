#include <stdio.h>

void maxmin(int, int, int, int*, int*);

int main() {
    int x, y, z;
    int count = scanf("%d %d %d", &x, &y, &z);
    if (count != 3) {
        printf("n/a\n");
        return 1;
    }

    int max, min;
    maxmin(x, y, z, &max, &min);
    printf("%d %d\n", max, min);
    return 0;
}

void maxmin(int probe1, int probe2, int probe3, int *max, int *min) {
    *max = *min = probe1;

    if (probe2 > *max) *max = probe2;
    if (probe3 > *max) *max = probe3;

    if (probe2 < *min) *min = probe2;
    if (probe3 < *min) *min = probe3;
}
