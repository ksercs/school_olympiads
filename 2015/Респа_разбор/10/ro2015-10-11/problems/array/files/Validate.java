import java.io.*;
import java.util.*;

public class Validate {
    
    static final int MX = 100000;
    
    public void run() {
        StrictScanner inf = new StrictScanner(System.in);
        
        int n = inf.nextInt();
        int m = inf.nextInt();
        ensureLimits(n, 1, MX, "n is out of range");
        ensureLimits(m, 1, MX, "n is out of range");
        
        inf.nextLine();
        
        for (int i = 0; i < m; i++) {
            int l = inf.nextInt();
            int r = inf.nextInt();
            int x = inf.nextInt();
            ensureLimits(l, 1, n, "T is out of range");
            ensureLimits(r, l, n, "wrong num r");
            ensureLimits(x, 0, 1000000000, "wrong num x");
            inf.nextLine();
        }
        
        inf.close();
    }
    
    public static void main(String[] args) {
        new Validate().run();
    }
    
    public class StrictScanner {
        private final BufferedReader in;
        private String line = "";
        private int pos;
        private int lineNo;
        
        public StrictScanner(InputStream source) {
            in = new BufferedReader(new InputStreamReader(source));
            nextLine();
        }
        
        public void close() {
            ensure(line == null, "Extra data at the end of file");
            try {
                in.close();
            } catch (IOException e) {
                throw new AssertionError("Failed to close with " + e);
            }
        }
        
        public void nextLine() {
            ensure(line != null, "EOF");
            ensure(pos == line.length(),  "Extra characters on line " + lineNo);
            try {
                line = in.readLine();
            } catch (IOException e) {
                throw new AssertionError("Failed to read line with " + e);
            }
            pos = 0;
            lineNo++;
        }
        
        public String next() {
            ensure(line != null, "EOF");
            ensure(line.length() > 0,  "Empty line " + lineNo);
            if (pos == 0)
                ensure(line.charAt(0) > ' ',  "Line " + lineNo + " starts with whitespace");
            else {
                ensure(pos < line.length(),  "Line " + lineNo + " is over");
                ensure(line.charAt(pos) == ' ',  "Wrong whitespace on line " + lineNo);
                pos++;
                ensure(pos < line.length(),  "Line " + lineNo + " is over");
                ensure(line.charAt(0) > ' ',  "Line " + lineNo + " has double whitespace");
            }
            StringBuilder sb = new StringBuilder();
            while (pos < line.length() && line.charAt(pos) > ' ')
                sb.append(line.charAt(pos++));
            return sb.toString();
        }
        
        public int nextInt() {
            String s = next();
            ensure(s.length() == 1 || s.charAt(0) != '0',  "Extra leading zero in number " + s + " on line " + lineNo);
            ensure(s.charAt(0) != '+',  "Extra leading '+' in number " + s + " on line " + lineNo);
            try {
                return Integer.parseInt(s);
            } catch (NumberFormatException e) {
                throw new AssertionError("Malformed number " + s + " on line " + lineNo);
            }
        }
        
        public double nextDouble() {
            String s = next();
            ensure(s.length() == 1 || s.startsWith("0.") || s.charAt(0) != '0',  "Extra leading zero in number " + s + " on line " + lineNo);
            ensure(s.charAt(0) != '+',  "Extra leading '+' in number " + s + " on line " + lineNo);
            try {
                return Double.parseDouble(s);
            } catch (NumberFormatException e) {
                throw new AssertionError("Malformed number " + s + " on line " + lineNo);
            }
        }
    }
    
    void ensure(boolean b, String message) {
        if (!b) {
            throw new AssertionError(message);
        }
    }
    
    void ensureLimits(int n, int from, int to, String name) {
        ensure(from <= n && n <= to, name + " must be from " + from + " to " + to);
    }
    
}