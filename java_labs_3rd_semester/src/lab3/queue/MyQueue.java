package lab3.queue;

import java.util.LinkedList;

public class MyQueue<T> extends LinkedList<T> {

  private final int size;

  public MyQueue(int size) {
    this.size = size;
  }

  @Override
  public boolean add(Object o) {
    boolean isLegit = super.add((T) o);
    if (isLegit && size() > size) {
      super.remove();
    }
    return isLegit;
  }

  public T get() {
    return this.removeLast();
  }

  @Override
  public boolean isEmpty() {
    return super.isEmpty();
  }
}
