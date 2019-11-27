class Deque<Base> {
    private Node head;
    private class Node {
        private Base object;
        private Node left;
        private Node right;
        private Node(Base o, Node l, Node r) {
            object = o;
            left = l; right = r;
        }
    }
    public Deque() {
        head = new Node(null, null, null);
        head.left=head; head.right=head;
    }
    public void enqueueRear(Base object) {
            Node tempL = head;
            Node newNode = new Node(object, tempL.left, tempL);
            tempL.left.right = newNode;
            tempL.left = newNode;
    }
    public void enqueueFront(Base object) {
            Node tempR = head;
            Node newNode = new Node(object, tempR, tempR.right);
            tempR.right.left = newNode;
            tempR.right = newNode;
    }
    public Base dequeueRear() {
        if (isEmpty()) {
            throw new IllegalStateException();
        } else {
            Node temp = head.left;
            temp.left.right = head;
            head.left = temp.left;
            return temp.object;
        }
    }
    public Base dequeueFront() {
        if (isEmpty()) {
            throw new IllegalStateException();
        } else {
            Node temp = head.right;
            temp.right.left = head;
            head.right = temp.right;
            return temp.object;
        }
    }
    public Boolean isEmpty() {
        return head.right==head && head.left==head;
    }
}

// OBSERVATION DEQUE. Test the class DEQUE. 40 points total.
class ObservationDeque{
// MAIN. Test the DEQUE on various example arguments. 
    public static void main(String [] args) { 
        Deque<String> deque = new Deque<String>();
        System.out.println(deque.isEmpty()); // true 2 points. 
        try {
            System.out.println(deque.dequeueFront()); 
        } catch (IllegalStateException ignore) { 
            System.out.println("No dequeueFront."); // No dequeueFront. 2 points. 
        } 
        try { System.out.println(deque.dequeueRear());
        } catch (IllegalStateException ignore) { 
            System.out.println("No dequeueRear."); // No dequeueRear. 2 points. 
        }
//Enqueueing to the rear and dequeueing from the rear makes the DEQUE act
// like a stack. 
        deque.enqueueRear("A");
        deque.enqueueRear("B"); 
        deque.enqueueRear("C");

        System.out.println(deque.isEmpty()); // false 2 points.

        System.out.println(deque.dequeueRear()); // C 2 points.
        System.out.println(deque.dequeueRear()); // B 2 points.
        System.out.println(deque.dequeueRear()); // A 2 points.
        System.out.println(deque.isEmpty()); // true 2 points.
// Enqueueing to the rear and dequeueing from the front makes the DEQUE act
// like a queue.
        deque.enqueueRear("A"); 
        deque.enqueueRear("B"); 
        deque.enqueueRear("C");

        System.out.println(deque.dequeueFront()); // A 2 points.
        System.out.println(deque.dequeueFront()); // B 2 points.
        System.out.println(deque.dequeueFront()); // C 2 points.

        System.out.println(deque.isEmpty()); // true 2 points.
//Enqueueing to the front and dequeueing from the front makes the DEQUE act
//like a stack. 
        deque.enqueueFront("A"); 
        deque.enqueueFront("B");
        deque.enqueueFront("C"); 

        System.out.println(deque.dequeueFront()); // C 2 points.
        System.out.println(deque.dequeueFront()); // B 2 points.
        System.out.println(deque.dequeueFront()); // A 2 points.

        System.out.println(deque.isEmpty()); // true 2 points.

// Enqueueing to the front and dequeueing from the rear makes the DEQUE act
// like a queue.
        deque.enqueueFront("A"); 
        deque.enqueueFront("B"); 
        deque.enqueueFront("C");

        System.out.println(deque.dequeueRear()); // A 2 points.
        System.out.println(deque.dequeueRear()); // B 2 points.
        System.out.println(deque.dequeueRear()); // C 2 points.

        System.out.println(deque.isEmpty()); // true 2 points. 
    }
}