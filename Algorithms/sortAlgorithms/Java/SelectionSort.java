package algo;

import java.util.Arrays;

// Time Complexity  O(N^2) where N = length of array
// Space Complexity O(1) , no extra space used

public class SelectionSort {
    private int arr[];

    public SelectionSort(int[] arr) {
        this.arr = arr;
    }

    public void sort() {

        for (int i = 0; i + 1 < arr.length; i++) {

            for (int k = i + 1; k < arr.length; k++) {
                if (arr[i] > arr[k]) swap(i, k);
            }
        }
    }

    private void swap(int indexA, int indexB) {
        int temp = arr[indexA];
        arr[indexA] = arr[indexB];
        arr[indexB] = temp;
    }

    public int[] getSortedArray() {
        return arr;
    }

    public static void main(String[] args) {
        SelectionSort selectionSort = new SelectionSort(new int[]{3, -1, 4, 5, 0, 2});
        selectionSort.sort();
        int[] result = selectionSort.getSortedArray();
        System.out.println(Arrays.toString(result));
    }
}
