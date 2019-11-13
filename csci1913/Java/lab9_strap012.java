import java.util.Iterator;

//  ARRAY QUEUE. A fixed length queue implemented as a circular array.

class ArrayQueue<Base> {
    private int front; // Index of front object in BASES.
    private int rear; // Index of rear object in BASES.
    private Base[] bases; // The BASEs in the queue.

    // Constructor. Make a new empty queue that can hold SIZE - 1 elements.

    public ArrayQueue(int size) {
        if (size >= 1) {
            front = 0;
            rear = 0;
            bases = (Base[]) new Object[size];
        } else {
            throw new IllegalArgumentException("Size must be at least 1.");
        }
    }

    // DEQUEUE. Remove a BASE from the front of the queue and return it.

    public Base dequeue() {
        if (isEmpty()) {
            throw new IllegalStateException("Queue is empty.");
        } else {
            front = (front + 1) % bases.length;
            Base temp = bases[front];
            bases[front] = null;
            return temp;
        }
    }

    // ENQUEUE. Add BASE to the rear of the queue.

    public void enqueue(Base base) {
        int nextRear = (rear + 1) % bases.length;
        if (front == nextRear) {
            throw new IllegalStateException("Queue is full.");
        } else {
            rear = nextRear;
            bases[rear] = base;
        }
    }

    // IS EMPTY. Test if the queue is empty.

    public boolean isEmpty() {
        return front == rear;
    }

    // IS FULL. Test if the queue can hold no more elements.

    public boolean isFull() {
        return front == (rear + 1) % bases.length;
    }

    private class ArrayQueueIterator implements Iterator<Base> {
        private int where;
        private ArrayQueueIterator() {
            where = (front + 1) % bases.length;
        }
        public boolean hasNext() {
            return where != (rear + 1 ) % bases.length;
        }
        public Base next() {
            if (hasNext()){
                Base temp = bases[where];
                where = (where + 1) % bases.length;
                return temp;
            } else {
                throw new IllegalStateException("Queues at its end.");
            }
        }
        public void remove() {
            //Do nothing
        }
    }
    public Iterator<Base> iterator() {
        return new ArrayQueueIterator();
    }
}


// QUEUETERATOR. Test ARRAY QUEUE's iterator. It's worth 20 points.

class Queueterator {

    // MAIN. Start execution here.

    public static void main(String[] args) {

        // Make an ARRAY QUEUE and enqueue some STRINGs. It can hold at most three.

        ArrayQueue<String> queue = new ArrayQueue<String>(4);

        queue.enqueue("A");
        queue.enqueue("B");
        queue.enqueue("C");

        // Make a FIRST iterator for QUEUE and use it to visit QUEUE's elements.

        Iterator<String> first = queue.iterator();
        while (first.hasNext()) {
            System.out.println(first.next()); // A B C one per line 5 pts.
        }

        // Make sure FIRST hasn't changed QUEUE.

        System.out.println(queue.isEmpty()); // false 1 pt.
        System.out.println(queue.dequeue()); // A 1 pt.
        System.out.println(queue.dequeue()); // B 1 pt.
        System.out.println(queue.dequeue()); // C 1 pt.
        System.out.println(queue.isEmpty()); // true 1 pt.

        // Let's enqueue more three more things to QUEUE.

        queue.enqueue("X");
        queue.enqueue("Y");
        queue.enqueue("Z");

        // Now make a SECOND iterator for QUEUE. The FIRST one does not work any more,
        // because QUEUE has changed. Use SECOND to visit QUEUE's new elements.

        Iterator<String> second = queue.iterator();
        while (second.hasNext()) {
            System.out.println(second.next()); // X Y Z one per line 5 pts.
        }

        // The new iterator hasn't changed QUEUE either.

        System.out.println(queue.isEmpty()); // false 1 pt.
        System.out.println(queue.dequeue()); // X 1 pt.
        System.out.println(queue.dequeue()); // Y 1 pt.
        System.out.println(queue.dequeue()); // Z 1 pt.
        System.out.println(queue.isEmpty()); // true 1 pt.
    }
}