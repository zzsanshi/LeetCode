/**
 * @title: CanPlaceFlowers_605
 * @Author Mr_zlch
 * @Date: 2021/3/17 10:36
 * @Version 1.0
 **/
/*假设有一个很长的花坛，一部分地块种植了花，另一部分却没有。可是，花不能种植在相邻的地块上，它们会争夺水源，两者都会死去。

        给你一个整数数组flowerbed 表示花坛，由若干 0 和 1 组成，其中 0 表示没种植花，1 表示种植了花。
        另有一个数n ，能否在不打破种植规则的情况下种入n朵花？能则返回 true ，不能则返回 false。

        示例 1：

        输入：flowerbed = [1,0,0,0,1], n = 1
        输出：true
        */
public class CanPlaceFlowers_605 {
    public static void main(String[] args) {
        System.out.println(canPlaceFlowers(new int[]{1,0,0,0,1}, 1));

    }
    public static boolean canPlaceFlowers(int[] flowerbed, int n) {
        int count = 0;
        int m = flowerbed.length;
        int pre = -1; // 有花的下标

        for (int i = 0; i < m; i++) {
            if(flowerbed[i]==1){
                if(pre < 0){  //左边界到第一朵花间的可种花数
                    count += i / 2;
                }else{ //第n-1朵花与第n朵花间的可种花数
                    count += (i - pre - 2) / 2;
                }
                if(count >= n) //可种数大于n直接返回true
                    return true;
                pre = i; //维护当前花下标
            }
        }

        if(pre < 0){ //花圃没有花时的可种花数
            count += (m + 1) / 2;
        }else{ //最后一朵花到右边界的可种花数
            count += (m - pre - 1) / 2;
        }

        return count >= n;
    }
}
