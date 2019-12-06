class PriorityQueue<Base> { 
    private class Node { 
        private Base object; 
        private int rank; 
        private Node left; 
        private Node right; 
        private Node(Base object, int rank) { 
            this.object = object; 
            this.rank = rank; 
            left = null; 
            right = null; 
        } 
    }
    private Node root;              // Root node of the BST.

    public PriorityQueue() {
        root = new Node(null, -1);  // root is the lone King of Kings
      }
    public boolean isEmpty() {
        return root.right==root.left;
    }

    public Base dequeue() {
        if (isEmpty())
            throw new IllegalStateException();
        Node top = root;
        Node bottom = root.right;
        while (bottom.left != null) {
            top = bottom;
            bottom = bottom.left;
        }
        if (top.object == null)     // Special case for top being the head node
            top.right = bottom.right;    
        else
            top.left = bottom.right;
        return bottom.object;
    }

    public void enqueue(Base object, int rank) {
        if (rank < 0)               // No extra negative ranks allowed
            throw new IllegalArgumentException();
        boolean lessOrEqual = false;
        Node top = root;
        Node bottom = root.right;
        while (bottom != null) {
            top = bottom;
            if (rank <= bottom.rank) {
                bottom = bottom.left;
                lessOrEqual = true;
            } else {
                bottom = bottom.right;
                lessOrEqual = false;
            }
        }
        if (lessOrEqual) {
            top.left = new Node(object, rank);
        } else {
            top.right = new Node(object, rank);
        }
    }
}
//  SNOBBERY. How the aristocracy behaves in a queue. 20 points.

class Snobbery {

    // MAIN. Queue them up.

    public static void main(String[] args) {
        PriorityQueue<String> queue = new PriorityQueue<String>();

        System.out.println(queue.isEmpty()); // true 2 points

        try {
            System.out.println(queue.dequeue());
        } catch (IllegalStateException ignore) {
            System.out.println("Blimey!"); // Blimey! 2 points
        }

        queue.enqueue("Lancelot", 5);
        queue.enqueue("Fawlty", 7);
        queue.enqueue("Elizabeth", 0);
        queue.enqueue("Charles", 1);
        queue.enqueue("Turing", 7);

        try {
            queue.enqueue("Zeus", -100);
        } catch (IllegalArgumentException ignore) {
            System.out.println("No gods!"); // No gods! 2 points
        }

        System.out.println(queue.isEmpty()); // false 2 points

        System.out.println(queue.dequeue()); // Elizabeth 2 points
        System.out.println(queue.dequeue()); // Charles 2 points
        System.out.println(queue.dequeue()); // Lancelot 2 points
        System.out.println(queue.dequeue()); // Turing 2 points
        System.out.println(queue.dequeue()); // Fawlty 2 points

        // It's OK if Fawlty comes out before Turing, but both must come out last.

        System.out.println(queue.isEmpty()); // true 2 points.
    }

}
