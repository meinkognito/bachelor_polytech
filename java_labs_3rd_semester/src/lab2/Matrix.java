package lab2;

import lab2.exceptions.MyDivisionByZeroException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.Random;

public class Matrix {

  public static double[][] builder(int matrixSize) {
    double[][] res = new double[matrixSize][matrixSize];
    Random r = new Random();

    for (int i = 0; i < matrixSize; i++) {
      for (int j = 0; j < matrixSize; j++) {
        if (r.ints(-matrixSize, matrixSize + 1).findFirst().isPresent()) {
          res[i][j] = r.ints(-matrixSize, matrixSize + 1).findFirst().getAsInt();
        }
      }
    }
    return res;
  }

  public static double[][] rotate90AntiClockwise(double[][] matrix) {
    int side = matrix.length;
    double[][] res = new double[side][side];

    for (int i = 0; i < side; i++) {
      for (int j = i; j < side; j++) {
        double temp = matrix[j][i];
        res[j][i] = matrix[i][j];
        res[i][j] = temp;
      }
    }

    for (int i = 0; i < side; i++) {
      for (int j = 0, k = side - 1; j < k; j++, k--) {
        double temp = res[j][i];
        res[j][i] = res[k][i];
        res[k][i] = temp;
      }
    }

    res = sumAndDivide(res);

    return res;
  }

  public static double[][] sumAndDivide(double[][] matrix) {
    int side = matrix.length;
    double[][] res = new double[side][side];

    for (int i = 0; i < side; i++) {
      for (int j = 0; j < side; j++) {
        double sum;
        if (j == 0) {
          sum = matrix[i][j + 1];
        } else if (j == side - 1) {
          sum = matrix[i][j - 1];
        } else {
          sum = matrix[i][j - 1] + matrix[i][j + 1];
        }
        try {
          if (sum == 0) {
            throw new MyDivisionByZeroException();
          } else {
            res[i][j] = matrix[i][j] / sum;
          }
        } catch (MyDivisionByZeroException e) {
          res[i][j] = 0;
        }
      }
    }
    return res;
  }

  public static void writer(double[][] matrix, FileWriter fileWriter) throws IOException {
    for (double[] doubles : matrix) {
      for (double x : doubles) {
        if (x < 0) {
          fileWriter.write(String.format("%.2f ", x));
        } else {
          fileWriter.write(String.format(" %.2f ", x));
        }
      }
      fileWriter.write('\n');
    }
  }
}
