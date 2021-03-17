import java.lang.reflect.Array;
import java.util.Arrays;
import java.util.Comparator;

/**
 * @title: Non_overlappingIntervals_435
 * @Author Mr_zlch
 * @Date: 2021/3/16 12:20
 * @Version 1.0
 **/
/*
题目描述
        给定多个区间，计算让这些区间互不重叠所需要移除区间的最少个数。起止相连不算重叠。
        输入输出样例
        输入是一个数组，数组由多个长度固定为2 的数组组成，表示区间的开始和结尾。输出一个
        整数，表示需要移除的区间数量。
        Input: [[1,2], [2,4], [1,3]]
        Output: 1
        在这个样例中，我们可以移除区间[1,3]，使得剩余的区间[[1,2], [2,4]] 互不重叠。
*/
public class Non_overlappingIntervals_435 {
    public static void main(String[] args) {
        int i = eraseOverlapIntervals2(new int[][]{{1, 2}, {2, 3}, {3, 4}, {1, 3}});
        System.out.println(i);
    }
    //贪心
    public static int eraseOverlapIntervals(int[][] intervals) {
        if (intervals.length == 0) {
            return 0;
        }

        Arrays.sort(intervals, new Comparator<int[]>() {  //区间结尾排序
            @Override
            public int compare(int[] interval1, int[] interval2) {
                return interval1[1] - interval2[1];
            }
        });


        int n = intervals.length;
        int right = intervals[0][1];
        int res = 1;
        for (int i = 1; i < n; i++) { //从第二个开始循环，若区间开头大于right，则符合规则的区间数+1
            if(intervals[i][0] >= right){
                res++;
                right = intervals[i][1];
            }
        }
        return n-res;
    }

    //动态
    public static int eraseOverlapIntervals2(int[][] intervals) {
        int n = intervals.length;
        if (n == 0) {
            return 0;
        }

        Arrays.sort(intervals, new Comparator<int[]>() {  //区间结尾排序
            @Override
            public int compare(int[] interval1, int[] interval2) {
                return interval1[1] - interval2[1];
            }
        });


        int[] f = new int[n];
        Arrays.fill(f, 1);
        for (int i = 1; i < n; i++) {  // 令i为最大的区间，动态求其左侧的最优解
            for (int j = 0; j < i; j++) {
                if(intervals[j][1] <= intervals[i][0]){
                    f[i] = Math.max(f[i], f[j] + 1);
                }
            }
        }
        return n - Arrays.stream(f).max().getAsInt(); //总区间数-符合规则数
    }
}
