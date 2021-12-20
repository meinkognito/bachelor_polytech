package lab2.exceptions;

import java.io.FileNotFoundException;

public class MyFileNotFoundException extends FileNotFoundException {

  private final String detail;

  public MyFileNotFoundException(String detail) {
    this.detail = detail;
  }

  public MyFileNotFoundException() {
    this("File was not found!");
  }

  @Override
  public String toString() {
    return "MyFileNotFoundException: " + detail;
  }
}
