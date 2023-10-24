    public class KadaneAlgo {
            static int kadaneAlgo(int[] arr) {
                int MaxA = arr[0]; // Initialize MaxA
                int MaxB = arr[0]; // Initialize MaxB
        
                for (int i = 1; i < arr.length; i++) {
                    MaxA = Math.max(arr[i], MaxA + arr[i]);
                    MaxB = Math.max(MaxB, MaxA);
                }
        
                return MaxB;
            }
        
            public static void main(String[] args) {
                int[] arr = {5,6,-9,1,3,-1,6};
                int maxSum = kadaneAlgo(arr);
                System.out.println("Maximum subarray sum is " + maxSum);
            }
        }
        
