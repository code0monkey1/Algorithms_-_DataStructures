package algo;

import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

public class Knapsack {

    public static int[] itemValue;
    public static int[] itemWeight;
    public static int knapsackWeight;
    public static int items;
    public static int dp[][];


    public static void main(String[] args) {
        knapsackWeight = 7;
        items = 4;

        itemValue = new int[items + 1];
        itemWeight = new int[items + 1];

        itemValue[1] = 1;
        itemValue[2] = 4;
        itemValue[3] = 5;
        itemValue[4] = 7;

        itemWeight[1] = 1;
        itemWeight[2] = 3;
        itemWeight[3] = 4;
        itemWeight[4] = 5;

        int highestValue = highestValueForKnapsack();
        List<Integer> itemsSelected = itemsSelected();

        System.out.println(highestValue);
        System.out.println(itemsSelected);

    }

    public static int highestValueForKnapsack() {

        dp = new int[items + 1][knapsackWeight + 1];

        for (int i = 1; i <= items; i++)
            for (int k = 1; k <= knapsackWeight; k++)
                dp[i][k] = Math.max(dp[i - 1][k], itemWeight[i] <= k ? itemValue[i] + dp[i - 1][k - itemWeight[i]] : 0);


        System.out.println(Arrays.deepToString(dp).replace("],", "]\n"));

        return dp[items][knapsackWeight];
    }

    public static List<Integer> itemsSelected() {
        List<Integer> itemsSelected = new ArrayList<>();


        for (int row = items, column = knapsackWeight; row >= 1; row--) {

            if (dp[row][column] > dp[row - 1][column]) {
                itemsSelected.add(row);
                column = column - itemWeight[row];
            }

        }
        return itemsSelected;
    }
}