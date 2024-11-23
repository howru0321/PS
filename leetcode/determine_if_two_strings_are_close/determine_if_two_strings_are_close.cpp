class Solution {
public:
    bool closeStrings(string word1, string word2) {
        if(word1.size()!=word2.size()){
            return false;
        }

        unordered_map<char,int> char_1_nums;
        unordered_map<char,int> char_2_nums;
        for(int i=0;i<word1.size();i++){
            int char_1 = word1[i];
            auto iter_1 = char_1_nums.find(char_1);
            if(iter_1==char_1_nums.end()){
                char_1_nums.insert({char_1, 1});
            }else{
                (*iter_1).second++;
            }

            int char_2 = word2[i];
            auto iter_2 = char_2_nums.find(char_2);
            if(iter_2==char_2_nums.end()){
                char_2_nums.insert({char_2, 1});
            }else{
                (*iter_2).second++;
            }
        }

        vector<int> word_1_nums;
        vector<char> word_1_chars;
        for(auto iter_1=char_1_nums.begin();iter_1!=char_1_nums.end();iter_1++){
            int num=(*iter_1).second;
            word_1_nums.push_back(num);
            char c = (*iter_1).first;
            word_1_chars.push_back(c);
        }
        sort(word_1_nums.begin(),word_1_nums.end());
        sort(word_1_chars.begin(),word_1_chars.end());

        vector<int> word_2_nums;
        vector<char> word_2_chars;
        for(auto iter_2=char_2_nums.begin();iter_2!=char_2_nums.end();iter_2++){
            int num=(*iter_2).second;
            word_2_nums.push_back(num);
            char c = (*iter_2).first;
            word_2_chars.push_back(c);
        }
        sort(word_2_nums.begin(),word_2_nums.end());
        sort(word_2_chars.begin(),word_2_chars.end());

        for(int i=0;i<word_1_nums.size();i++){
            int num_1=word_1_nums[i];
            int num_2=word_2_nums[i];
            if(num_1!=num_2){
                return false;
            }

            char c_1=word_1_chars[i];
            char c_2=word_2_chars[i];
            if(c_1!=c_2){
                return false;
            }
        }
        return true;
    }
};