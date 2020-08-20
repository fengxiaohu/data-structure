import java.util.LinkedList;
import java.util.Queue;
 class Node
{
    int data;
    Node left,right;
    boolean isThread;
    public Node(int item)
    {
        this.data = item;
        this.left = null;
        this.right = null;
    }
}
public class BinaryTree2ThreadTree {

    Node root;
    // put nodes in inorder into queue
    void populateQueue(Node node,Queue<Node> q)
    {
        if(node == null)
        {
            return;
        }
        if(node.left!=null)
        {
            populateQueue(node.left, q);
        }
        q.add(node);
        if(node.right!=null)
        {
            populateQueue(node.right, q);
        }
    }
    void createThreadUtil(Node node,Queue<Node> q)
    {
        if(node==null)
        {
            return;
        }
        if(node.left !=null)
        {
            createThreadUtil(node.left, q);
            q.remove();
        }
        if(node.right!=null)
        {
            createThreadUtil(node.right, q);
        }
        else if(node.right==null)
        {
            q.remove();
            node.right = q.peek();
            node.isThread = true;
        }
    }
    void createThreaded(Node node)
    {
        Queue<Node> q = new LinkedList<Node>();
        populateQueue(node, q);
        createThreadUtil(node, q);
    }
    Node leftMost(Node node)
    {
        while(node!=null && node.left != null)
        {
            node = node.left;
        }
        return node;
    }
    void inorder(Node node)
    {
        if(node == null)
        {
            return;
        }
        Node cur = leftMost(node);
        while(cur!=null)
        {
            System.out.print(" " + cur.data + " "); 
            if(cur.isThread)
            {
                cur = cur.right;
            }
            else
            {
                cur = leftMost(cur.right);
            }
        }
        
        
    }
    public static void main(String[] args)
    {
        BinaryTree2ThreadTree tree = new BinaryTree2ThreadTree(); 
        tree.root = new Node(1); 
        tree.root.left = new Node(2); 
        tree.root.right = new Node(3); 
  
        tree.root.left.left = new Node(4); 
        tree.root.left.right = new Node(5); 
        tree.root.right.left = new Node(6); 
        tree.root.right.right = new Node(7); 
  
        tree.createThreaded(tree.root); 
        System.out.println("Inorder traversal of created threaded tree"); 
        tree.inorder(tree.root);    
    }
}
