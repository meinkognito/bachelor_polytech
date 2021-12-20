package lab2.exceptions;

public class MyDivisionByZeroException extends ArithmeticException {

  private final String detail;

  public MyDivisionByZeroException(String detail) {
    this.detail = detail;
  }

  public MyDivisionByZeroException() {
    this("");
  }

  @Override
  public String toString() {
    return "MyDivisionByZeroException{" + "detail='" + detail + '\'' + '}';
  }
}
