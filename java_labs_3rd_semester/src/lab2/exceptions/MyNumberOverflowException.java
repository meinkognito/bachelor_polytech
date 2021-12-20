package lab2.exceptions;

public class MyNumberOverflowException extends RuntimeException {

  private final String detail;

  public MyNumberOverflowException(String detail) {
    this.detail = detail;
  }

  public MyNumberOverflowException() {
    this("");
  }

  @Override
  public String toString() {
    return "MyNumberOverflowException: Your number is out of limit!";
  }
}
