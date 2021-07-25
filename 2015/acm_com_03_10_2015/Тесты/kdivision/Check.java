import ru.ifmo.testlib.Checker;
import ru.ifmo.testlib.InStream;
import ru.ifmo.testlib.Outcome;
import static ru.ifmo.testlib.Outcome.Type.*;

public class Check implements Checker {
    public Outcome outcome(Outcome.Type type, final String format) {
        return new Outcome(type, format);
    }

    public Outcome test(InStream inf, InStream ouf, InStream ans) {
        int nAns = ans.nextInt();
        int nOuf = ouf.nextInt();
        if (nAns != nOuf) {
            return outcome(WA, String.format("expected %d numbers, found %d", nAns, nOuf));
        }
        for (int i = 0; i < nAns; i++) {
            int x = ans.nextInt();
            int y = ouf.nextInt();
            if (x != y) {
                return outcome(WA, String.format("number %d: expected %d, found %d", i + 1, x, y));
            }
        }
        return outcome(OK, String.format("%d numbers", nAns));
    }
}
