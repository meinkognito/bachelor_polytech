package lab7;

import java.util.concurrent.BlockingQueue;
import java.util.concurrent.ExecutorService;
import java.util.concurrent.Executors;
import java.util.concurrent.LinkedBlockingQueue;

public class Main {

  private static BlockingQueue<String> queue;

  public static void main(String[] args) {
    int threadsNumber;
    try {
      threadsNumber = Integer.parseInt(args[0]);
    } catch (NumberFormatException | IndexOutOfBoundsException e) {
      System.err.println("Incorrect number of threads!");
      return;
    }

    ExecutorService senders = Executors.newFixedThreadPool(threadsNumber,
        r -> new Thread(r, "Sender"));

    ExecutorService recipients = Executors.newFixedThreadPool(threadsNumber,
        r -> new Thread(r, "Recipient"));

    queue = new LinkedBlockingQueue<>();

    for (int i = 0; i < threadsNumber; i++) {
      senders.execute(new Sender(i));
      recipients.execute(new Recipient(i));
    }

    senders.shutdown();
    recipients.shutdown();

  }

  private static class Sender implements Runnable {

    private final int senders;

    public Sender(int senders) {

      this.senders = senders;
    }

    @Override
    public void run() {
      String message = "Message from " + Thread.currentThread().getName() + " №" + senders;
      System.out.println("Sent: " + message);
      queue.add(message);
    }
  }

  private static class Recipient implements Runnable {

    private final int recipients;

    public Recipient(int recipients) {
      this.recipients = recipients;
    }

    @Override
    public void run() {
      try {
        System.out.println("Received: \"" + queue.take() + "\" by the Recipient " + recipients);
      } catch (InterruptedException e) {
        e.printStackTrace();
      }
    }
  }
}
