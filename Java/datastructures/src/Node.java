
/*
 * Node class for BST
 */
public class Node {
    public Node left;
    public Node right;
    public int data;

    public Node(int data) {
        right = left = null;
        this.data = data;
    }
}
