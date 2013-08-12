import java.util.ArrayList;
import java.util.Arrays;

public class Solution {
    public ArrayList<ArrayList<Integer>> threeSum(int[] num) {
    ArrayList<ArrayList<Integer>> res = new ArrayList<ArrayList<Integer>>();
    Arrays.sort(num);
    for (int i = 0; i < num.length - 2; i++) {
        int sum = -num[i];
        int s = i + 1, e = num.length - 1;
        while (s < e) {
        if (num[s] + num[e] == sum) {
            ArrayList<Integer> list = new ArrayList<Integer>();
            list.add(num[i]);
            list.add(num[s]);
            list.add(num[e]);
            res.add(list);

            while (s < e && num[s] == num[s + 1])
            s++;
            while (s < e && num[e] == num[e - 1])
            e--;
            s++;
            e--;

        } else if (num[s] + num[e] > sum) {
            e--;
        } else {
            s++;
        }
        }

        while (i < num.length-2 && num[i]==num[i+1])
        i++;
    }
    return res;
    }

    public static void main(String[] args) {
    Solution sol = new Solution();
    int[] nums = { 0, 0, 0, 0 };
    // int[] nums = { 0, 1, 2, 2, 3, -4, -1, -1 };
    ArrayList<ArrayList<Integer>> res = sol.threeSum(nums);
    for (ArrayList<Integer> list : res) {
        for (Integer i : list) {
        System.out.print(i + " ");
        }
        System.out.println();
    }
    }
}
