package mod8;
import java.util.concurrent.atomic.AtomicBoolean;

public class module8 {

    public static void main(String[] args) throws InterruptedException {
        AtomicBoolean doneFlag = new AtomicBoolean(false);

        // Create the threads
        Thread t1 = new Thread(() -> countUp(doneFlag));
        Thread t2 = new Thread(() -> countDown(doneFlag));

        // Start the threads
        t1.start();
        t2.start();

        // Join the threads with the main thread
        t1.join();
        t2.join();
    }

    // Function for the first thread to count up to 20
    private static void countUp(AtomicBoolean doneFlag) {
        for (int i = 0; i <= 20; ++i) {
            System.out.println("Count up: " + i);
            try {
                Thread.sleep(100); // Simulate work
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
        doneFlag.set(true);
    }

    // Function for the second thread to count down to 0
    private static void countDown(AtomicBoolean doneFlag) {
        while (!doneFlag.get()) {
            Thread.yield(); // Wait until the first thread is done
        }

        for (int i = 20; i >= 0; --i) {
            System.out.println("Count down: " + i);
            try {
                Thread.sleep(100); // Simulate work
            } catch (InterruptedException e) {
                Thread.currentThread().interrupt();
            }
        }
    }
}
