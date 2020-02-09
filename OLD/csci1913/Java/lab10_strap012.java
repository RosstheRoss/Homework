class AssociationList<Key, Value> {
    private class Node {
        private Key key;
        private Value value;
        private Node next;
        private Node(Key k, Value v, Node n) {
            key=k; value=v; next=n;
        }
    }
    private Node head;
    public AssociationList() {
        head = new Node(null, null, null);
    }
    public void delete(Key key) {
        Node left = head;
        Node right = head.next;
        while (right!=null) {
            if (isEqual(right.key, key)) {
                left.next=right.next;
                break;
            } else {
                left=right; right=right.next;
            }
        }

    }
    public Value get(Key key) {
        Node where=head.next;
        while (where!=null) {
            if (isEqual(where.key,key)) {
                return where.value;
            } else {
                where=where.next;
            }
        } //No matching key found
        throw new IllegalArgumentException();
    }
    private boolean isEqual(Key leftKey, Key rightKey) {
        if (leftKey == null || rightKey == null) {
            return leftKey == rightKey;
        } else {
            return leftKey.equals(rightKey);
        }
    }
    public boolean isIn(Key key) {
        Node where = head.next;
        while (where != null) {
            if (isEqual(where.key, key)) {
                return true;
            } else {
                where = where.next;
            }
        } // No matching key found
        return false;
    }
    public void put(Key key, Value value) {
        Node where=head.next;
        boolean found=false;
        while (where!=null){
            if(isEqual(key, where.key)) {
                where.value=value;
                found=true;
                break;
            } else {
                where=where.next;
            }
        } //End of while
        if (!found) {
            Node temp=head.next;
            head.next= new Node(key, value, temp);
        }
    }
}

//
//  Tests for CSci 1913 Lab 10
//  James Moen
//  08 Apr 19
//
//  The TRY-CATCH statements catch exceptions thrown by ASSOCIATION LIST's
//  methods, so that the program can continue to run even if a method fails.
//
//  Each test has a comment that shows what it should print and how many points
//  it is worth, for a total of 40 points.

//  HOGWARTS. The Hogwarts dating service.

class Hogwarts {

    // MAIN. Make an instance of ASSOCIATION LIST and test it.

    public static void main(String[] args) {
        AssociationList<String, String> list = new AssociationList<String, String>();

        System.out.println(list.isIn(null)); // false 2 points.

        try {
            System.out.println(list.get(null));
        } catch (IllegalArgumentException ignore) {
            System.out.println("No null"); // No null 2 points.
        }

        list.put(null, "Wormtail");
        list.put("Ron", "Lavender");
        list.put("Voldemort", null);
        list.put("Dean", "Ginny");

        System.out.println(list.isIn("Dean")); // true 2 points.
        System.out.println(list.isIn("Ginny")); // false 2 points.
        System.out.println(list.isIn("Ron")); // true 2 points.
        System.out.println(list.isIn("Voldemort")); // true 2 points.
        System.out.println(list.isIn(null)); // true 2 points.
        System.out.println(list.isIn("Joanne")); // false 2 points.

        System.out.println(list.get("Ron")); // Lavender 2 points.
        System.out.println(list.get("Dean")); // Ginny 2 points.
        System.out.println(list.get("Voldemort")); // null 2 points.
        System.out.println(list.get(null)); // Wormtail 2 points.

        try {
            System.out.println(list.get("Joanne"));
        } catch (IllegalArgumentException ignore) {
            System.out.println("No Joanne"); // No Joanne 2 points.
        }

        list.delete(null);

        System.out.println(list.isIn(null)); // false 2 points.

        list.put(null, null);
        list.put("Harry", "Ginny");
        list.put("Ron", "Hermione");

        System.out.println(list.isIn(null)); // true 2 points.
        System.out.println(list.get(null)); // null 2 points.
        System.out.println(list.get("Harry")); // Ginny 2 points.
        System.out.println(list.get("Dean")); // Ginny 2 points.
        System.out.println(list.get("Ron")); // Hermione 2 points.

        list.delete("Dean");

        try {
            System.out.println(list.get("Dean"));
        } catch (IllegalArgumentException ignore) {
            System.out.println("No Dean"); // No Dean 2 points.
        }
    }
}