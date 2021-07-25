import ru.ifmo.testlib.Checker;
import ru.ifmo.testlib.InStream;
import ru.ifmo.testlib.Outcome;

public class Check implements Checker {

    @Override
    public Outcome test(InStream inf, InStream ouf, InStream ans) {
        int n = inf.nextInt();
        int m = inf.nextInt();
        int k = inf.nextInt();
        String jr = ans.nextToken();
        String prt = ouf.nextToken();
        if (!jr.toLowerCase().equals(prt.toLowerCase()))
            return new Outcome(Outcome.Type.WA, "Jury and part answers are different!");
        if (jr.toLowerCase().equals("no"))
            return new Outcome(Outcome.Type.OK, "No solution!");

        ouf.nextLine();
        ans.nextLine();

        char[][] part = new char[n][m], jury = new char[n][m];
        for (int i = 0; i < n; ++i) {
            String s = ouf.nextToken();
            if (m != s.length())
                return new Outcome(Outcome.Type.PE, "Line #" + i + " contains no " + m + " elements");
            for (int j = 0; j < m; ++j)
                part[i][j] = s.charAt(j);
        }

        for (int i = 0; i < n; ++i) {
            String s = ans.nextToken();
            if (m != s.length())
                return new Outcome(Outcome.Type.PE, "Line #" + i + " contains no " + m + " elements");
            for (int j = 0; j < m; ++j)
                jury[i][j] = s.charAt(j);
        }

        if (part[0][0] == 'C' || part[n - 1][m - 1] == 'C')
            return new Outcome(Outcome.Type.WA, "Start or finish is 'C'");
        int[][] dp = new int[n][m];
        int cntPart = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j) {
                int c = (part[i][j] == 'C' ? 1 : 0);
                cntPart += c;
                dp[i][j] = i + j;
                if (i > 0) dp[i][j] = Math.min(dp[i][j], dp[i - 1][j] + c);
                if (j > 0) dp[i][j] = Math.min(dp[i][j], dp[i][j - 1] + c);
            }
        if (dp[n - 1][m - 1] < k)
            return new Outcome(Outcome.Type.WA, "There is path which contains less than k police cars");
        int cntJury = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                if (jury[i][j] == 'C') cntJury++;
        if (cntJury > cntPart)
            return new Outcome(Outcome.Type.FAIL, "Jury have more cars, than participant");
        if (cntPart > cntJury)
            return new Outcome(Outcome.Type.WA, "Participant have more cars, than jury");
        return new Outcome(Outcome.Type.OK, "Good job!");
    }
}
