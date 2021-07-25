import ru.ifmo.testlib.Checker;
import ru.ifmo.testlib.InStream;
import ru.ifmo.testlib.Outcome;
import static ru.ifmo.testlib.Outcome.Type.*;

public class Check implements Checker {
    public static final double EPS = 1e-6;
    @Override
    public Outcome test(InStream inf, InStream ouf, InStream ans) {
        int n = inf.nextInt();
        int m = inf.nextInt();
        for (int i = 0; i < m; ++i) {
            double ja = ans.nextDouble();
            double pa = ouf.nextDouble();

            double relative_error = Math.abs(ja - pa) / Math.max(Math.abs(ja), 1.0);
            double absolute_error = Math.abs(ja - pa);
            double error = Math.min(relative_error, absolute_error);
            if (error > EPS)
                return new Outcome(WA, String.format("Expected t[" + i + "] %.17f, found %.17f, error = %.17f", ja, pa, error));
        }
        return new Outcome(OK, "Good job!");
    }
}
