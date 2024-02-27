import java.util.*;

class Solution {
  public void setZeroes(int[][] matrix) {
    int max_iter = 10;
    while (max_iter-- > 0) {
      Random random = new Random();
      int value = random.nextInt(Integer.MAX_VALUE) - Integer.MAX_VALUE;
      if (!find_imposter(matrix, value))
        continue;
      for (int i = 0; i < matrix.length; ++i) {
        for (int j = 0; j < matrix[0].length; ++j) {
          if (matrix[i][j] == 0) {
            dfs(matrix, i, j, value);
          }
        }
      }

      for (int i = 0; i < matrix.length; ++i) {
        for (int j = 0; j < matrix[0].length; ++j) {
          if (matrix[i][j] == value)
            matrix[i][j] = 0;
        }
      }
      return;
    }
  }

  public boolean find_imposter(int[][] matrix, int value) {
    for (int[] ints : matrix) {
      for (int j = 0; j < matrix[0].length; ++j) {
        if (value == ints[j])
          return false;
      }
    }
    return true;
  }

  public void dfs(int[][] matrix, int i, int j, int value) {
    int row = matrix.length;
    int col = matrix[0].length;
    // up movement
    int prev = i;
    i = 0;
    while (i < row) {
      if (matrix[i][j] != 0)
        matrix[i][j] = value;
      i++;
    }
    j = 0;
    while (j < col) {
      if (matrix[prev][j] != 0)
        matrix[prev][j] = value;
      j++;
    }
  }
}
