class RunnyStack<Base> {
    private int numRuns;
    private int numDepth;
    private Run top;
    //Constructors
    private class Run {
        private Base base;
        private int l;
        private Run next;
        private Run(Base base, Run next) {
            this.base=base;
            this.l=l+1;
            this.next=next;
        }
    }
    public RunnyStack() {
        top=null;
    }
    //Methods
    private boolean isEqual(Run b1, Base b2){
        if (b1 == null || b2 == null) {
            return b1 == b2;
        } else {
            return b1.base.equals(b2);
        }
    }
    public boolean isEmpty() {
        return top==null;
    }
    public int depth() {
        return numDepth;
    }
    public Base peek() {
        if (isEmpty()) {
            throw new IllegalStateException();
        } else {
            return top.base;
        }
    }
    public void pop() {
        if (isEmpty()) {
            throw new IllegalStateException();
        } else {
            top.l--;
            numDepth--;
            if (top.l == 0) {
                top=top.next;
                numRuns--;
            }
        }
    }
    public void push(Base base) {
        numDepth++;
        if (isEqual(top, base)) {
            top.l++;
        } else {
            numRuns++;
            top=new Run(base, top);
        }
    }
    public int runs() {
        return numRuns;
    }
   
}

//
//  Tests for CSci 1913 Lab 8
//  James Moen
//  20 Mar 17
//
//  The TRY-CATCH statements catch exceptions thrown by RUNNY STACK's methods,
//  so that the program can continue to run even if a method fails. We still
//  haven't talked about TRY-CATCH'es in the lectures yet.
//
//  Most tests have comments that show what they should print, and how many
//  points they are worth, for a total of 40 points.
//
//  Camembert is a soft French cheese. It may be runny. It can be stacked.
//

class Camembert {
    public static void main(String[] args) {
        RunnyStack<String> s = new RunnyStack<String>();

        System.out.println(s.isEmpty()); // true 1 point
        System.out.println(s.depth()); // 0 1 point
        System.out.println(s.runs()); // 0 1 point

        try {
            s.pop();
        } catch (IllegalStateException ignore) {
            System.out.println("No pop"); // No pop 1 point
        }

        try {
            System.out.println(s.peek());
        } catch (IllegalStateException ignore) {
            System.out.println("No peek"); // No peek 1 point
        }

        s.push("A");
        System.out.println(s.peek()); // A 1 point
        System.out.println(s.depth()); // 1 1 point
        System.out.println(s.runs()); // 1 1 point

        System.out.println(s.isEmpty()); // false 1 point

        s.push("B");
        System.out.println(s.peek()); // B 1 point
        System.out.println(s.depth()); // 2 1 point
        System.out.println(s.runs()); // 2 1 point

        s.push("B");
        System.out.println(s.peek()); // B 1 point
        System.out.println(s.depth()); // 3 1 point
        System.out.println(s.runs()); // 2 1 point

        s.push("B");
        System.out.println(s.peek()); // B 1 point
        System.out.println(s.depth()); // 4 1 point
        System.out.println(s.runs()); // 2 1 point

        s.push("C");
        System.out.println(s.peek()); // C 1 point
        System.out.println(s.depth()); // 5 1 point
        System.out.println(s.runs()); // 3 1 point

        s.push("C");
        System.out.println(s.peek()); // C 1 point
        System.out.println(s.depth()); // 6 1 point
        System.out.println(s.runs()); // 3 1 point

        s.pop();
        System.out.println(s.peek()); // C 1 point
        System.out.println(s.depth()); // 5 1 point
        System.out.println(s.runs()); // 3 1 point

        s.pop();
        System.out.println(s.peek()); // B 1 point
        System.out.println(s.depth()); // 4 1 point
        System.out.println(s.runs()); // 2 1 point

        s.pop();
        System.out.println(s.peek()); // B 1 point
        System.out.println(s.depth()); // 3 1 point
        System.out.println(s.runs()); // 2 1 point

        s.pop();
        s.pop();
        System.out.println(s.peek()); // A 1 point
        System.out.println(s.depth()); // 1 1 point
        System.out.println(s.runs()); // 1 1 point

        s.pop();
        System.out.println(s.isEmpty()); // true 1 point
        System.out.println(s.depth()); // 0 1 point
        System.out.println(s.runs()); // 0 1 point

        try {
            System.out.println(s.peek());
        } catch (IllegalStateException ignore) {
            System.out.println("No peek"); // No peek 1 point
        }
    }
}
