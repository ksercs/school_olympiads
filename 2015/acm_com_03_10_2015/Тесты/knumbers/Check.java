import ru.ifmo.testlib.Checker;
import ru.ifmo.testlib.InStream;
import ru.ifmo.testlib.Outcome;
import static ru.ifmo.testlib.Outcome.Type.*;

import java.util.ArrayList;
import java.util.Arrays;

public class Check implements Checker {
    public Outcome outcome(Outcome.Type type, final String format, final Object... args) {
        return new Outcome(type, String.format(format, args));
    }

    int findDifference(String a, String b) {
        for (int i = 0; i < a.length(); i++) {
            if (a.charAt(i) != b.charAt(i)) {
                return i;
            }
        }   
        return -1;  
    }

    public Outcome test(InStream inf, InStream ouf, InStream ans) {
        String jAns = ans.nextLine();
        String pAns = ouf.nextLine();
        if (jAns.length() != pAns.length()) {
            return outcome(WA, "Wrong answer length - expected %d, found %d", jAns.length(), pAns.length());
        }
        int wrongSymbolIndex = findDifference(jAns, pAns);
        if (!jAns.equals(pAns)) {
            return outcome(WA, String.format("%d symbol is wrong - expected %c, found %c", wrongSymbolIndex + 1, jAns.charAt(wrongSymbolIndex), pAns.charAt(wrongSymbolIndex)));
        }
        return outcome(OK, "Corrent answer");
    }
}
