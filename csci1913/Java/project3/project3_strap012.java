package project3;
class AnagramTree {
    private TreeNode head;
    private class TreeNode {
        private byte[] summary;
        private WordNode words;
        private TreeNode left, right;
        private TreeNode(String word, byte[] summary) {
            words = new WordNode(word);
            this.summary = summary;
            left = null; right = null;
        }
    }

    private class WordNode {
        private String word;
        private WordNode next;
        private WordNode(String word) {
            this.word = word;
            next = null;
        }
    }

    public AnagramTree() {
        head = new TreeNode("e", stringToSummary("e"));
    }

    public void add (String word) {
        byte [] newSumm = new byte [26];
        newSumm = stringToSummary(word);
        TreeNode top = head, bottomR = head.right, bottomL = head.left;
        // boolean goLeft = false;
        try { while (true) {
            int comp = compareSummaries(top.summary, newSumm);
            if (comp < 0) {        // left is less than right, go left
                top = bottomL;
                // goLeft = true;
                bottomL = bottomL.left;
            } else if (comp > 0) { // right is less, go right
                top = bottomR;
                // goLeft = false;
                bottomR = bottomR.right;
            } else {
                top.words.next = new WordNode(word);
            }
        }} catch (NullPointerException ignore) {
            top = new TreeNode(word, newSumm);    
        }
    } 

    public void anagrams() {
        findAnagrams(head.left);
        findAnagrams(head.right);       //e should be lower than other words as it is e
    }

    private void findAnagrams(TreeNode subtree) {
        try { while (true) {
            findAnagrams(subtree.right);
            findAnagrams(subtree.left);
            
        } } catch (NullPointerException ignore) { /* Do nothing */}
    }

    public String toString() {
        StringBuilder builder = new StringBuilder();

        return builder.toString();
    }
    
    private int compareSummaries(byte[] left, byte[] right) {
        for (int i = 0; i < 25; i++) {
            if (left[i] != right[i]) {
                return left[i] - right[i];
            }
        }
        return 0;
    }

    private byte[] stringToSummary(String word) {
        byte[] temp = new byte[26];
        for (byte i = 0; i < word.length(); i++) {
            temp[word.charAt(i) - 'a'] += 1;
        }
        return temp;
    }
}

class Anagrammer {
    public static void main(String[] args) {
        Words words = new Words(args[0]);
        AnagramTree anagrams = new AnagramTree();
        while (words.hasNext()) {
            anagrams.add(words.next());
        }
    }
}