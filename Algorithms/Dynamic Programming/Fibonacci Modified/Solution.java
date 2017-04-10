import java.util.*;
import java.math.*;

public class Solution {
	int n;
    BigInteger a,b,num;
    Solution() {
        Scanner scan=new Scanner(System.in);
        int x,y;
        x=scan.nextInt();
        y=scan.nextInt();
        n=scan.nextInt();
        a=new BigInteger(String.valueOf(x));
        b=new BigInteger(String.valueOf(y));
        num= new BigInteger("0");
    }
    public static void main(String[] args) {
        Solution obj=new Solution();
        obj.calc();
        System.out.println(obj.num);
        
    }
    
    private void calc() {
        for(int i=0;i<n-2;i++) {
        		num=a.add(b.multiply(b));
        		a=b;
        		b=num;
        	}
        }
   }