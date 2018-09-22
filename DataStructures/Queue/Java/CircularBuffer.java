import java.util.Arrays;

public class CircularBuffer<T> {

    private T[] arr;
    private int read;
    private int write;

    public CircularBuffer(int size) {
        arr = (T[]) new Object[size];
    }


    private int nextIndex(int index) {
        return (index + 1) % (arr.length);
    }

    private boolean arrayIsFull() {
        return arr[write] != null;
    }

    public T poll() {
        T element = arr[read];

        if (element == null) {
            System.out.println("The array is empty");
            return null;
        } else {
            arr[read] = null;
            read = nextIndex(read);
        }

        return element;
    }

    @Override
    public String toString() {
        return "CircularBuffer{" +
                "arr=" + (arr == null ? null : Arrays.asList(arr)) +
                '}';
    }

    public void offer(T element) {
        if (arrayIsFull()) System.out.println("The array is full");
        else {
            arr[write] = element;
            write = nextIndex(write);
        }

    }

    public static void main(String[] args) {
        CircularBuffer<Integer> integerCircularBuffer = new CircularBuffer<>(3);
        integerCircularBuffer.offer(3);
        System.out.println(integerCircularBuffer);
        integerCircularBuffer.offer(4);
        System.out.println(integerCircularBuffer);
        integerCircularBuffer.offer(1);
        System.out.println(integerCircularBuffer);
        integerCircularBuffer.offer(6);
        System.out.println(integerCircularBuffer);
        integerCircularBuffer.poll();
        System.out.println(integerCircularBuffer);
        integerCircularBuffer.poll();
        System.out.println(integerCircularBuffer);
        integerCircularBuffer.poll();
        System.out.println(integerCircularBuffer);
        integerCircularBuffer.poll();

    }

}
