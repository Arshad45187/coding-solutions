#include <stdlib.h>

int** matrixReshape(int** mat, int matSize, int* matColSize, int r, int c, int* returnSize, int** returnColumnSizes) {
    int origRows = matSize;
    int origCols = matColSize[0];

    if (origRows * origCols != r * c) {
        *returnSize = origRows;
        *returnColumnSizes = (int*)malloc(origRows * sizeof(int));
        for (int i = 0; i < origRows; i++) {
            (*returnColumnSizes)[i] = origCols;
        }
        return mat;
    }

    *returnSize = r;
    *returnColumnSizes = (int*)malloc(r * sizeof(int));
    int** result = (int**)malloc(r * sizeof(int*));

    for (int i = 0; i < r; i++) {
        (*returnColumnSizes)[i] = c;
        result[i] = (int*)malloc(c * sizeof(int));
    }

    for (int i = 0; i < r * c; i++) {
        result[i / c][i % c] = mat[i / origCols][i % origCols];
    }

    return result;
}
