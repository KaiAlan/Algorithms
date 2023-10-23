package Algorithms;

import java.util.Arrays;

class cyclicSort{
    public static void main(String[] args) {
        int arr[] = {4,3,2,1};
        cyclicSort(arr);
        System.out.println(Arrays.toString(arr));
    }
    static void cyclicSort(int[] arr){
        int i = 0;
        while(i<arr.length){
            int correct = arr[i] -1;
            if( arr[i] != arr[correct]){
                swap(arr, i, correct);
            }
            else i++;
        }
    }
    static void swap(int[]  arr, int p1, int p2){
        int temp = arr[p1];
        arr[p1] = arr[p2];
        arr[p2] = temp;
    }
}

