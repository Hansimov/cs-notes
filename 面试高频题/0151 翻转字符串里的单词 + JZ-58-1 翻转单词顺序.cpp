class Solution {
public:
    string reverseWords(string s) {
        reverse(s.begin(), s.end());

        int idx = 0;    // offset of pointer to string s
        int start = 0;  // start of current word
        int end = 0;    // end of current word
        for (start=0; start<s.size(); ++start) {
            if (s[start] == ' ')
                continue;
            if (idx != 0) // add space between two words
                s[idx++] = ' ';

            end = start;
            while (end<s.size() && s[end]!=' ') 
                s[idx++] = s[end++];

            reverse(s.begin()+idx-(end-start), s.begin()+idx);

            start = end;
        }
        // erase uesless space of string
        s.erase(s.begin()+idx, s.end());
        return s;
    }
};