//  SORT. Sort a linear singly-linked list of INTs.

class Sort {

    // NODE. A node in a linear singly linked list of INTs.

    private static class Node {
        private int number; // The INT in the node, duh.
        private Node next; // The NODE that follows this one, or NULL.

        // Constructor. Initialize a new NODE with NUMBER and NEXT.

        private Node(int number, Node next) {
            this.number = number;
            this.next = next;
        }
    }

    // MAKE NODES. Return a list of NODEs that contains INTs from NUMBERS in order
    // of their appearance.

    private static Node makeNodes(int... numbers) {
        if (numbers.length > 0) {
            Node first = new Node(numbers[0], null);
            Node last = first;
            for (int index = 1; index < numbers.length; index += 1) {
                last.next = new Node(numbers[index], null);
                last = last.next;
            }
            return first;
        } else {
            return null;
        }
    }

    // WRITE NODES. Write the INTs from a list of NODEs in paired square brackets,
    // separated by commas, with a newline at the end.

    private static void writeNodes(Node nodes) {
        System.out.print('[');
        if (nodes != null) {
            System.out.print(nodes.number);
            nodes = nodes.next;
            while (nodes != null) {
                System.out.print(", ");
                System.out.print(nodes.number);
                nodes = nodes.next;
            }
        }
        System.out.println(']');
    }

    // SORT NODES. Sort UNSORTED, a list of NODEs, into nondecreasing order of its
    // NUMBER slots, without making new NODEs.

    private static Node sortNodes(Node unsorted) {
        Node left = null, right = null;
        if (unsorted==null || unsorted.next==null) {
        //unsorted is either empty or of length 1
            return unsorted;
        } 
        //Halving phase
        else {
            int step = 1;
            while (unsorted != null) {
                Node next = unsorted.next;
                if (step % 2 == 0) {    //Even case
                    //Pops out first value and puts into Right
                    unsorted.next = right;
                    right = unsorted;
                } else {                //Odd case
                    // Pops out first value and puts into Left
                    unsorted.next = left;
                    left = unsorted; 
                }
                step++;
                unsorted = next;
            }
        }
        //Sorting (recursive) Phase
        left = sortNodes(left);
        right = sortNodes(right);

        //Combining phase, variables needed for Q funs
        Node end = null, temp = null, sorted = null;
        //Special Initial Case
        if (left.number < right.number) {
            sorted = left; 
            end = left;
            temp = left.next;
            left = temp;
            end.next = null;
        } else {
            temp = right.next;
            sorted = right;
            end = right;
            right = temp;
            end.next = null;
        }
        //Loop for rearranging pointers. Easily the hardest part of the assignment
        while (left != null && right != null) {
            if (left.number < right.number) {
                end.next = left;
                end = left;
                temp = left.next;
                end.next = null;
                left = temp;
            } else { //Right is smaller or equal, put it at the end.
                end.next = right;
                end = right;
                temp = right.next;
                end.next = null;
                right = temp;
            }
        } 

        if (left == null) {
            end.next=right;
        } else if (right == null) {
            end.next=left;
        }
        return sorted;
    }

    // MAIN. Run some examples. The comments show what must be printed.

    public static void main(String[] args) {
        writeNodes(sortNodes(makeNodes())); // []
        writeNodes(sortNodes(makeNodes(1))); // [1]
        writeNodes(sortNodes(makeNodes(1, 2))); // [1, 2]
        writeNodes(sortNodes(makeNodes(2, 1))); // [1, 2]

        writeNodes(sortNodes(makeNodes(1, 2, 3, 4, 5, 6, 7, 8, 9)));
        // [1, 2, 3, 4, 5, 6, 7, 8, 9]

        writeNodes(sortNodes(makeNodes(9, 8, 7, 6, 5, 4, 3, 2, 1)));
        // [1, 2, 3, 4, 5, 6, 7, 8, 9]

        writeNodes(sortNodes(makeNodes(3, 1, 4, 5, 9, 2, 6, 8, 7)));
        // [1, 2, 3, 4, 5, 6, 7, 8, 9]

        writeNodes(sortNodes(makeNodes(5,5,5,1,2,3,6,90,12,1,14)));
        // [1, 1, 2, 3, 5, 5, 5, 6, 12, 14, 90]

        writeNodes(sortNodes(makeNodes(1, 100, 6, 100, 1, 15, 10000, 12, 2, 0, -15)));
        // [-15, 0, 1, 1, 2, 6, 12, 15, 100, 100, 10000]
    }
}