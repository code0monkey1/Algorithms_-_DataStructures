package algo;

import java.util.Arrays;

public class IntMinPriorityQueue {

    private int arr[];
    private int lastIndex = -1;
    public IntMinPriorityQueue(int size) {
        arr = new int[size];
    }


    public IntMinPriorityQueue() {
        this(1);
    }

    public int[] getArr() {
        return arr;
    }

    private boolean isInvalidIndex(int index) {
        return (index > lastIndex || index < 0);
    }

    private void expandArrayIfNeeded() {
        if (arr.length == lastIndex) arr = Arrays.copyOf(arr, arr.length * 2);
    }

    public void push(int element) {
        lastIndex++;
        expandArrayIfNeeded();
        arr[lastIndex] = element;
        swim(lastIndex);
    }

    public void pop() {
        arr[0] = arr[lastIndex--];
        sink(0);
    }

    public int getLastIndex() {
        return lastIndex;
    }

    public int getSize() {
        return arr.length;
    }

    private void swim(int childIndex) {

        int parentIndex = (childIndex - 1) / 2;

        if (childIndex == 0 ||
                isInvalidIndex(parentIndex) ||
                isChildGreaterThanParent(arr[childIndex], arr[parentIndex])) return;

        swap(childIndex, parentIndex);

        swim(parentIndex);
    }

    private void sink(int parentIndex) {

        if (parentIndex == lastIndex) return;

        int leftChildIndex = 2 * parentIndex + 1;
        int rightChildIndex = 2 * parentIndex + 2;

        int childIndex = leftChildIndex;

        if (!isInvalidIndex(leftChildIndex) && !isInvalidIndex(rightChildIndex))
            childIndex = arr[rightChildIndex] < arr[leftChildIndex] ? rightChildIndex : leftChildIndex;

        if (isChildGreaterThanParent(arr[childIndex], arr[parentIndex])) return;

        swap(childIndex, parentIndex);

        sink(childIndex);

    }

    private void swap(int childIndex, int parentIndex) {
        int temp = arr[childIndex];
        arr[childIndex] = arr[parentIndex];
        arr[parentIndex] = temp;
    }

    private boolean isChildGreaterThanParent(int child, int parent) {
        return child > parent;
    }

    public void removeElement(int element) {

        boolean foundElement = false;
        int elementIndex = 0;

        for (int index = 0; index <= lastIndex; index++)
            if (element == arr[index]) {
                foundElement = true;
                elementIndex = index;
            }

        if (!foundElement) return;

        swap(lastIndex, elementIndex);

        lastIndex--;
        sink(elementIndex);

    }


}
