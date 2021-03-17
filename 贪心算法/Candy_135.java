import java.util.Arrays;

/**
 * @title: Candy_135
 * @Author Mr_zlch
 * @Date: 2021/3/16 10:26
 * @Version 1.0
 **/
/*
题目描述
        一群孩子站成一排，每一个孩子有自己的评分。现在需要给这些孩子发糖果，规则是如果一
        个孩子的评分比自己身旁的一个孩子要高，那么这个孩子就必须得到比身旁孩子更多的糖果；所
        有孩子至少要有一个糖果。求解最少需要多少个糖果。
        输入输出样例
        输入是一个数组，表示孩子的评分。输出是最少糖果的数量。
        Input: [1,0,2]
        Output: 5
        在这个样例中，最少的糖果分法是[2,1,2]。
*/
public class Candy_135 {
    public static void main(String[] args) {
        System.out.println(candy(new int[]{1,3,2,2,1}));
        candy2(new int[]{1,3,2,2,1});
    }
    private static int candy(int[] ratings) {
        int n = ratings.length; // 孩子数量
        if(ratings == null || n == 0) return 0;
        if(n == 1) return 1;

        int[] res = new int[n]; // 初始化所有孩子的糖果都为1
        Arrays.fill(res, 1);
        for (int i = 1; i < n; i++) { //从左到右扫，只能维护右边的孩子，循环扫描右边的孩子，i从1开始
            if(ratings[i - 1] < ratings[i]){ //右边的分数大于左边，则右边为左边+1个糖果
                res[i] = res[i - 1] + 1;
            }
        }
        for (int i = n - 1; i > 0; i--) { // 从右到左扫，循环扫描右边的孩子，i从n-1递减
            if(ratings[i] < ratings[i - 1]){ //第一次循环后，已存在分数差，左边分数大则糖果数必定不小于右边，则左边糖果数应为左边与右边糖果+1的最大值
                res[i - 1] = Math.max(res[i - 1], res[i] + 1);
            }
        }
        return Arrays.stream(res).sum();
    }

    private static int candy2(int[] ratings) {
        int[] left = new int[ratings.length];
        int[] right = new int[ratings.length];
        Arrays.fill(left, 1);
        Arrays.fill(right, 1);
        for(int i = 1; i < ratings.length; i++)
            if(ratings[i] > ratings[i - 1]) left[i] = left[i - 1] + 1;
        int count = left[ratings.length - 1];
        for(int i = ratings.length - 2; i >= 0; i--) {
            if(ratings[i] > ratings[i + 1]) right[i] = right[i + 1] + 1;
            count += Math.max(left[i], right[i]);
        }
        return count;
    }
    private static int candy3(int[] ratings) {
        int n = ratings.length; // 孩子数量
        if(ratings == null || n == 0) return 0;
        if(n == 1) return 1;
        int res = 1;
        int inc = 1, dec = 0, pre = 1; //递增序列长度为1，递减为0，当前初始为1
        for (int i = 1; i < n; i++) { //左向右扫
            if(ratings[i] >= ratings[i - 1]){ //右大等于左。则为递增或平行
                dec = 0; //递增时，递减为0
                pre = ratings[i] == ratings[i - 1] ? 1 : pre + 1; //右等于左，当前为1，否则为左+1
                res += pre; //结果累加当前糖果数
                inc = pre; //增长长度为当前值
            }else{
                dec++; //小于时，递减累加1
                if(dec == inc) // 若最近的递增个数等于递减个数，说明递增序列最后一位为两个序列的最高分数，递增的最后一位可加入递减序列
                    dec++;
                res += dec; // 结果累加递减序列长度
                pre = 1; //对于递增来说，递减均为1，以便为递增赋值
            }
        }
        return res;
    }
}
