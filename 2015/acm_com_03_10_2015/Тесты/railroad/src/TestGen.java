import java.io.*;
import java.util.*;

public class TestGen {
    final int N = 100000;
    final int MAX_X = 1_000_000_000;
    final Random random = new Random(0xBEEF);

    int testCount;
    public class Test {
        int[] a, b, v, t;
        int x;

        public Test shuffle() {
            List<Integer> np = new ArrayList<>();
            for (int i = 0; i < a.length; ++i) np.add(i);
            Collections.shuffle(np, random);

            List<Integer> mp = new ArrayList<>();
            for (int i = 0; i < t.length; ++i) mp.add(i);
            Collections.shuffle(mp, random);

            int[] na = new int[a.length];
            int[] nb = new int[a.length];
            int[] nv = new int[a.length];
            int[] nt = new int[t.length];
            for (int i = 0; i < a.length; ++i) {
                na[np.get(i)] = a[i];
                nb[np.get(i)] = b[i];
                nv[np.get(i)] = v[i];
            }

            for (int i = 0; i < t.length; ++i)
                nt[mp.get(i)] = t[i];
            return new Test(a, b, v, t, x);
        }

        public Test(int[] a, int[] b, int[] v, int[] t, int x) {
            this.a = a;
            this.b = b;
            this.v = v;
            this.t = t;
            this.x = x;
        }

        public Test(Integer[] a, Integer[] b, Integer[] v, Integer[] t, int x) {
            this.a = new int[a.length];
            this.b = new int[b.length];
            this.v = new int[v.length];
            this.t = new int[t.length];
            for (int i = 0; i < a.length; ++i) {
                this.a[i] = a[i];
                this.b[i] = b[i];
                this.v[i] = v[i];
            }
            for (int i = 0; i < t.length; ++i)
                this.t[i] = t[i];
            this.x = x;
        }

        public Test(List<Integer> a, List<Integer> b, List<Integer> v, List<Integer> t, int x) {
            this(a.toArray(new Integer[a.size()]), b.toArray(new Integer[b.size()]), v.toArray(new Integer[v.size()]), t.toArray(new Integer[t.size()]), x);
        }
    }

    void print(Test test) throws IOException {
        PrintWriter out = new PrintWriter(String.format("../tests/%02d", ++testCount));
        int n = test.a.length;
        int m = test.t.length;
        test = test.shuffle();

        out.println(n + " " + m + " " + test.x);
        for (int i = 0; i < n; ++i)
            out.println(test.a[i] + " " + test.b[i] + " " + test.v[i]);
        for (int i = 0; i < m; ++i)
            if (i + 1 < m) out.print(test.t[i] + " ");
            else out.println(test.t[i]);
        out.close();
        System.out.println(testCount);
    }

    void genSamples() throws IOException {
        print(new Test(new int[]{-4, 13, -7}, new int[]{-1, 6, -6}, new int[]{1, 3, 1}, new int[]{1, 5}, 0));
        print(new Test(new int[]{4, -11}, new int[]{2, -8}, new int[]{1, 2}, new int[]{2, 6}, 0));
    }

    void genHandleTests() throws IOException {
    }

    private int randomInSegment(Pair<Double, Double> segm) {
        int l = (int)Math.ceil(segm.left);
        int r = (int)Math.floor(segm.right);
        if (l > r)
            return Integer.MIN_VALUE;
        return random.nextInt(r - l + 1) + l;
    }

    private int[] randomInSegments(int m, List<Pair<Double, Double>> segments) {
        int[] t = new int[m];
        for (int i = 0; i < m; ++i) {
            int j, val;
            do {
                j = random.nextInt(segments.size());
                val = randomInSegment(segments.get(j));
            } while (val == Integer.MIN_VALUE);
            t[i] = val;
        }
        return t;
    }

    private int[] mostCompSegment(int m, List<Pair<Double, Double>> segments, Comparator<Double> comparator) {
        double mx = segments.get(0).right - segments.get(0).left;
        int mxid = 0;
        for (int i = 1; i < segments.size(); ++i)
            if (comparator.compare(segments.get(i).right - segments.get(i).left, mx) > 0) {
                mx = segments.get(i).right - segments.get(i).left;
                mxid = i;
            }
        return randomInSegments(m, Collections.singletonList(segments.get(mxid)));
    }

    private final Action randomFree = (busy, free, m) -> randomInSegments(m, free);
    private final Action randomBusy = (busy, free, m) -> randomInSegments(m, busy);
    private final Action mostLongFree = (busy, free, m) -> mostCompSegment(m, free, Comparator.<Double>naturalOrder());
    private final Action mostLongBusy = (busy, free, m) -> mostCompSegment(m, busy, Comparator.<Double>naturalOrder());
    private final Action leastLongFree = (busy, free, m) -> mostCompSegment(m, free, Comparator.<Double>reverseOrder());
    private final Action leastLongBusy = (busy, free, m) -> mostCompSegment(m, busy, Comparator.<Double>reverseOrder());

    private final Action incrBusy = (busy, free, m) -> {
        int[] t = new int[m];
        int j = 0;
        for (int i = 0; i < busy.size() && j < m; ++i) {
            int l = (int)Math.ceil(busy.get(i).left);
            int r = (int)Math.floor(busy.get(i).right);
            if (l > r)
                continue;

            for (int c = 1; c <= i + 1 && j < m; ++c)
                t[j++] = randomInSegment(busy.get(i));
        }
        if (j != m) {
            int sz = m - j;
            for (int c = 1; c <= sz; ++c)
                t[j++] = randomInSegment(busy.get(busy.size() - 1));
        }
        return t;
    };

    void run() throws IOException {
        new File("../tests").mkdir();
        genSamples();
        genHandleTests();

        print(manyOvertaking(N, N, 0, randomBusy));//11
        print(manyOvertaking(N, N, 0, randomFree));
        print(manyOvertaking(N, N, N / 2, mostLongBusy));
        print(manyOvertaking(N, N, N - 1000, incrBusy));//14

        print(startBusy(N, N, N / 2, 100));//15
        print(startBusy(N, N, N, 100000));

        print(closely(N, N));//18
        print(closely(N, N));

        print(beforeAll(N, N));//21
        print(beforeAll(N, N));//22

        print(afterAll(N, N));//23
        print(afterAll(N, N));//24

        print(byGroup(N, N, (int) Math.sqrt(N), randomBusy));//25
        print(byGroup(N, N, (int) Math.sqrt(N), randomFree));
        print(byGroup(N, N, 10, randomBusy));
        print(byGroup(N, N, 100, randomBusy));
        print(byGroup(N, N, 10000, mostLongBusy));
        print(byGroup(N, N, 10, incrBusy));
        print(byGroup(N, N, 100, incrBusy));
        print(byGroup(N, N, (int) Math.sqrt(N), incrBusy));
        print(byGroup(N, N, 1000, incrBusy));//34
        print(byGroup(N, N, 10, mostLongFree));
        print(byGroup(N, N, 100, mostLongFree));
        print(byGroup(N, N, 1000, mostLongFree));
        //print(byGroup(N, N, 10, leastLongFree));

        print(randomTest(N, N, 1000));//40
        print(randomTest(N, N, MAX_X));//42
        print(randomTest(N, N, MAX_X));//43

        print(antiEps(30, 30, 0, 0));//3
        print(antiEps(30, 30, 0, MAX_X));
        print(antiEps(N, N, 0, 0));
        print(antiEps(N, N, 0, MAX_X));
        print(antiEps(N, N, 1, MAX_X));
    }

    private Test afterAll(int n, int m) {
        int maxT = random.nextInt(MAX_X / 2) + MAX_X / 2;
        int x = random();
        int[] a = new int[n];
        int[] b = new int[n];
        int[] v = new int[n];
        for (int i = 0; i < n; ++i) {
            v[i] = random();
            int bound = MAX_X;
            if ((long) v[i] * maxT < bound) bound = v[i] * maxT;
            a[i] = -random.nextInt(bound);
            b[i] = -random.nextInt(bound);
            if (a[i] > b[i]) {
                int tm = a[i];
                a[i] = b[i];
                b[i] = tm;
            }
            if (random.nextBoolean() && ensure(2 * x - a[i]) && ensure(2 * x - b[i])) {
                a[i] = 2 * x - a[i];
                b[i] = 2 * x - b[i];
            }
        }
        int[] t = new int[m];
        for (int i = 0; i < m; ++i)
            t[i] = random.nextInt(MAX_X - maxT) + maxT;
        return new Test(a, b, v, t, x);
    }

    private Test byGroup(int n, int m, int sizeGroup, Action action) {
        int[] intervals = randomIncreaseSeq(n / sizeGroup + 1);
        int groups = intervals.length - 1;
        int[] size = new int[groups];
        int x = 0;
        for (int i = 0; i < groups; ++i)
            size[i] = n / groups + (i < n % groups ? 1 : 0);
        int[] a = new int[n];
        int[] b = new int[n];
        int[] v = new int[n];
        int sz = 0;

        for (int i = 0; i + 1 < intervals.length; ++i) {
            int len = random.nextInt(intervals[i + 1] - intervals[i]) + 1;
            int[] times = randomIncreaseSeqEq(size[i] + 1, len);
            times[size[i]] = len;

            for (int j = 0; j < times.length; ++j) times[j] += intervals[i];
            int p = 0;
            for (int j = 0; j < size[i]; ++j) {
                while (times[p] == times[j]) ++p;
                int r = p + random.nextInt(times.length - p);
                int vi = random.nextInt(MAX_X / times[r]) + 1;
                int bi = -times[j] * vi;
                int ai = -times[r] * vi;
                if (random.nextBoolean()) {
                    ai = -ai;
                    bi = -bi;
                }
                a[sz] = ai;
                b[sz] = bi;
                v[sz] = vi;
                sz++;
            }
        }
        Pair<List<Pair<Double, Double>>, List<Pair<Double, Double>>> pair = getSegments(a, b, v, x);
        int[] t = action.generate(pair.left, pair.right, m);
        return new Test(a, b, v, t, x);
    }

    private Test beforeAll(int n, int m) {
        int x = random();
        int maxT = random.nextInt(MAX_X / 100);
        int[] a = new int[n];
        int[] b = new int[n];
        int[] v = new int[n];
        int[] t = new int[m];
        for (int i = 0; i < m; ++i)
            t[i] = random.nextInt(maxT);
        for (int i = 0; i < n; ++i) {
            v[i] = random.nextInt((x + MAX_X) / maxT - 2) + 1;
            b[i] = x - (random.nextInt(x + MAX_X - v[i] * maxT) + v[i] * maxT);
            a[i] = random.nextInt(MAX_X + b[i]) - MAX_X;
            if (random.nextBoolean() && ensure(2 * x - a[i]) && ensure(2 * x - b[i])) {
                a[i] = 2 * x - a[i];
                b[i] = 2 * x - b[i];
            }
        }
        return new Test(a, b, v, t, x);
    }

    private Test closely(int n, int m) {
        int x = 0;
        int[] a = new int[n];
        int[] b = new int[n];
        int[] v = new int[n];
        int[] t = new int[m];

        int[] arrivalT = randomIncreaseSeq(n + 1);
        for (int i = 0; i < n; ++i) {
            v[i] = random.nextInt(MAX_X / arrivalT[i + 1]) + 1;
            b[i] = -v[i] * arrivalT[i];
            a[i] = -v[i] * arrivalT[i + 1];
            if (random.nextBoolean()) {
                a[i] = -a[i];
                b[i] = -b[i];
            }
        }
        int cr = Math.min(n, m);
        System.arraycopy(arrivalT, 0, t, 0, cr);
        for (int i = cr; i < m; ++i)
            t[i] = random.nextInt(MAX_X);
        return new Test(a, b, v, t, x);
    }

    private Test randomTest(int n, int m, int maxval) {
        int[] a = new int[n];
        int[] b = new int[n];
        int[] v = new int[n];
        int[] t = new int[m];
        int x = random.nextInt(2 * maxval) - maxval;
        for (int i = 0; i < n; ++i) {
            a[i] = random.nextInt(2 * maxval) - maxval;
            b[i] = random.nextInt(2 * maxval) - maxval;
            if (a[i] == b[i]) {
                --i;
                continue;
            }
            v[i] = random.nextInt(maxval / 2) + maxval / 2;
        }
        for (int i = 0; i < m; ++i)
            t[i] = random.nextInt(maxval);
        return new Test(a, b, v, t, x);
    }

    private Test startBusy(int n, int m, int busy, int maxt) {
        int x = random.nextInt(1000) - 500;
        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();
        List<Integer> v = new ArrayList<>();
        for (int i = 0; i < busy; ++i) {
            int vec = random.nextBoolean() ? 1 : -1;
            int l = -random();
            int r = random();
            a.add(l * vec);
            b.add(r * vec);
            v.add(random());
        }
        for (int i = 0; i < n - busy; ++i) {
            int l = random.nextInt(MAX_X * 2) - MAX_X;
            int r = random.nextInt(MAX_X * 2) - MAX_X;
            a.add(l);
            b.add(r);
            v.add(random());
        }
        List<Integer> t = new ArrayList<>();
        for (int i = 0; i < m; ++i)
            t.add(random.nextInt(maxt));
        return new Test(a, b, v, t, x);
    }


    public interface Action {
        int[] generate(List<Pair<Double, Double>> busy, List<Pair<Double, Double>> free, int m);
    }

    private int random() {
        return random.nextInt(MAX_X) + 1;
    }

    private Test manyOvertaking(int n, int m, int decrDest, Action action) {
        int[] b = new int[n];
        int[] v = new int[n];

        double[] lf = new double[n];
        double[] rg = new double[n];
        int[] a = randomIncreaseSeq(n);
        for (int i = 0; i < n; ++i)
            a[i] = -a[i];
        for (int i = 0; i < n / 2; ++i) {
            int tmp = a[i];
            a[i] = a[n - i - 1];
            a[n - i - 1] = tmp;
        }
        int x = random.nextInt(100) - 50;
        for (int i = 0; i + 1 < n; ++i)
            b[i] = random.nextInt(a[i + 1] - a[i]) + a[i] + 1;
        b[n - 1] = random.nextInt(MAX_X - a[n - 1]) + a[n - 1] + 1;
        int[] tm = randomIncreaseSeq(n);
        for (int i = 0; i < n; ++i) {
            double curt = tm[i] + random.nextDouble();
            v[i] = (int)((x - b[i]) / curt) + 1;
            lf[i] = Math.min(Math.abs(a[i] - x), Math.abs(b[i] - x)) / v[i];
            rg[i] = Math.max(Math.abs(a[i] - x), Math.abs(b[i] - x)) / v[i];
        }
        List<Integer> id = randomSubset(n, decrDest);
        for (Integer anId : id) {
            a[anId] *= -1;
            b[anId] *= -1;
        }
        Pair<List<Pair<Double, Double>>,
            List<Pair<Double, Double>>> segments = getSegments(a, b, v, x);
        int[] t = action.generate(segments.left, segments.right, m);
        return new Test(a, b, v, t, x);
    }

    public static class Event implements Comparable<Event> {
        public static double EPS = 1e-9;
        int tp;
        double t;
        Event(int tp, double t) {
            this.tp = tp;
            this.t = t;
        }

        @Override
        public int compareTo(Event o) {
            if (Math.abs(t - o.t) < EPS)
                return tp - o.tp;
            if (t < o.t)
                return -1;
            return 1;
        }
    }

    private Pair<List<Pair<Double, Double>>, List<Pair<Double, Double>>> getSegments(int[] a, int[] b, int[] v, int x) {
        List<Event> ev = new ArrayList<>();
        for (int i = 0; i < a.length; ++i) {
            int absv = (a[i] < b[i] ? 1 : -1);
            if ((x - a[i]) * absv <= 0) continue;
            if ((x - b[i]) * absv >= 0) ev.add(new Event(0, (x - b[i]) * absv * 1.0 / v[i]));
            else ev.add(new Event(0, 0.0));
            ev.add(new Event(1, (x - a[i]) * absv * 1.0 / v[i]));
        }
        Collections.sort(ev);
        int bal = 0;
        List<Pair<Double, Double>> free = new ArrayList<>();
        for (int i = 0; i + 1 < ev.size(); ++i) {
            if (ev.get(i).tp == 0) ++bal;
            else --bal;
            if (bal == 0) free.add(new Pair<>(ev.get(i).t, ev.get(i + 1).t));
        }
        if (0 < ev.get(0).t) free.add(new Pair<>(0.0, ev.get(0).t));
        if (ev.get(ev.size() - 1).t < MAX_X) free.add(new Pair<>(ev.get(ev.size() - 1).t, MAX_X * 1.0));
        List<Pair<Double, Double>> busy = new ArrayList<>();
        for (int i = 0; i + 1 < free.size(); ++i)
            busy.add(new Pair<>(free.get(i).right, free.get(i + 1).left));
        return new Pair<>(busy, free);
    }

    private int[] randomIncreaseSeq(int n) {
        Set<Integer> s = new HashSet<>();
        while (s.size() < n) {
            int x = random();
            s.add(x);
        }
        int[] a = new int[n];
        int j = 0;
        for (Integer x : s)
            a[j++] = x;
        Arrays.sort(a);
        return a;
    }

    private int[] randomIncreaseSeqEq(int n, int mx) {
        int[] a = new int[n];
        for (int i = 0; i < n; ++i)
            a[i] = random.nextInt(mx);
        Arrays.sort(a);
        return a;
    }

    private List<Integer> randomSubset(int n, int k) {
        List<Integer> perm = new ArrayList<>();
        for (int i = 0; i < n; ++i) perm.add(i);
        shuffle(perm);
        return perm.subList(0, k);
    }

    private List<?> shuffle(List<?> ar) {
        Collections.shuffle(ar, random);
        return ar;
    }

    public Test antiEps(int n, int m, int t, int x) {
        int maxV = Math.min(MAX_X, (t == 0 ? x + MAX_X : x / t + MAX_X));
        List<Integer> a = new ArrayList<>();
        List<Integer> b = new ArrayList<>();
        List<Integer> v = new ArrayList<>();
        List<Integer> tj = new ArrayList<>();
        for (int i = maxV; i >= maxV - 20; --i)
            if (ensure(x - (i * t + 1))) {
                b.add(x - (i * t + 1));
                a.add(-MAX_X);
                v.add(i);
            }
        int len = maxV - maxV / 10;
        for (int i = 0; i < n - a.size(); ++i) {
            int vi = random.nextInt(len) + maxV / 10;
            int delta = random.nextInt(10) + 1;
            if (ensure(x - (vi * t + delta))) {
                int ai = x - (vi * t + delta);
                int bi = -MAX_X + random.nextInt(20);
                if (ai == bi) {
                    --i;
                    continue;
                }
                b.add(ai);
                a.add(bi);
                v.add(vi);
                if (a.get(a.size() - 1) >= b.get(b.size() - 1))
                    throw new AssertionError("ai >= bi");
            }
        }
        for (int i = 0; i < m; ++i)
            tj.add(t + random.nextInt(5));
        return new Test(a, b, v, tj, x);
    }

    private boolean ensure(int x) {
        return -MAX_X <= x && x <= MAX_X;
    }

    public static void main(String[] args) throws IOException {
        new TestGen().run();
    }

    private static class Pair<A, B> {
        Pair(A a, B b) {
            left = a;
            right = b;
        }

        A left;
        B right;
    }
}
