package Bitwise_And_of_Numbers_Range;
class Solution {
  public int rangeBitwiseAnd(int left, int right) {
    if (left == 0 || left == right)
      return left;
    int ans = 0;
    while (true) {
      int low = lg(left);
      int high = lg(right);
      // System.out.println(low+" "+high+" "+left+" "+right);
      if (low != high || left == 0)
        break;
      ans |= (1 << low);
      left = eraseMSB(left, low);
      right = eraseMSB(right, high);
    }
    return ans;
  }
  public static int lg(int x) {
    if (x == 0)
      return -1;
    return 31 -
        Integer.numberOfLeadingZeros(x); // 31 for integer size (32 bits)
  }
  public int eraseMSB(int x, int y) { return x & (~(1 << y)); }
}
public class Bitwise_And_of_Numbers_Range {
  public static void main(String[] args) {
    int left = 12, right = 15;
    Solution obj = new Solution();
    System.out.println(obj.rangeBitwiseAnd(left, right));
  }
}
