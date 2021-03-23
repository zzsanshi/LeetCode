import java.util.Arrays;

/**
 * @title: AssignCookies_455
 * @Author Mr_zlch
 * @Date: 2021/3/16 9:42
 * @Version 1.0
 **/

/*
题目描述
        有一群孩子和一堆饼干，每个孩子有一个饥饿度，每个饼干都有一个大小。每个孩子只能吃
        最多一个饼干，且只有饼干的大小大于孩子的饥饿度时，这个孩子才能吃饱。求解最多有多少孩
        子可以吃饱。
        输入输出样例
        输入两个数组，分别代表孩子的饥饿度和饼干的大小。输出最多有多少孩子可以吃饱的数
        量。
        Input: [1,2], [1,2,3]
        Output: 2
        在这个样例中，我们可以给两个孩子喂[1,2]、[1,3]、[2,3] 这三种组合的任意一种。
        */
public class AssignCookies_455 {

    public static int assignCookie(int[] g, int[] s){
        Arrays.sort(g);
        Arrays.sort(s);
        int n = g.length;
        int m = s.length;
        int res = 0;
        int i = 0;
        int j = 0;
        while(i < n && j < m){
            if(g[i] <= s[j]){
                i++;
                res++;
            }
            j++;
        }
        return res;
    }

    public static void main(String[] args) {
        int[] g = {1, 2};
        int[] s = {2, 1, 3};
        System.out.println(assignCookie(g, s));

    }
}
