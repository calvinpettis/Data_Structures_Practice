import java.util.Random;

/*
 * Binary Search Tree in Java, like our Data structures class (I am rusty)
 */
public class BST {
    public Node root;

    public static void main(String[] args) {
        BST bst = new BST();
        Random rand = new Random();
        // for (int i = 0; i < Math.pow(2, 12); i++) {
        // bst.insert(rand.nextInt(10000000));
        // }
        // System.out.println(bst.min().data);
        // System.out.println(bst.max().data);
        // bst.print(bst.root);

        bst.insert(50);
        bst.insert(30);
        bst.insert(70);
        bst.insert(20);
        bst.insert(40);
        bst.insert(60);
        bst.insert(80);
        if (bst.pred(50) != null) {
            System.out.println("pred: " + bst.pred(50).data + "\n");
        }
        if (bst.succ(50) != null) {
            System.out.println("succ: " + bst.succ(50).data + "\n");
        }
    }

    /**
     * Create a new BST with first Node as null
     */
    public BST() {
        root = null;
    }

    /**
     * returns smallest value node in the tree, null if empty
     */
    public Node min(Node root) {
        if (root == null) {
            return null;
        }
        Node newNode = root;
        while (newNode.left != null) {
            newNode = newNode.left;
        }
        return newNode;
    }

    /**
     * returns largest value node in the tree, null if empty
     */
    public Node max(Node root) {
        if (root == null) {
            return null;
        }
        Node newNode = root;
        while (newNode.right != null) {
            newNode = newNode.right;
        }
        return newNode;
    }

    /**
     * Puts a new node in the list with the specified data
     */
    public void insert(int data) {
        root = insertHelper(new Node(data), root);
    }

    /**
     * Insert helper
     */
    private Node insertHelper(Node newNode, Node root) {
        if (root == null) {
            return newNode;
        } else {
            if (newNode.data > root.data) {
                root.right = insertHelper(newNode, root.right);
            } else {
                root.left = insertHelper(newNode, root.left);
            }
        }
        return root;
    }

    /**
     * Removes a node in the BST, will do nothing if not in the tree
     */
    public void delete(int data) {
        root = deleteHelper(data, root);
    }

    /**
     * Delete helper
     */
    private Node deleteHelper(int data, Node root) {
        if (root == null) {
            return null;
        }
        // traverse BST to find the data
        if (data > root.data) {
            root.right = deleteHelper(data, root.right);
        } else {
            root.left = deleteHelper(data, root.left);
        }
        // if node is a leaf, then just delete
        if (root.left == null && root.right == null) {
            return null;
        }
        // if it has one child y, then return that child y
        if (root.left == null && root.right != null) {
            return root.right;
        } else if (root.left != null && root.right == null) {
            return root.left;
        }
        // if there are two children, find successor and copy information over, then
        // delete successor
        if (root.right != null && root.left != null) {
            Node s = succ(root.data);
            root.data = s.data;
            root = deleteHelper(s.data, root);
        }
        return root;
    }

    /**
     * Returns the predecessor of the value (largest value smaller than the data)
     */
    public Node pred(int data) {
        Node pred = null;
        if (root != null) {
            if (data == root.data && root.left != null) {
                pred = max(root.left);
            } else {
                Node cursor = root;
                while (cursor != null) {
                    if (data > cursor.data) {
                        cursor = cursor.right;
                        pred = cursor.right;
                    } else {
                        cursor = cursor.left;
                    }
                }

            }
        }
        return pred;
    }

    /**
     * Returns the successor (smallest value larger than the data)
     */
    public Node succ(int data) {
        Node succ = null;
        if (root != null) {
            if (data == root.data && root.right != null) {
                succ = min(root.right);
            } else {
                Node cursor = root;
                while (cursor != null) {
                    if (data > cursor.data) {
                        cursor = cursor.right;
                    } else {
                        succ = cursor.left;
                        cursor = cursor.left;
                    }
                }

            }
        }
        return succ;

    }

    /**
     * in-order traversal
     */
    public void print(Node root) {
        if (root == null) {
            return;
        }
        if (root.left != null) {
            print(root.left);
        }
        System.out.println(root.data);
        if (root.right != null) {
            print(root.right);
        }
    }

    /**
     * TODO: never
     */
    private void balance() {

    }

}
