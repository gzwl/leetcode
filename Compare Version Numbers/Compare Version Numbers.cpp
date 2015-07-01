/*
    比较版本号的大小
    从左到右依次比较被'.'分割成的区域，如果大小不等就直接返回结果，大小相同再比较下一个
    每个区域的字符串化成数字进行比较
*/

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0,j = 0;
        while(i < version1.size() || j < version2.size()){
            int num1 = 0,num2 = 0;
            while(i < version1.size() && version1[i] != '.')    num1 = num1 * 10 + version1[i++] - '0';
            while(j < version2.size() && version2[j] != '.')    num2 = num2 * 10 + version2[j++] - '0';
            i++;
            j++;
            if(num1 > num2)     return 1;
            if(num1 < num2)     return -1;
        }
        return 0;
    }
};

