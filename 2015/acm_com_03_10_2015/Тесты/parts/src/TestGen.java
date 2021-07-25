import java.io.*;
import java.util.*;

public class TestGen {

    static PrintWriter out;
    static Random rnd = new Random(0);
    static int tNumber = 1;
    
    
    static void printTest(int n, int[] a, int[] b) throws IOException {
        System.out.println(String.format("Generating test %d", tNumber));
        out = new PrintWriter(String.format("../tests/%02d", tNumber++));
        out.println(n);
        for (int i = 0; i < n; i++) {
            out.println(a[i] + " " + b[i]);
        }
        out.close();
    }

    
    static void genSample() throws IOException {
        printTest(4, new int[]{3, 7, 2, 1}, new int[]{5, 9, 4, 10});
    }
    
    static int randFromTo(int l, int r) {
        return rnd.nextInt(r - l + 1) + l;      
    }

    public static void main(String[] args) throws IOException {
        new File("../tests").mkdir();        
        genSample();
        for (int it = 0; it < 5; ++it) {
            int n = randFromTo(3, 20);
            int[] a = new int[n];
            int[] b = new int[n];
            for (int i = 0; i < n; ++i) {
                b[i] = randFromTo(1, 10);
                a[i] = randFromTo(1, b[i]);
            }
            printTest(n, a, b);
        }

        {
            int n = 1;
            int[] a = new int[n];
            int[] b = new int[n];
            a[0] = randFromTo(1, 10000);
            b[0] = a[0];
            printTest(n, a, b);
        }
        
        {
            int n = 1;
            int[] a = new int[n];
            int[] b = new int[n];
            b[0] = randFromTo(1, 10000);
            a[0] = randFromTo(1, b[0]);
            printTest(n, a, b);
        }

        {
            int n = 10;
            int[] a = new int[n];
            int[] b = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = randFromTo(1, 10000);
                b[i] = a[i];
            }
            printTest(n, a, b);
        }

        for (int it = 0; it < 10; ++it) {
            int n = randFromTo(10000, 100000);
            int[] a = new int[n];
            int[] b = new int[n];
            for (int i = 0; i < n-1; ++i) {
                b[i] = randFromTo(1, 1000000000);
                a[i] = randFromTo(b[i]/2, b[i]);
            }
            a[n-1] = randFromTo(1, 1000000000);
            b[n-1] = a[n-1];
            printTest(n, a, b);
        }
        
        {
            int n = 100000;
            int[] a = new int[n];
            int[] b = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = 1;
                b[i] = 1000000000;
            }
            printTest(n, a, b);
        }
        
        {
            int n = 100000;
            int[] a = new int[n];
            int[] b = new int[n];
            for (int i = 0; i < n; ++i) {
                a[i] = 1000000000-1;
                b[i] = 1000000000;
            }
            printTest(n, a, b);
        }
        
        {
            int n = 100000;
            int[] a = new int[n];
            int[] b = new int[n];
            for (int i = 0; i < n; ++i) {
                b[i] = randFromTo(1, 1000000000);
                a[i] = Math.max(1, b[i] - 1);
            }
            printTest(n, a, b);
        }
        
        for (int it = 0; it < 5; ++it) {
            int n = randFromTo(10000, 100000);
            int[] a = new int[n];
            int[] b = new int[n];
            for (int i = 0; i < n; ++i) {
                b[i] = randFromTo(100000000, 1000000000);
                a[i] = randFromTo(1, b[i]);
            }
            printTest(n, a, b);
        }

    }                 
}


