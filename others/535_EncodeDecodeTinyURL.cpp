class Solution {
private:
    unordered_map<int, string> keys;
    int count = 0;
        
public:

    // Encodes a URL to a shortened URL.
    string encode(string longUrl) {
        string shortUrl = "http:/tinyurl.com/" + to_string(count);
        keys.insert({count, longUrl});
        ++count;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode(string shortUrl) {
        size_t last_idx = shortUrl.find_last_of('/');
        string key = shortUrl.substr(last_idx+1);
        int key_num = stoi(key);
        return keys[key_num];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
