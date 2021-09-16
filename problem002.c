#include <stdio.h>
#include <stdlib.h>
#include <string.h>

void input(int **matrix, int *n, int *m);
void output(int *matrix, int n, int m);

void sort_horizontal(int *matrix, int n, int m, int **result_matrix);
void sort_vertical(int *matrix, int n, int m, int **result_matrix);
void sort_spiral(int *matrix, int n, int m, int **result_matrix);


int main() {
    int n, m, *matrix, *result;

    input(&matrix, &n, &m);

    sort_vertical(matrix, n, m, &result);
    output(result, n, m);
    printf("\n\n");
    free(result);

    sort_horizontal(matrix, n, m, &result);
    output(result, n, m);
    printf("\n\n");
    free(result);
    
    sort_spiral(matrix, n, m, &result);
    output(result, n, m);
    free(result);

    free(matrix);
}

void sort(int *array, int size) {
    int swap;
    for (int i = 0; i < size-1; ) {
        if (array[i] < array[i+1]) {
            i++;
            continue;
        }
        swap = array[i];
        array[i] = array[i+1];
        array[i+1] = swap;
        if (i > 0) i--;
    }
}

void input(int **matrix, int *n, int *m) {
    scanf("%d %d", n, m);
    int *res = malloc((*n)*(*m)*sizeof(int));

    int x;
    for (int i = 0; i < (*n)*(*m); i++) {
        scanf("%d", &res[i]);
    }

    sort(res, (*n)*(*m));
    *matrix = res;
}

void output(int *matrix, int n, int m) {
    for (int i = 0; i < n; i++) {
        if (i > 0) printf("\n");
        for (int j = 0; j < m; j++) {
            if (j > 0) printf(" ");
            printf("%d", matrix[i*m + j]);
        }
    }
}

void sort_horizontal(int *matrix, int n, int m, int **result_matrix) {
    int *res = malloc(n*m*sizeof(int));

    int row = 0, col = 0, dir = 1;
    int prev_col;
    for (int i = 0; i < n*m; i++) {
        prev_col = col;
        res[row*m + col] = matrix[i];
        col += dir;
        
        if (col < 0 || col > m-1) {
            col = prev_col;
            dir = -dir;
            row++;
        }
    }

    *result_matrix = res;
}

void sort_vertical(int *matrix, int n, int m, int **result_matrix) {
    int *res = malloc(n*m*sizeof(int));

    int row = 0, col = 0, dir = 1;
    int prev_row;
    for (int i = 0; i < n*m; i++) {
        prev_row = row;
        res[row*m + col] = matrix[i];
        row += dir;

        if (row < 0 || row > n-1) {
            row = prev_row;
            dir = -dir;
            col++;
        }
    }

    *result_matrix = res;
}

void sort_spiral(int *matrix, int n, int m, int **result_matrix) {
    int *res = malloc(n*m*sizeof(int));
    memset(res, 0, n*m*sizeof(int));

    int row = (n-1)/2, col = (m-1)/2;
    int i = 0;
    int step = 0;
    res[row*m + col] = matrix[i++];
    while (i < n*m) {
        step++;
        // right
        for (int s = 0; s < step; s++) {
            col++;
            if (0 <= col && col < m && 0 <= row && row < n) res[row*m + col] = matrix[i++];
        }

        // down
        for (int s = 0; s < step; s++) {
            row++;
            if (0 <= col && col < m && 0 <= row && row < n) res[row*m + col] = matrix[i++];
        }

        step++;
        // left
        for (int s = 0; s < step; s++) {
            col--;
            if (0 <= col && col < m && 0 <= row && row < n) res[row*m + col] = matrix[i++];
        }

        // up
        for (int s = 0; s < step; s++) {
            row--;
            if (0 <= col && col < m && 0 <= row && row < n) res[row*m + col] = matrix[i++];
        }

    }

    *result_matrix = res;
}
