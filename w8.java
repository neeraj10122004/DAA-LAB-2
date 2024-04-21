import java.util.*;

class node{
    int data;
    char c;
    node left,right;
    node(int data,char c,node left,node right){
        this.data=data;
        this.c=c;
        this.left=left;
        this.right=right;
    }
}

class MyComparator implements Comparator<node>{
    public int compare(node x,node y){
        return x.data-y.data;
    }
}

public class w8 {
    public static void printcode(node root,String s){
        if(root.left==null && root.right==null && Character.isLetter(root.c)){
            System.out.println(root.c+":"+s);
            return ;
        }
        printcode(root.left,s+"0");
        printcode(root.right,s+"1");
    }
    public static void main(String[] args){
        Scanner a = new Scanner(System.in);
        int n;
        System.out.println("enter the number of characters");
        n=a.nextInt();
        Character[] carray=new Character[n];
        Integer[] iarray=new Integer[n];
        System.out.println("enter characters and frequencies");
        for(int i=0;i<n;i++){
            carray[i]=a.next().charAt(0);
            iarray[i]=a.nextInt();
        }
        PriorityQueue<node> pq = new PriorityQueue<node>(new MyComparator());
        node root = null;
        for(int i=0;i<n;i++){
            node nn = new node(iarray[i],carray[i],null,null);
            pq.add(nn);
        }
        while(pq.size()>1){
            node x = pq.peek();
            pq.poll();
            node y = pq.peek();
            pq.poll();
            node nn = new node(x.data+y.data,'-',x,y);
            root=nn;
            pq.add(nn);
        }
        printcode(root,"");
    }
}
