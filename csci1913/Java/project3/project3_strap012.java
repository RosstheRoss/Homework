//package used to bundle with Words class
package project3;
class AnagramTree {
    private TreeNode head;
    private class TreeNode {
        private byte[] summary;
        private WordNode words;
        private TreeNode left, right;
        private TreeNode(String word, byte[] summary) {
            words = new WordNode(word, null);
            this.summary = summary;
            left = null; right = null;
        }
    }

    private class WordNode {
        private String word;
        private WordNode next;
        private WordNode(String word, WordNode next) {
            this.word = word;
            this.next = next;
        }
    }

    public AnagramTree() {
        head = new TreeNode(null, null);
    }

    public void add (String word) {
        byte [] newSumm = new byte [26];
        newSumm = stringToSummary(word);
        TreeNode top = head, bottom = top.right;
        boolean goLeft = false, addWord = false;
        while (bottom != null) {
            int comp = compareSummaries(bottom.summary, newSumm);
            if (comp > 0) {        // left is greater than right, go left
                top = bottom;
                goLeft = true;
                bottom = bottom.left;
            } else if (comp < 0) { // right is greater, go right
                top = bottom;
                goLeft = false;
                bottom = bottom.right;
            } else {
                WordNode badNode = bottom.words;
                boolean wordExists = false;
                while (badNode != null) {
                //Traverse word list to find already added entries
                    if (badNode.word.equals(word)) {
                        wordExists = true;
                        break;
                    }    
                    badNode = badNode.next; 
                }
                if (!wordExists)
                    bottom.words = new WordNode(word, bottom.words);
                addWord = true;
                break;
            }
        }   
        if (!addWord) {     //Word was not added, add it
            if (goLeft)
                top.left = new TreeNode(word, newSumm);
            else
                top.right = new TreeNode(word, newSumm);
        }
    } 

    public void anagrams() {
        findAnagrams(head.right);
    }

    private void findAnagrams(TreeNode subtree) {
        if (subtree != null) {
            if (subtree.words.next != null) {
                System.out.println();
                while (subtree.words != null) {
                    System.out.print(subtree.words.word);
                    System.out.print(" ");
                    subtree.words = subtree.words.next;
                }
            }
            findAnagrams(subtree.left);
            findAnagrams(subtree.right);
        }
    }
    
    private int compareSummaries(byte[] left, byte[] right) {
        for (int i = 0; i <= 25; i++) {
            if (left[i] != right[i]) {
                return left[i] - right[i];
            }
        }
        //Summaries are identical here
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
        anagrams.anagrams();
        //Print extra line for neatness
        System.out.println();
    }
}