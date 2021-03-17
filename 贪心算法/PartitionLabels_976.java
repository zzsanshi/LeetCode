import java.util.ArrayList;
import java.util.Arrays;
import java.util.List;

/**
 * @title: PartitionLabels_976
 * @Author Mr_zlch
 * @Date: 2021/3/17 13:07
 * @Version 1.0
 **/

/*字符串 S 由小写字母组成。我们要把这个字符串划分为尽可能多的片段，同一字母最多出现在一个片段中。
        返回一个表示每个字符串片段的长度的列表。
        示例：
        输入：S = "ababcbacadefegdehijhklij"
        输出：[9,7,8]
        解释：
        划分结果为 "ababcbaca", "defegde", "hijhklij"。
        每个字母最多出现在一个片段中。
        像 "ababcbacadefegde", "hijhklij" 的划分是错误的，因为划分的片段数较少。*/
public class PartitionLabels_976 {
    public static void main(String[] args) {
        System.out.println(partitionLabels("ababcbacadefegdehijhklij").toString());
    }
    public static List<Integer> partitionLabels(String S) {
        int[] last = new int[26];
        int n = S.length();
        for (int i = 0; i < n; i++) { //存储每个字母最后出现的下标
            last[S.charAt(i) - 'a'] = i;
        }
        int start = 0, end = 0;
        List<Integer> partition = new ArrayList<Integer>();
        for (int i = 0; i < n; i++) { //遍历字符串，维护end
            end = Math.max(end, last[S.charAt(i) - 'a']);
            if(i == end){ //若字母下标和end一致，则字段结束，start更新
                partition.add(end - start + 1);
                start = end + 1;
            }
        }
        return partition;
    }
}
