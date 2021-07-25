/**
 * Created by Grigorii Shovkoplias on 01.10.2015.
 */

import java.io.*;
import java.util.*;

public class TestGen {

    private void gen() throws Exception {
        new File("../tests").mkdir();
        done = 0;
        genSamples();
        genSimples();
        genRand();
        genMax();
    }

    public static void main(String[] args) throws Exception {
        new TestGen().gen();
    }

    private int done = 0;
    private final Random rnd = new Random(3289214075201L);
    private final int MAXN = 1_000_000_000;

    private int rand(int n) {
        if (n < 1)
            return 0;
        return rnd.nextInt(n);
    }

    private char zeroOrOne() {
        return (char) ('0' + rnd.nextInt(2));
    }

    private long rand(long n) {
        if (n < 1)
            return 0;
        long res = rand(Integer.MAX_VALUE);
        res <<= 32;
        res += rand(Integer.MAX_VALUE);
        res %= n;
        return res;
    }

    private void print(int a, int b, int c, int d, int k) throws IOException {
        done++;
        System.err.println("Generation test #" + done);
        PrintWriter out = new PrintWriter(String.format("../tests/%02d", done));
        out.println(String.format("%d %d %d %d %d", a, b, c, d, k));
        out.close();
    }

    //begin generators

    private void genSamples() throws IOException {
        print(1, 10, 1, 7, 3);
        print(1, 2, 2, 3, 7);
        print(1, 4, 2, 3, 2);
    }

    private void genSimples() throws IOException {
        print(100, 140, 100, 140, 100);
        print(1, 2, 1000, 2000, 100);
        print(256, 512, 18, 18, 10);
        print(1, 1, 1, 1, 1);
    }

    private void genRand() throws IOException {
        for (int i = 0; i < 15; i++) {
            int b = rand(MAXN) + 1;
            int a = rand(b) + 1;
            int d = rand(MAXN) + 1;
            int c = rand(d) + 1;
            int k = rand(MAXN) + 1;
            print(a, b, c, d, k);
        }
    }

    private void genMax() throws IOException {
        print(1, MAXN, 1, MAXN, MAXN);
        print(1, MAXN, 1, MAXN, MAXN / 3);
        print(1, MAXN, 1, MAXN, 237);
        print(MAXN, MAXN, MAXN, MAXN, MAXN);
        print(MAXN / 2, MAXN, MAXN / 3, MAXN, MAXN / 4);
        print(MAXN, MAXN, MAXN, MAXN, 1);
        print(MAXN / 5, MAXN, MAXN / 4, MAXN, 345);
    }


    //end generators

}
