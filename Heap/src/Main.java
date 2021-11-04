import java.util.LinkedList;
import java.util.Queue;

public class Main {

    public static void main(String args[]) throws Exception {
        MaxHeap maxHeap = new MaxHeap();
        maxHeap.push(9);
        maxHeap.push(3);
        maxHeap.push(1);
        maxHeap.push(24);

        for(int i=0;i<4;i++){
            System.out.println(maxHeap.pop());
        }


    }

    static class Node {
        Node parent = null;
        Node left = null;
        Node right = null;
        int val;

        public Node(int val) {
            this.val = val;
        }
    }

    static class MaxHeap {
        Node root = null;

        public void push(int value) {
            // Heap 자료구조란
            Node node = new Node(value);

            if (root == null) {
                root = node;
            } else {
                Queue<Node> queue = new LinkedList<>();
                queue.add(root);

                //데이터 맨끝 삽입
                while (!queue.isEmpty()) {
                    Node v = queue.poll();

                    if (v.left == null) {
                        v.left = node;
                        node.parent = v;
                        break;
                    } else {
                        queue.add(v.left);
                    }

                    if (v.right == null) {
                        v.right = node;
                        node.parent = v;
                        break;
                    } else {
                        queue.add(v.right);
                    }
                }


                //부모 찾아서 부모랑 교환
                Node temp = node;

                while (temp.parent != null) {
                    if (temp.parent.val < temp.val) {
                        swap(temp.parent, temp);
                        temp = temp.parent;
                    } else {
                        break;
                    }
                }
            }
        }

        private void swap(Node A, Node B) {
            int temp = A.val;
            A.val = B.val;
            B.val = temp;
        }

        public int pop() {
            int ret = 0;

            if (root == null) {
                return -1;
            }
            else {
                ret = root.val;

                Queue<Node> queue = new LinkedList<>();

                queue.add(root);
                Node temp = null;

                while (!queue.isEmpty()) {
                    Node v = queue.poll();
                    temp = v;
                    if (v.left != null) {
                        queue.add(v.left);
                    }
                    if (v.right != null) {
                        queue.add(v.right);
                    }
                }

                swap(root, temp);

                if(temp==root){
                    root=null;
                }
                else{
                    Node parent = temp.parent;

                    if(parent.right!=null){
                        parent.right=null;
                    }
                    else{
                        parent.left=null;
                    }

                    temp=root;

                    while(temp.left!=null || temp.right!=null){
                        if(temp.left!=null && temp.right!=null){
                            if(temp.left.val<temp.right.val){
                                if(temp.val<temp.right.val){
                                    swap(temp,temp.right);
                                    temp=temp.right;
                                }
                                else{
                                    break;
                                }
                            }
                            else{
                                if(temp.val<temp.left.val){
                                    swap(temp,temp.left);
                                    temp=temp.left;
                                }
                                else{
                                    break;
                                }
                            }
                        }
                        else if(temp.left!=null){
                            if(temp.val<temp.left.val){
                                swap(temp,temp.left);
                                temp=temp.left;
                            }
                            else{
                                break;
                            }
                        }
                        else if(temp.right!=null){
                            if(temp.val<temp.right.val){
                                swap(temp,temp.right);
                                temp=temp.right;
                            }
                            else{
                                break;
                            }
                        }
                    }
                }



            }


            return ret;
        }


    }
}
