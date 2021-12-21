package lab1.utilities;

public record Point(double x, double y) {

  @Override
  public String toString() {
    return "(" + x + ", " + y + ")";
  }
}
