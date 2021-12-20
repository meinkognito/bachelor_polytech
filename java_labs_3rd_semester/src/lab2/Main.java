package lab2;

import lab2.exceptions.*;

import java.io.FileInputStream;
import java.io.FileNotFoundException;
import java.io.FileWriter;
import java.io.IOException;
import java.util.InputMismatchException;
import java.util.Scanner;

public class Main {

  public static void main(String[] args) {
    try {
      int matrixSize = scanner();
      writer(matrixSize);
    } catch (MyFileNotFoundException | MyNumberOverflowException | InputMismatchException | OutOfMemoryError e) {
      e.printStackTrace();
    }
  }

  private static int scanner() throws MyFileNotFoundException, InputMismatchException {
    int matrixSize;
    try (Scanner sc = new Scanner(new FileInputStream("input.txt"))) {
      if (sc.hasNextInt()) {
        matrixSize = sc.nextInt();
      } else {
        throw new InputMismatchException("Size of matrix was not provided!");
      }
      if (matrixSize > 1_000_000) {
        throw new MyNumberOverflowException();
      }
    } catch (FileNotFoundException e) {
      throw new MyFileNotFoundException();
    }

    return matrixSize;
  }

  private static void writer(int matrixSize) {
    try (FileWriter fileWriter = new FileWriter("output.txt")) {
      double[][] matrix = Matrix.builder(matrixSize);

      double[][] r90Matrix = Matrix.rotate90AntiClockwise(matrix);
      fileWriter.write("Rotated by 90°\n");
      Matrix.writer(r90Matrix, fileWriter);

      double[][] r180Matrix = Matrix.rotate90AntiClockwise(r90Matrix);
      fileWriter.write("\nRotated by 180°\n");
      Matrix.writer(r180Matrix, fileWriter);

      double[][] r270Matrix = Matrix.rotate90AntiClockwise(r180Matrix);
      fileWriter.write("\nRotated by 270°\n");
      Matrix.writer(r270Matrix, fileWriter);

      System.out.println("Result is in output.txt");
    } catch (IOException e) {
      e.printStackTrace();
    }
  }
}
