package algo;

import java.util.Arrays;

//Complexity O(N^2) where N = size of array
// Space Complexity O(1) , no extra space used

public class BubbleSort {
    private int arr[];

    public BubbleSort(int[] arr) {
        this.arr = arr;
    }

    private void swap(int indexA, int indexB) {

        int temp = arr[indexA];
        arr[indexA] = arr[indexB];
        arr[indexB] = temp;
    }

    public void sort() {

        for (int i = 0; i + 1 < arr.length; i++) {

            for (int k = i + 1; k < arr.length; k++) {
                if (arr[i] >arr[k]) swap(i, k);
            }
        }
    }

    public int[] getSortedArray() {
        return arr;
    }

    public static void main(String[] args) {
        BubbleSort bubbleSort = new BubbleSort(new int[]{2, 4, 1, -1, 9});
        bubbleSort.sort();

        int[] result=bubbleSort.getSortedArray();
        System.out.println(Arrays.toString(result));
    }
}


