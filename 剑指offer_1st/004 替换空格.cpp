/*
* CodingInterviews/004-替换空格 at master · gatieme/CodingInterviews 
    * https://github.com/gatieme/CodingInterviews/tree/master/004-%E6%9B%BF%E6%8D%A2%E7%A9%BA%E6%A0%BC
* 替换空格__牛客网 
    * https://www.nowcoder.com/questionTerminal/4060ac7e3e404ad1a894ef3e17650423
* 替换空格__牛客网 
    * https://www.nowcoder.com/questionTerminal/4060ac7e3e404ad1a894ef3e17650423?answerType=1&f=discussion
*/

class Solution {
public:
    void replaceSpace(char *str,int length) {
        int old_len=0, space_cnt=0, new_len;
        int i=0;
        while(str[i]!='\0') {
            ++old_len;
            if (str[i]==' ')
                ++space_cnt;
            ++i;
        }
        new_len = old_len + space_cnt*2;
        // *_len no need to -1 because we do not count '\0'
        int old_p = old_len, new_p = new_len;
         while(old_p>=0) {
            if (str[old_p]==' ') {
                str[new_p--] = '0';
                str[new_p--] = '2';
                str[new_p--] = '%';
            } else {
                str[new_p--] = str[old_p];
            }
            --old_p;
         }
    }
};