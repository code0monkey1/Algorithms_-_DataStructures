package algo;


import java.util.Arrays;
import java.util.List;

public class Kadanes_Algorithm {

    public static void main(String[] args) {
        List<Integer> list = Arrays.asList(2,-5,4,-1);

        int global_max= Integer.MIN_VALUE;
        int dp_max_sum=0;
        for(int i=0;i<list.size();i++){

            dp_max_sum=Math.max(dp_max_sum,list.get(i));
            global_max=Math.max(dp_max_sum,global_max);
        }

        System.out.println(global_max);
    }

}
