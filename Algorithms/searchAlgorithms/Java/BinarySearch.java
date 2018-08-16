package algo;

public class BinarySearch {
    private int number;
    private int arr[];
    private int indexFound;

    public BinarySearch(int arr[], int number) {
        this.arr = arr; // assumption : arr is a sorted array and is not empty
        this.number = number;
        this.indexFound = -1;
    }


    public void searchForNumber() {

        int start = 0;
        int end = arr.length - 1;

        while (start <= end) {

            int mid = getMid(start, end);

            if (midElementIsGreaterThanNumber(arr, mid, number)) {
                end = mid - 1;
            } else if (midElementIsLesserThanNumber(arr, mid, number)) {
                start = mid + 1;
            } else {
                indexFound = mid;
                return;
            }

        }
    }
    
    public boolean found(){    // this return true if the number was present in the array 
      return indexFound >= 0;
  }

  public int getIndexFound() {
        return indexFound;             // return -1 if number not found , else return the index of the number
    }  

    private int getMid(int start, int end) {
        return (start + ((end-start) >> 1)); // to escape the integer overflow
    }

    private boolean midElementIsGreaterThanNumber(int[] arr, int mid, int number) {
        return arr[mid] > number;
    }

    private boolean midElementIsLesserThanNumber(int[] arr, int mid, int number) {
        return arr[mid] < number;
    }

    public static void main(String[] args) {
        BinarySearch binarySearch = new BinarySearch(new int[]{2, 3, 4, 5, 8}, 1);
        binarySearch.searchForNumber();
        System.out.println(binarySearch.getIndexFound());
    }

}
