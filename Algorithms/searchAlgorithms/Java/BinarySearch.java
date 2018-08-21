package algo;

// Time complexity (log(N)) where N = number of elements
// Space Complexity O(1) , no extra space used

public class BinarySearch {
    private int number;
    private int arr[];
    private int indexFound;

    public BinarySearch(int arr[], int number) {
        this.arr = arr; // assumption : arr is a sorted array
        this.number = number;
        this.indexFound = -1;
    }


    public void searchForNumber() {

        int start = 0;
        int end = arr.length - 1;

        while (start <= end) {

            int mid = getMid(start, end);

            if (midElementGreaterThanNumber(arr, mid, number)) {
                end = mid - 1;
            } else if (midElementLesserThanNumber(arr, mid, number)) {
                start = mid + 1;
            } else {
                indexFound = mid;
                return;
            }

        }
    }

    public int getIndexFound() {
        return indexFound;
    }

    private int getMid(int start, int end) {
        return (start + ((end-start) >> 1)); // to escape the integer overflow
    }

    private boolean midElementGreaterThanNumber(int[] arr, int mid, int number) {
        return arr[mid] > number;
    }

    private boolean midElementLesserThanNumber(int[] arr, int mid, int number) {
        return arr[mid] < number;
    }

    public static void main(String[] args) {
        BinarySearch binarySearch = new BinarySearch(new int[]{2, 3, 4, 5, 8}, 1);
        binarySearch.searchForNumber();
        System.out.println(binarySearch.getIndexFound());
    }

}
