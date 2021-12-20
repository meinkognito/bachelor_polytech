package lab3;

import lab3.birds.*;
import lab3.queue.MyQueue;

public class Main {

  public static void main(String[] args) {
    System.out.println(consume(produce()));
  }

  public static MyQueue<? extends Paleognaths> produce() {
    MyQueue<Birds> queue = fillQueue();
    MyQueue<? extends Paleognaths> res = new MyQueue<>(6);
    while (!queue.isEmpty()) {
      Birds bird = queue.get();
      if (bird instanceof Paleognaths) {
        res.add(bird);
      }
    }
    return res;
  }

  public static MyQueue<? super Emu> consume(MyQueue<? extends Birds> queue) {
    MyQueue<? super Casuariiformes> res = new MyQueue<>(6);
    while (!queue.isEmpty()) {
      Birds bird = queue.get();
      if (!(bird instanceof Casuariiformes)) {
        res.add(bird);
      }
    }
    return res;
  }

  private static MyQueue<Birds> fillQueue() {
    MyQueue<Birds> temp = new MyQueue<>(6);
    temp.add(new Birds());
    temp.add(new Paleognaths());
    temp.add(new Notopaleognaths());
    temp.add(new Novaeratitae());
    temp.add(new Casuariiformes());
    temp.add(new Emu());
    return temp;
  }
}
