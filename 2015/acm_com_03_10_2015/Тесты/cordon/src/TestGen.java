import java.io.*;
import java.util.*;

public class TestGen {
    final int N = 300;
    final int K = 1_000_000_000;
    final Random random = new Random(0xBEEF);

    int testCount;

    void print(int n, int m, int k) throws IOException {
        PrintWriter out = new PrintWriter(String.format("../tests/%02d", ++testCount));
        out.println(n + " " + m + " " + k);
        System.out.println(testCount);
        out.close();
    }

    void genSamples() throws IOException {
        print(2, 2, 1);
        print(1, 6, 2);
	    print(3, 3, 4);
    }

    void genHandleTests() throws IOException {
    }

    void run() throws IOException {
        new File("../tests").mkdir();
        genSamples();
        genHandleTests();
        print(1, 2, 0);
        print(2, 1, 0);
        print(2, 2, 0);
        print(1, N, N - 2);
        print(N, 1, N / 2);
        print(1, 50, 20);
        print(50, 1, 29);
        print(N, N, 0);
        print(N, N, 1);
        print(N, N, 2);
        print(N, N, 2 * N - 3);
        print(N, N / 2, N + N / 2 - 3);
        print(N, N / 2, N + N / 2 - 4);
        print(N / 2, N, N + N / 2 - 5);
        print(100, 200, 273);
        print(219, 170, 219 + 170 - 3);
        print(119, 250, 119 + 250 - 4);
        print(200, 300, 400);
        print(N, N, 403);
        for (int i = 0; i < 10; ++i) {
            int n = random.nextInt(N) + 1;
            int m = random.nextInt(N) + 1;
            if (n == 1 && m == 1) {
                --i;
                continue;
            }
            int k = random.nextInt(n + m - 2);
            print(n, m, k);
        }

        print(1, N, N);
        print(N / 2, 1, N / 2);
        print(2, N, 2 + N);
        print(2, N, N);
        for (int i = 0; i < 10; ++i) {
            int n = random.nextInt(N) + 1;
            int m = random.nextInt(N) + 1;
            if (n == 1 && m == 1) {
                --i;
                continue;
            }
            int k = random.nextInt(K - (n + m - 2)) + (n + m - 2);
            print(n, m, k);
        }
        print(N, N, K);
    }

    public static void main(String[] args) throws IOException {
        new TestGen().run();
    }
}
