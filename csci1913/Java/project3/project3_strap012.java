package project3;

class AnagramTree {
    private TreeNode head;
    private class TreeNode {
        private byte[] summary;
        private WordNode words;
        private TreeNode left, right;
        private TreeNode(String word) {
            summary = stringToSummary(word);
            // words = new WordNode(word);
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
        head = new TreeNode("e");
    }

    public void add (String word) {

    }

    public void anagrams() {

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
            temp[i] = (byte) (word.charAt(i) - ('a' + i));
        }
        return temp;
    }
}