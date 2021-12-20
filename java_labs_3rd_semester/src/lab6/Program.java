package lab6;

import java.util.Random;

public class Program implements Runnable {

  public enum State {
    UNKNOWN,
    STOPPING,
    RUNNING,
    FATAL_ERROR
  }

  private State programState;
  private final Thread daemonThread;
  public final Object mutex;

  public State getProgramState() {
    return programState;
  }

  public void setRandomState() throws InterruptedException {
    Random random = new Random();
    programState = State.values()[random.nextInt(State.values().length)];
    Thread.sleep(1000);
    mutex.notify();
  }

  Program() {
    mutex = new Object();
    daemonThread = new Thread(() -> {
      while (true) {
        try {
          Thread.sleep(3000);
          System.out.println("[PRM] Doing abstract things...\n");
          synchronized (mutex) {
            setRandomState();
          }
        } catch (InterruptedException ignored) {
        }
      }
    });
    daemonThread.setDaemon(true);
  }

  public String daemonMessage() {
    return "[DAE] Current state has changed to " + programState;
  }

  @Override
  public void run() {
    if (!daemonThread.isAlive()) {
      daemonThread.start();
    }
  }
}