import java.io.*;
import java.util.*;
import java.util.ArrayList;
import java.util.function.Supplier;
import java.math.*;

public class TestGen {
    int testCount;
    PrintWriter testsDesc;
    static Random random = new Random(787788);
    static final int MAX_N = 200_000;

    String[] samples = {
            "abbabaab",
            "abbababa"
    };

    String[] hand = {
            "y",
            "rr",
            "az",
            "qqqqq",
            "abcde",
            "oooooooooooo"
    };

    void write(String s) throws IOException {
        String path = String.format("../tests/%02d", ++testCount);
        PrintWriter out = new PrintWriter(path);
        out.println(s);
        out.close();
        System.out.println(String.format("Test %d is generated", testCount));
    }


    void genHand(String[] a) throws IOException {
        for (String s : a) {
            write(s);
        }
    }

    void genRand(int n) throws IOException {
        StringBuilder s = new StringBuilder();
        for (int i = 0; i < n; i++) {
            s.append((char)(random.nextInt(26) + 'a'));
        }
        write(s.toString());
    }

    ArrayList<Integer> maxDivisors = new ArrayList<>();
    ArrayList<Integer> primes = new ArrayList<>();

    void precalc() {
        int best = 0;
        for (int i = 1; i <= MAX_N; i++) {
            int cnt = 0;
            for (int j = 1; j * j <= i; j++) {
                if (i % j == 0) {
                    cnt++;
                    if (j * j != i) {
                        cnt++;
                    }
                }
            }
            if (cnt > best) {
                best = cnt;
                maxDivisors.add(i);
            }
            if (cnt == 2) {
                primes.add(i);
            }
        }
    }

    void gen2BigTests(int n, int len) throws IOException {
        StringBuilder s = new StringBuilder();
        StringBuilder alpha = new StringBuilder();
        for (int j = 0; j < len; j++) {
            alpha.append((char) (random.nextInt(26) + 'a'));
        }
        for (int i = 0; i < n - 1; i++) {
            s.append(alpha);
        }
        s.append(alpha);
        write(s.toString());
        s.delete(s.length() - alpha.length(), s.length());
        alpha.setCharAt(0, (char) ('a' + (alpha.charAt(0) - 'a' + 1) % 26));
        s.append(alpha);
        write(s.toString());
    }

    void genTestOneK(int n, int alpha) throws IOException {
        ArrayList<Integer> a = new ArrayList<>();
        for (int i = 2; i < n; i++) {
            if (n % i == 0) {
                a.add(i);
            }
        }
        assert !a.isEmpty();
        int o = a.get(random.nextInt(a.size()));
        StringBuilder b = new StringBuilder();
        for (int i = 0; i < o; i++) {
            b.append((char)('a' + random.nextInt(alpha)));
        }
        String s = b.toString();
        String ss = s + s;
        StringBuilder res = new StringBuilder();
        for (int i = 0; i < n / o; i++) {
            int id = random.nextInt(s.length());
            String cur = ss.substring(id, id + s.length());
            res.append(cur);
        }
        write(res.toString());
    }

    void run() throws IOException {
        new File("../tests").mkdir();

        precalc();

        genHand(samples);
        genHand(hand);
        genRand(100);
        genRand(77777);
        genRand(random.nextInt(MAX_N) + 1);
        genRand(MAX_N);
        gen2BigTests(maxDivisors.get(maxDivisors.size() - 1), 1);
        gen2BigTests(primes.get(primes.size() - 1), 1);
        genTestOneK(maxDivisors.get(maxDivisors.size() - 1), 2);
        genTestOneK(maxDivisors.get(maxDivisors.size() - 1), 3);
        genTestOneK(maxDivisors.get(maxDivisors.size() - 1), 5);
        genTestOneK(maxDivisors.get(maxDivisors.size() - 1), 10);
        genTestOneK(maxDivisors.get(maxDivisors.size() - 1), 26);
        gen2BigTests(maxDivisors.get(maxDivisors.size() - 3), 2);
        gen2BigTests(maxDivisors.get(maxDivisors.size() - 6), 4);
        gen2BigTests(maxDivisors.get(maxDivisors.size() - 7), 6);

    }

    public static void main(String[] args) throws IOException {
        new TestGen().run();
    }
}