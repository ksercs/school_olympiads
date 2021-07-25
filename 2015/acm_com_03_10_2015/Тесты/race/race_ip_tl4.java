import java.util.*;
import java.io.*;

public class race_ip_tl4 {
    FastScanner in;
    PrintWriter out;

    final String TASK_NAME = "race";
    long ans;
    String[] a;

    public void solve() throws IOException {
        long l = System.currentTimeMillis();

        int n = in.nextInt();
        a = new String[n];
        Trie trie = new Trie();
        for (int i = 0; i < n; ++i) {
            a[i] = in.next();
            trie.insert(a[i], i);
        }
        dfs(trie.root, 0);
        out.println(ans);
        System.out.println((System.currentTimeMillis() - l) / 1000.0);
    }

    public Pair dfs(Node v, int lev) {
        Pair ret = null;
        int sm = 0;
        for (Integer c : v.children) {
            sm += v.to[c].cntEnd;
            Pair child = dfs(v.to[c], lev + 1);
            if (ret == null) {
                ret = child;
                continue;
            }
            //if (child.trie.size < ret.trie.size) ret = merge(ret, child);
            //else ret = merge(child, ret);
	        ret = merge(child, ret);
        }

        int endHere = v.cntEnd - sm;
        int id = v.idEnd;
        if (id != -1) {
            if (ret == null) ret = new Pair(0, new Trie());
            Node cur = ret.trie.root;
            for (int i = 0; i < a[id].length(); ++i) {
                int c = a[id].charAt(a[id].length() - i - 1) - 'a';
                if (cur.to[c] == null) {
                    ret.trie.size++;
                    cur.children.add(c);
                    cur.to[c] = new Node();
                }
                cur = cur.to[c];
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
        for (Integer c : less.children) {
            if (more.to[c] == null) {
                more.to[c] = new Node();
                s.size++;
                more.children.add(c);
            }
            more.to[c].cntEnd += less.to[c].cntEnd;
            mx = Math.max(mx, relaxDfs(less.to[c], more.to[c], lev + 1, s));
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
        public Node[] to = new Node[K];
        public ArrayList<Integer> children = new ArrayList<>();
        public int cntEnd;
        private int idEnd = -1;
    }

    class Trie {
        public int size = 1;
        public Node root = new Node();

        public void insert(String s, int id) {
            Node v = root;
            for (int i = 0; i < s.length(); ++i) {
                int c = s.charAt(i) - 'a';
                if (v.to[c] == null) {
                    v.to[c] = new Node();
                    v.children.add(c);
                    size++;
                }
                v = v.to[c];
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
        new race_ip_tl4().run();
    }
}