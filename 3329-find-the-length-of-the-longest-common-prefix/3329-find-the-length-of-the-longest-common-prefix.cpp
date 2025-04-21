class Solution {
public:
    class TrieNode{
    public:
        TrieNode *children[10];
        TrieNode(){
            for(int i = 0; i < 10; i++){
                children[i] = nullptr;
            }
        }
    };
    TrieNode *root;
    
    void makeTrie(string str){
        TrieNode *crl = root;
        for(int i = 0; i < str.size(); i++){
            int num = str[i] - '0';
            if(crl->children[num] == nullptr){
                crl->children[num] = new TrieNode();
            }
            crl = crl->children[num];
        }
    }

    int searchTrie(string str){
        TrieNode *crl = root;
        int sz = 0;
        for(int i = 0; i < str.size(); i++){
            int num = str[i] - '0';
            if(crl->children[num] == nullptr) return sz;
            sz++;
            crl = crl->children[num];
        }
        return sz;
    }
    
    int longestCommonPrefix(vector<int>& arr1, vector<int>& arr2) {
        root = new TrieNode();
        int ans = 0;
        for(int i = 0; i < arr1.size(); i++){
            string str = to_string(arr1[i]);
            makeTrie(str);
        }
        for(int i = 0; i < arr2.size(); i++){
            string str = to_string(arr2[i]);
            
            ans = max(ans, searchTrie(str));
        }
        return ans;
    }
};