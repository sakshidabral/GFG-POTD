//{ Driver Code Starts
// Initial Template for Java

import java.io.*;
import java.util.*;

class GFG {
    public static void main(String args[]) throws IOException {
        BufferedReader read = new BufferedReader(new InputStreamReader(System.in));
        int t = Integer.parseInt(read.readLine());
        while (t-- > 0) {
            String S1 = read.readLine().trim();
            String S2 = read.readLine().trim();

            Solution ob = new Solution();
            System.out.println(ob.longestCommonSubstr(S1, S2));
        }
    }
}
// } Driver Code Ends


class Solution {
    public int longestCommonSubstr(String str1, String str2) {
        // code here
        int maxi=0;
        for(int i=0;i<str1.length();i++){
            String s="";
            for(int j=i;j<str1.length();j++){
                s=s+str1.charAt(j);
                if(str2.contains(s))
                   maxi=Math.max(maxi,s.length()); 
            }
        }
        return maxi;
    }
}
