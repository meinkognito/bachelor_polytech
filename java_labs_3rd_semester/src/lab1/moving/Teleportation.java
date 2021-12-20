package lab1.moving;

import lab1.utilities.Point;

public class Teleportation implements Movement {
  @Override
  public Point move(Point newPoint) {
    System.out.println("Teleporting to " + newPoint.toString());
    return newPoint;
  }

  @Override
  public String toString() {
    return "Teleportation";
  }
}
