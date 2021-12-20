package lab6;

import lab6.Program.State;

public class Supervisor implements Runnable {

  private final Program program = new Program();
  private Thread programThread;

  private void start() {
    programThread = new Thread(program);
    programThread.start();
    System.out.println("[SVR] Program has been started");
  }

  private void restart() throws InterruptedException {
    programThread.interrupt();
    programThread = new Thread(program);
    programThread.start();
    System.out.println("[SVR] Restarting the program...");
  }

  private void interruptProgram() throws InterruptedException {
    programThread.interrupt();
    System.err.println("[SVR] Program has been interrupted due to fatal error!");
  }

  @Override
  public void run() {
    start();
    while (program.getProgramState() != State.FATAL_ERROR) {
      try {
        synchronized (program.mutex) {
          program.mutex.wait();
          switch (program.getProgramState()) {
            case UNKNOWN, STOPPING -> {
              System.out.println(program.daemonMessage());
              restart();
            }
            case RUNNING -> System.out.println(program.daemonMessage());
            case FATAL_ERROR -> {
              System.out.println(program.daemonMessage());
              interruptProgram();
            }
          }
        }
      } catch (InterruptedException ignored) {
      }
    }
  }
}