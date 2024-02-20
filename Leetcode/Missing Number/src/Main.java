class Solution {
    public int missingNumber(int[] nums) {
        int val=0;
        for(int i=0;i<=nums.length;++i)
            val^=i;
        for(int i:nums){
            val^=i;
        }
        return val;
    }
}
public class Main {
    public static void main(String[] args) {
        int[]nums={3,0,1};
        Solution obj=new Solution();
        System.out.println(obj.missingNumber(nums));
    }
}