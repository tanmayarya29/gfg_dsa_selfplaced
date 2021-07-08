// { Driver Code Starts
    import java.util.*;
    import java.io.*;
    import java.lang.*;
    
    
    class GFG
    {
        public static void main (String[] args) {
            Scanner sc = new Scanner(System.in);
            int t = sc.nextInt();
            
            int n;
            while(t-- > 0){
                n = sc.nextInt();
        
                Solution obj = new Solution();
                for(int i = 1; i <= n; i++)
                {
                    int x =sc.nextInt();
                    obj.insertHeap(x);
                    System.out.println((int)Math.floor(obj.getMedian()));
                }
            }
            
            
        }
    }
    
    // } Driver Code Ends
    
    
    class Solution
    {
        //Function to insert heap.
        public Queue<Integer> maxHeap = new PriorityQueue(Collections.reverseOrder());
        public Queue<Integer> minHeap = new PriorityQueue();
        public  void insertHeap(int num)
        {
            // add your code here
            if (maxHeap.size() == minHeap.size()) {
                minHeap.add(num);
                maxHeap.add(minHeap.remove());
            } else if (maxHeap.size() > minHeap.size()) {
                maxHeap.add(num);
                minHeap.add(maxHeap.remove());
            } // maxHeap will never be smaller size than minHeap
        }
        
        //Function to balance heaps.
        // public static void balanceHeaps()
        // {
        //   // add your code here
        // }
        
        //Function to return Median.
        public double getMedian()
        {
            // add your code here
             if (maxHeap.isEmpty()) {
                return 0;
            } else if (maxHeap.size() == minHeap.size()) {
                return (maxHeap.peek() + minHeap.peek()) / 2.0;
            } else {
                return maxHeap.peek();
            }
        }
        
    }