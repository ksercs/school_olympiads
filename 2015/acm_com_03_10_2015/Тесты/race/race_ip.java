import java.util.*;
import java.io.*;

public class race_ip {
    FastScanner in;
    PrintWriter out;

    final String TASK_NAME = "race";
    long ans;
    String[] a;

    public static class Edge {
        int c;
        Node to;

        public Edge(int c, Node to) {
            this.c = c;
            this.to = to;
        }
    }

    public void solve() throws IOException {
        int n = in.nextInt();
        a = new String[n];
        Trie trie = new Trie();
        for (int i = 0; i < n; ++i) {
            a[i] = in.next();
            trie.insert(a[i], i);
        }
        dfs(trie.root, 0);
        out.println(ans);
    }

    public Pair dfs(Node v, int lev) {
        Pair ret = null;
        int sm = 0;
        for (Edge c : v.children) {
            sm += c.to.cntEnd;
            Pair child = dfs(c.to, lev + 1);
            if (ret == null) {
                ret = child;
                continue;
            }
            if (child.trie.size < ret.trie.size) ret = merge(ret, child);
            else ret = merge(child, ret);
        }

        int endHere = v.cntEnd - sm;
        int id = v.idEnd;
        if (id != -1) {
            if (ret == null) ret = new Pair(0, new Trie());
            Node cur = ret.trie.root;
            for (int i = 0; i < a[id].length(); ++i) {
                int c = a[id].charAt(a[id].length() - i - 1) - 'a';
                Node to = cur.get(c);
                if (to == null) {
                    ret.trie.size++;
                    to = new Node();
                    cur.children.add(new Edge(c, to));
                }
                cur = to;
                cur.cntEnd += endHere;
                ret.mul = Math.max(ret.mul, (long) (i + 1) * cur.cntEnd);
            }
        }
        ans = Math.max(ans, ret.mul * lev);
        return ret;
    }
    Pair merge(Pair more, Pair less) {
        long mx = relaxDfs(less.trie.root, more.trie.root, 0, more.trie);
        more.mul = Math.max(more.mul, mx);
        return more;
    }

    long relaxDfs(Node less, Node more, int lev, Trie s) {
        long mx = (long) more.cntEnd * lev;
        for (Edge t : less.children) {
            Node to = more.get(t.c);
            if (to == null) {
                s.size++;
                to = new Node();
                more.children.add(new Edge(t.c, to));
            }
            to.cntEnd += t.to.cntEnd;
            mx = Math.max(mx, relaxDfs(t.to, to, lev + 1, s));
        }
        return mx;
    }

    class Pair {
        long mul;
        Trie trie;
        Pair(long m, Trie a) {
            mul = m;
            trie = a;
        }
    }

    class Node {
        public static final int K = 26;
        public ArrayList<Edge> children = new ArrayList<>();
        public int cntEnd;
        private int idEnd = -1;

        public Node get(int c) {
            for (Edge t : children)
                if (t.c == c)
                    return t.to;
            return null;
        }
    }

    class Trie {
        public int size = 1;
        public Node root = new Node();

        public void insert(String s, int id) {
            Node v = root;
            for (int i = 0; i < s.length(); ++i) {
                int c = s.charAt(i) - 'a';
                Node to = v.get(c);
                if (to == null) {
                    to = new Node();
                    v.children.add(new Edge(c, to));
                    size++;
                }
                v = to;
                v.cntEnd++;
            }
            v.idEnd = id;
        }
    }

    public void run() {
        try {
            in = new FastScanner(new File(TASK_NAME + ".in"));
            out = new PrintWriter(new File(TASK_NAME + ".out"));

            solve();

            out.close();
        } catch (IOException e) {
            e.printStackTrace();
        }
    }

    class FastScanner {
        BufferedReader br;
        StringTokenizer st;

        FastScanner(File f) {
            try {
                br = new BufferedReader(new FileReader(f));
            } catch (FileNotFoundException e) {
                e.printStackTrace();
            }
        }

        String next() {
            while (st == null || !st.hasMoreTokens()) {
                try {
                    st = new StringTokenizer(br.readLine());
                } catch (IOException e) {
                    e.printStackTrace();
                }
            }
            return st.nextToken();
        }

        int nextInt() {
            return Integer.parseInt(next());
        }
    }

    public static void main(String[] arg) {
        new race_ip().run();
    }
}