package lab1.moving;

import lab1.utilities.Point;

public class HorseRiding implements Movement {
  @Override
  public Point move(Point newPoint) {
    System.out.println("Riding to " + newPoint.toString());
    return newPoint;
  }

  public static String test() {
    return "horseriding";
  }

  @Override
  public String toString() {
    return "HorseRiding";
  }
}
