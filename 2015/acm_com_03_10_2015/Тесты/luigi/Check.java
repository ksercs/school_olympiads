/**
 * Created by Shovkoplias on 01.10.2015.
 */
import ru.ifmo.testlib.Checker;
import ru.ifmo.testlib.InStream;
import ru.ifmo.testlib.Outcome;

public class Check implements Checker {

    @Override
    public Outcome test(InStream inf, InStream ouf, InStream ans) {
        int A = inf.nextInt();
        int B = inf.nextInt();
        int C = inf.nextInt();
        int D = inf.nextInt();
        int k = inf.nextInt();

        //Jury answer
        int jX = ans.nextInt();
        int jY;
        if (jX == -1) {
            jY = -1;
        } else {
            jY = ans.nextInt();
        }

        //Contestant answer
        int cX = ouf.nextInt();
        int cY;
        if (cX == -1) {
            cY = -1;
        } else {
            cY = ouf.nextInt();
        }

        //if answer doesn't exist
        if (cX == -1 && jX == -1) {
            return new Outcome(Outcome.Type.OK, String.format("-1"));
        }

        //else
        if (cX == -1) {
            return new Outcome(Outcome.Type.WA, String.format("Contestant doesn't find answer \"%d %d\"", jX, jY));
        }

        if (cX < A || cX > B) {
            return new Outcome(Outcome.Type.WA, String.format("x = %d not in [%d; %d]", cX, A, B));
        }

        if (cY < C || cY > D) {
            return new Outcome(Outcome.Type.WA, String.format("y = %d not in [%d; %d]", cY, C, D));
        }

        if ((cY + cX) % k != 0) {
            return new Outcome(Outcome.Type.WA, String.format("(%d + %d) mod %d != 0", cX, cY, k));
        }

        if (jX == -1) {
            return new Outcome(Outcome.Type.FAIL, String.format("Jury doesn't find answer \"%d %d\"", cX, cY));
        }

        if (jX + jY < cX + cY) {
            return new Outcome(Outcome.Type.FAIL,
                    String.format("Jury's answer \"%d %d\" worse than \"%d %d\"", jX, jY, cX, cY));
        }

        if (jX + jY > cX + cY) {
            return new Outcome(Outcome.Type.WA,
                    String.format("Jury's answer \"%d %d\" better than \"%d %d\"", jX, jY, cX, cY));
        }

        return new Outcome(Outcome.Type.OK, String.format("%d %d", cX, cY));
    }


}
