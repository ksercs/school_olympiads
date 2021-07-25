import java.io.*;
import java.util.*;

public class TestGen {
    final int MAX_SUM = 200000;
    final int ALPHABET = 26;
    Random random = new Random(0xBAD);
    boolean isSamples = false;

    int testCount;

    void print(String[] strings) throws IOException {
        int sm = 0;
        for (String string1 : strings)
            sm += string1.length();
        if (sm > MAX_SUM)
            throw new IllegalArgumentException("Sum length too long, sum = " + sm);

        PrintWriter out = new PrintWriter(String.format("../tests/%02d", ++testCount));
        System.out.println(testCount);
        out.println(strings.length);
        for (String string : strings)
            out.println(string);
        out.close();
    }

    void genSamples() throws IOException {
        print(new String[]{
                "aa",
                "aa",
                "aa",
                "bb"
        });

        print(new String[]{
                "aba",
                "ab",
                "abbba",
                "aba"
        });

        print(new String[]{
                "abac",
                "abaac",
                "aac",
                "abac",
                "abc"
        });
    }

    void genHandleTests() throws IOException {
    }

    public String[] merge(String[]... arrays) {
        int sumSize = 0;
        for (String[] array : arrays)
            sumSize += array.length;
        String[] ret = new String[sumSize];
        int ptr = 0;
        for (String[] array : arrays)
            for (String anArray : array)
                ret[ptr++] = anArray;
        return shuffle(Arrays.asList(ret)).toArray(ret);
    }

    void run() throws IOException {
        new File("../tests").mkdir();
        int n = MAX_SUM;
        genSamples();
        genHandleTests();

        print(genOneLong(MAX_SUM));
        print(genOneChar(MAX_SUM));

        print(genEqualsStrings(MAX_SUM / 2, 2));
        print(genEqualsStrings(1000, 100));
        print(genEqualsStrings(1000, 200));
        print(genEqualsStrings(10000, 10));

        print(noIntersection(100, 200, MAX_SUM / 600));//pref, suf, ans_cnt, total_cnt
        print(merge(noIntersection(5000 - 3, 5000 - 8, 10), noIntersection(5000 - 4, 5000 - 6, 10)));//pref, suf, ans_cnt, total_cnt
        print(genRandomStringsByArray(noIntersection(777, 333, 100)));
        print(genRandomStringsByArray(noIntersection(13, 15, 5000)));

        print(intersectStrings(100, 100, 100));
        print(genRandomStringsByArray(intersectStrings(100, 100, 500)));
        print(genRandomStringsByArray(intersectStrings(1000, 1000, 50)));
        print(merge(noIntersection(800, 950, 60), intersectStrings(1000, 1000, 50)));

        print(merge(intersectStrings(100, 100, 100), intersectStrings(100, 200, 100), noIntersection(90, 200, 80), noIntersection(90, 70, 100)));
        print(merge(intersectStrings(200, 150, 100), intersectStrings(90, 200, 100), intersectStrings(90, 70, 100)));


        print(prefixSuffixAntiTernary(100, 50, 50, 1));//19 n, prefix, suffix, countExtremums
        print(prefixSuffixAntiTernary(1000, 50, 50, 45));
        print(prefixSuffixAntiTernary(20, 5000, 5000, 15));
        print(prefixSuffixAntiTernary(100, 1000, 1000, 70));
        print(prefixSuffixAntiTernary(10, 9000, 9000, 8));

        print(prefixSuffixAntiTernary(400, 200, 200, 100));
        print(prefixSuffixAntiTernary(800, 89, 98, 50));
        print(prefixSuffixAntiTernary(800, 89, 98, 3));
        print(merge(
                prefixSuffixAntiTernary(200, 89, 98, 20),
                prefixSuffixAntiTernary(200, 50, 130, 10),
                prefixSuffixAntiTernary(100, 170, 100, 10),
                prefixSuffixAntiTernary(200, 70, 85, 5),
                prefixSuffixAntiTernary(200, 89, 98, 8)));

        print(antiTernary2(20, 150, 150, 20));//27
        print(antiTernary2(8, 500, 500, 30));
        print(antiTernary2(40, 90, 70, 50));
        print(antiTernary2(20, 1000, 1000, 100));
        print(antiTernary2(10, 500, 500, 400));
        print(antiTernary2(5, 500, 500, 500));
        print(antiTernary2(1, 10000, 10000, 100));//33
        print(antiTernary2(2900, 8, 10, 7));//34
        print(antiTernary2(6000, 3, 5, 3));//35

        print(merge(prefixSuffixAntiTernary(300, 100, 80, 20), prefixSuffixAntiTernary(300, 91, 100, 20), prefixSuffixAntiTernary(300, 85, 70, 20)));

        int sq = (int)Math.sqrt(n * 2.0) - 1;
        print(genSimpleTrie(sq, true));//39
        print(genSimpleTrie(sq, false));//40
        print(genSimpleTrie2(MAX_SUM / 2, 1, 'a', 'y', 'z', 'z'));//41
        print(genSimpleTrie2(MAX_SUM / 4, 2, 'a', 'a', 'b', 'z'));//42
        print(genSimpleTrie2(MAX_SUM / 20, 10, 'a', 'a', 'b', 'z'));//43
        print(genSimpleTrie2(MAX_SUM / 3, 2, 'a', 'z', 'a', 'z'));//44
        print(genSimpleTrie2(MAX_SUM / 10, 5, 'z', 'z', 'a', 'y'));//45
        print(genSimpleTrie2(MAX_SUM / 4, 2, 'n', 'n', 'a', 'z'));//46
    }

    private String[] antiTernary2(int n, int prefMax, int sufMax, int countExtremums) {
        int[] prefixes = genDecreasingSeq(prefMax, countExtremums);
        int[] suffixes = genDecreasingSeq(sufMax, countExtremums);
        List<String> ret = new ArrayList<>();

        int maxVal = n * prefMax * sufMax;
        int st = countExtremums;
        int sm1 = 0;
        for (int i = 0; i < countExtremums; ++i) {
            int prev = (i == 0 ? 0 : maxVal / (suffixes[i - 1] * prefixes[i - 1]));
            sm1 += (maxVal / (suffixes[i] * prefixes[i]) - prev) * (suffixes[i] + prefixes[i]);
            st = i;
            if (sm1 > MAX_SUM) break;
        }

        String pref = randomString(prefMax);
        String suff = randomString(sufMax);
        for (int i = 1; i <= n; ++i)
            ret.add(randomStringFromPrefSuff(pref, suff, random.nextInt(5) + 3));
        int sm = n;
        for (int i = 1; i < st; ++i) {
            int cn = maxVal / (prefixes[i] * suffixes[i]) - sm;
            if (cn < 0)
                throw new IllegalStateException("cn < 0");

            String curPref = pref.substring(0, prefixes[i]);
            String curSuff = suff.substring(suff.length() - suffixes[i]);
            for (int j = 1; j <= cn; ++j)
                ret.add(randomStringFromPrefSuff(curPref, curSuff, random.nextInt(5) + 3));
            sm += cn;
        }
        shuffle(ret);
        return ret.toArray(new String[ret.size()]);
    }

    private String[] genOneChar(int maxSum) {
        String[] ret = new String[maxSum];
        for (int i = 0; i < maxSum; ++i)
            ret[i] = "" + randomChar();
        return ret;
    }

    private String[] genOneLong(int maxSum) {
        StringBuilder sb = new StringBuilder();
        for (int i = 0; i < maxSum; ++i) sb.append(randomChar());
        return new String[] {sb.toString()};
    }

    private char randomChar() {
        return (char)(random.nextInt(ALPHABET) + 'a');
    }

    private char randomChar(int bound) {
        return (char)(random.nextInt(bound) + 'a');
    }

    private String[] genSimpleTrie2(int maxLen, int cntLong, char l, char r, char left, char right) {
        StringBuilder sb = new StringBuilder();
        List<String> ret = new ArrayList<>();
        for (int i = 0; i < maxLen; ++i)
            sb.append((char) (randomChar(r - l + 1) + l - 'a'));

        int sm = maxLen * cntLong;
        int sq = (int)Math.sqrt((MAX_SUM - maxLen * cntLong) * 2.0) - 2;
        StringBuilder shortWords = new StringBuilder();
        for (int i = 0; i < sq; ++i) {
            shortWords.append(sb.charAt(i));
            for (char c = left; c <= right; ++c) {
                if (c == sb.charAt(i))
                    continue;
                if (sm + shortWords.length() + 1 > MAX_SUM)
                    break;
                sm += shortWords.length() + 1;
                ret.add(shortWords.toString() + c);
            }
        }

        String lgStr = sb.toString();
        ret.add(lgStr);
        for (int i = 1; i < cntLong; ++i)
            ret.add(lgStr.substring(0, lgStr.length() - 10) + randomString(5));
        return ret.toArray(new String[ret.size()]);
    }

    public String[] genSimpleTrie(int len, boolean inverse) {
        String s = "a";
        List<String> ret = new ArrayList<>();
        for (int i = 2; i <= len; ++i) {
            char c1 = randomChar();
            char c2 = randomChar();
            char tmp;
            if (inverse && c1 < c2 || !inverse && c1 > c2) {
                tmp = c1;
                c1 = c2;
                c2 = tmp;
            }
            ret.add(s + c2);
            s += c1;
        }
        return ret.toArray(new String[ret.size()]);
    }

    public String[] intersectStrings(int pref, int suff, int n) {
        int k = random.nextInt(Math.min(suff, pref) / 10) + 1;
        int t1 = random.nextInt((pref % k == 0 ? pref / k - 1 : pref / k)) + 1;
        int t2 = random.nextInt((suff % k == 0 ? suff / k - 1 : suff / k)) + 1;

        int t = Math.min(t1, t2);
        String startPrefix = randomString(pref - t1 * k);
        String endSuffix = randomString(suff - t2 * k);
        String period = randomString(k);
        List<String> ret = new ArrayList<>();
        for (int i = 1; i <= t; i++) {
            StringBuilder str = new StringBuilder();
            str.append(startPrefix);
            for (int j = 1; j <= t1 + t2 - t; ++j)
                str.append(period);
            str.append(endSuffix);
            ret.add(str.toString());
        }
        if (ret.size() < n)
            return ret.toArray(new String[ret.size()]);
        List<Integer> perm = new ArrayList<>();
        for (int i = 0; i < ret.size(); ++i)
            perm.add(i);
        shuffle(perm);
        List<String> a = new ArrayList<>();
        for (int i = 0; i < n; ++i)
            a.add(ret.get(perm.get(i)));
        return a.toArray(new String[a.size()]);
    }

    private String[] genRandomStringsByArray(String[] strings) {
        int sumLen = 0;
        for (String string : strings) sumLen += string.length();
        return merge(strings, genRandomStringsBySum(MAX_SUM - sumLen));
    }

    private String[] noIntersection(int pref, int suf, int n) {
        String prefString = randomString(pref);
        String suffixString = randomString(suf);
        String[] ret = new String[n];
        for (int i = 0; i < n; ++i)
            ret[i] = prefString + randomString(10) + suffixString;
        return ret;
    }

    private String[] genEqualsStrings(int tot, int len) {
        String str = randomString(len);
        String[] another = genRandomStringsBySum(MAX_SUM - tot * len);
        String[] ret = new String[tot + another.length];
        for (int i = 0; i < ret.length; ++i)
            if (i < tot) ret[i] = str;
            else ret[i] = another[i - tot];
        return ret;
    }

    public String[] genRandomStringsBySum(int sum) {
        List<String> ret = new ArrayList<>();
        while (sum > 0) {
            int l = random.nextInt(sum) + 1;
            ret.add(randomString(l));
            sum -= l;
        }
        shuffle(ret);
        return ret.toArray(new String[ret.size()]);
    }

    final int ITERATIONS = 100;
    public String[] prefixSuffixAntiTernary(int n, int prefMax, int sufMax, int countExtremums) {
        ++countExtremums;

        int[] sizes = null, prefixes = null, suffixes = null;
        int cnt = 0;
        int maxVal = -1;
        for (int it = 0; it < ITERATIONS; ++it) {
            int[] sizesTmp = genDecreasingSeq(n, countExtremums);
            int[] prefixesTmp = genDecreasingSeq(prefMax, countExtremums);
            int[] suffixesTmp = genDecreasingSeq(sufMax, countExtremums);
            reverse(prefixesTmp);
            reverse(suffixesTmp);
            for (int i = 1; i + 1 < countExtremums; ++i)
                if (sizesTmp[i] * prefixesTmp[i] * suffixesTmp[i] >
                        sizesTmp[i + 1] * prefixesTmp[i + 1] * suffixesTmp[i + 1] &&
                    sizesTmp[i] * prefixesTmp[i] * suffixesTmp[i] >
                        sizesTmp[i - 1] * prefixesTmp[i - 1] * suffixesTmp[i - 1] ||

                    sizesTmp[i] * prefixesTmp[i] * suffixesTmp[i] <
                        sizesTmp[i + 1] * prefixesTmp[i + 1] * suffixesTmp[i + 1] &&
                    sizesTmp[i] * prefixesTmp[i] * suffixesTmp[i] <
                        sizesTmp[i - 1] * prefixesTmp[i - 1] * suffixesTmp[i - 1])
                    ++cnt;
            if (cnt > maxVal) {
                maxVal = cnt;
                sizes = sizesTmp;
                prefixes = prefixesTmp;
                suffixes = suffixesTmp;
            }
        }


        String prefix = randomString(prefMax);
        String suffix = randomString(sufMax);
        List<String> ret = new ArrayList<>();
        for (int i = 1; i <= sizes[countExtremums - 1]; ++i)
            ret.add(randomStringFromPrefSuff(prefix, suffix, 5));
        for (int i = countExtremums - 2; i >= 0; --i) {//sizes[i] > sizes[i + 1], pref[i] < pref[i + 1]
            int len = sizes[i] - sizes[i + 1];
            int[] prefDecr = genDecreasingSeq(prefixes[i + 1] - prefixes[i], Math.min(len, prefixes[i + 1] - prefixes[i]));
            int[] suffDecr = genDecreasingSeq(suffixes[i + 1] - suffixes[i], Math.min(len, suffixes[i + 1] - suffixes[i]));
            if (prefDecr.length != len) prefDecr = repeatLastElement(prefDecr, len);
            if (suffDecr.length != len) suffDecr = repeatLastElement(suffDecr, len);
            for (int j = 0; j < prefDecr.length; ++j) {
                prefDecr[j] += prefixes[i];
                suffDecr[j] += suffixes[i];
            }

            for (int j = 0; j < prefDecr.length; ++j)
                ret.add(randomStringFromPrefSuff(
                        prefix.substring(0, prefDecr[j]),
                        suffix.substring(suffix.length() - suffDecr[j]), 5));
        }
        shuffle(ret);
        return ret.toArray(new String[ret.size()]);
    }

    private int[] repeatLastElement(int[] suffDecr, int len) {
        int[] p = new int[len];
        System.arraycopy(suffDecr, 0, p, 0, suffDecr.length);
        for (int j = 0; j < len - suffDecr.length; ++j)
            p[j + suffDecr.length] = suffDecr[suffDecr.length - 1];
        return p;
    }

    private String randomString(int len) {
        StringBuilder builder = new StringBuilder();
        for (int i = 0; i < len; ++i)
            builder.append(randomChar());
        return builder.toString();
    }


    private String randomStringFromPrefSuff(String pref, String suff, int bad) {
        int b = random.nextInt(bad) + 1;
        return pref + randomString(b) + suff;
    }

    private int[] reverse(int[] array) {
        for(int i = 0; i < array.length / 2; i++)
        {
            int temp = array[i];
            array[i] = array[array.length - i - 1];
            array[array.length - i - 1] = temp;
        }
        return array;
    }

    private int[] genDecreasingSeq(int maxVal, int countExtremums) {
        if (maxVal < countExtremums)
            throw new IllegalArgumentException("maxVal = " + maxVal + ", countExtremums = " + countExtremums);
        if (maxVal < 0)
            throw new IllegalArgumentException("maxVal < 0");
        if (countExtremums <= 0)
            throw new IllegalArgumentException("countExtremums <= 0");

        int[] ret = new int[countExtremums];
        ret[0] = maxVal;
        List<Integer> perm = new ArrayList<>(maxVal);
        for (int i = 1; i < maxVal; ++i)
            perm.add(i);
        shuffle(perm);
        List<Integer> prefix = perm.subList(0, countExtremums - 1);
        Collections.sort(prefix);
        Collections.reverse(prefix);
        for (int i = 1; i < countExtremums; ++i)
            ret[i] = prefix.get(i - 1);
        return ret;
    }

    public List<?> shuffle(List<?> list) {
        Collections.shuffle(list, random);
        return list;
    }

    public static void main(String[] args) throws IOException {
        new TestGen().run();
    }
}
