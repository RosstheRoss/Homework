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
        Node left=null, right=null, sorted=null;
        boolean firstSort=true;
        if (unsorted==null || unsorted.next==null) {
        //unsorted list is either empty or of length 1
            return unsorted;
        } else {
        //--HALVING PHASE--
            int oddeven = 0;
            boolean firstNodeR = true, firstNodeL = true;
            while (unsorted!=null) {
                
                if (oddeven%2==0) {
                    if (firstNodeL) {
                        left=unsorted;
                        firstNodeL=false;
                    } else {
                        unsorted=left.next;
                    }
                } else {
                    if (firstNodeR) {
                        right=unsorted;
                        firstNodeR=false;
                    } else {
                        unsorted = right.next;
                    }
                }
                oddeven++;
                unsorted=unsorted.next;
            }
        }
        //--SORTING PHASE--
        sortNodes(left); sortNodes(right);
        //--COMBINING PHASE
        while (left != null || right != null) {
            if (left.number>right.number) {
                if(firstSort) {
                    sorted = left;
                    firstSort = false;
                } else {
                    sorted.next = left;
                }
                left = left.next;
            } else {
                if (firstSort) {
                    sorted = right;
                    firstSort = false;
                } else {
                    sorted.next = right;
                }
                right = right.next;  
            }
        }
        if (left==null) {
            while (right!=null) {
                sorted.next=right;
                right=right.next;
            }
        } else if (right==null) {
            while (left!=null) {
                sorted.next=left;
                left=left.next;
            }
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
    }
}