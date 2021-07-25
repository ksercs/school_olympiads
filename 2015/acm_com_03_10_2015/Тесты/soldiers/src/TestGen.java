import java.io.*;
import java.util.*;

public class TestGen {

    static PrintWriter out;
    static Random rnd = new Random(0);
    static int tNumber = 1;
    
    
    static void printTest(int n, int m, int k, String commands) throws IOException {
        System.out.println(String.format("Generating test %d", tNumber));
        out = new PrintWriter(String.format("../tests/%02d", tNumber++));
        out.println(n + " " + m);
        out.println(k);
        out.println(commands);             
        out.close();
    }

    
    static void genSample() throws IOException {
        printTest(5, 3, 7, "LRARLRL");
    }
    
    static int randFromTo(int l, int r) {
        return rnd.nextInt(r - l + 1) + l;      
    }

    static char randomCommand() {
        int t = randFromTo(0, 2);
        if (t == 0)
            return 'A';
        if (t == 1)
            return 'L';
        return 'R';
    }
    

    public static void main(String[] args) throws IOException {
        new File("../tests").mkdir();        
        genSample();
        
        for (int i = 0; i < 5; ++i) {
            int n = randFromTo(2, 5);
            int m = randFromTo(1, n-1);
            int k = 10;
            StringBuilder s = new StringBuilder();
            for (int j = 0; j < k; ++j) {
                s.append(randomCommand());
            }
            printTest(n, m, k, s.toString());
        }

        printTest(1, 0, 11, "AALRLRLRAAA");
        printTest(1, 1, 22, "AALRLRAARLAALLRRRLRAAA");
        printTest(10, 5, 5, "AAAAA");

        for (int i = 0; i < 10; ++i) {
            int n = randFromTo(10000, 100000);
            int m = randFromTo(1000, n);
            int k = 100000;
            StringBuilder s = new StringBuilder();
            for (int j = 0; j < k; ++j) {
                s.append(randomCommand());
            }
            printTest(n, m, k, s.toString());
        }

        {
            int n = 100000;
            int m = 100000;
            int k = 100000;
            StringBuilder s = new StringBuilder();
            for (int j = 0; j < k; ++j) {
                s.append(randomCommand());
            }
            printTest(n, m, k, s.toString());
        }


        {
            int n = 100000;
            int m = 0;
            int k = 100000;
        
            StringBuilder s = new StringBuilder();
            for (int j = 0; j < k; ++j) {
                s.append(randomCommand());
            }
            printTest(n, m, k, s.toString());
        }

        {
            int n = randFromTo(10000, 100000);
            int m = randFromTo(1000, n);
            int k = 100000;
            StringBuilder s = new StringBuilder();
            for (int j = 0; j < k; ++j) {
                s.append('A');
            }
            printTest(n, m, k, s.toString());
        }

        {
            int n = randFromTo(10000, 100000);
            int m = randFromTo(1000, n);
            int k = 100000;
            StringBuilder s = new StringBuilder();
            for (int j = 0; j < k; ++j) {
                s.append('L');
            }
            printTest(n, m, k, s.toString());
        }

        {
            int n = randFromTo(10000, 100000);
            int m = randFromTo(1000, n);
            int k = 100000;
            StringBuilder s = new StringBuilder();
            for (int j = 0; j < k; ++j) {
                s.append('R');
            }
            printTest(n, m, k, s.toString());
        }
    }                 
}


