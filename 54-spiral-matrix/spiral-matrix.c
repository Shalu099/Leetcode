int* spiralOrder(int** matrix, int matrixSize, int* matrixColSize, int* returnSize) {
    if (matrixSize == 0 || *matrixColSize == 0) {
        *returnSize = 0;
        return NULL;
    }

    int rows = matrixSize;
    int cols = matrixColSize[0];
    int* result = (int*)malloc(rows * cols * sizeof(int));
    *returnSize = 0;

    int top = 0, bottom = rows - 1, left = 0, right = cols - 1;

    while (top <= bottom && left <= right) {
        
        for (int i = left; i <= right; i++)
            result[(*returnSize)++] = matrix[top][i];
        top++;

        
        for (int i = top; i <= bottom; i++)
            result[(*returnSize)++] = matrix[i][right];
        right--;

        
        if (top <= bottom) {
            for (int i = right; i >= left; i--)
                result[(*returnSize)++] = matrix[bottom][i];
            bottom--;
        }

        
        if (left <= right) {
            for (int i = bottom; i >= top; i--)
                result[(*returnSize)++] = matrix[i][left];
            left++;
        }
    }

    return result;
}
