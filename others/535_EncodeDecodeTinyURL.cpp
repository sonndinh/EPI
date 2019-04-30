class Solution {
private:
    unordered_map<int, string> keys2;
    int count = 0;
    
    unordered_map<string, string> keys;
    const string alphabet = "0123456789abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRTSUVWXYZ";
    
    string keyGen() {
        string key;
        srand(time(nullptr));
        for (int i = 0; i < 6; ++i) {
            int ran_num = rand();
            key += alphabet[ran_num % 62];
        }
        return key;
    }
    
public:
    string encode(string longUrl) {
        string key = keyGen();
        while (keys.count(key) > 0) {
            key = keyGen();
        }
        keys.insert({key, longUrl});
        return "http://tinyurl.com/" + key;
    }
    
    string decode(string shortUrl) {
        string key = shortUrl.substr(shortUrl.find_last_of('/') + 1);
        return keys[key];
    }
    
    // Encodes a URL to a shortened URL.
    string encode2(string longUrl) {
        string shortUrl = "http:/tinyurl.com/" + to_string(count);
        keys2.insert({count, longUrl});
        ++count;
        return shortUrl;
    }

    // Decodes a shortened URL to its original URL.
    string decode2(string shortUrl) {
        size_t last_idx = shortUrl.find_last_of('/');
        string key = shortUrl.substr(last_idx+1);
        int key_num = stoi(key);
        return keys2[key_num];
    }
};

// Your Solution object will be instantiated and called as such:
// Solution solution;
// solution.decode(solution.encode(url));
