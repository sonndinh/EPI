class Solution {
public:
    string helper(int num, const unordered_map<int, string>& units, const unordered_map<int, string>& tens) {
        string ret;
        if (num >= 100) {
            int q = num/100;
            ret += units.at(q) + " Hundred";
            num -= q * 100;
        }
        
        if (num >= 10 && num <= 19) {
            if (!ret.empty())
                ret += " ";
            ret += tens.at(num);
            return ret;
        }
        
        if (num >= 20) {
            int q = num/10;
            if (!ret.empty())
                ret += " ";
            ret += tens.at(q*10);
            num -= q * 10;
        }
        
        if (num > 0) {
            if (!ret.empty())
                ret += " ";
            ret += units.at(num);
        }
        return ret;
    }
    
    string numberToWords(int num) {
        if (num == 0)
            return "Zero";
        
        string ret;
        unordered_map<int, string> units{{0, ""}, {1, "One"}, {2, "Two"}, {3, "Three"}, {4, "Four"}, {5, "Five"}, 
                                         {6, "Six"}, {7, "Seven"}, {8, "Eight"}, {9, "Nine"}};
        unordered_map<int, string> tens{{10, "Ten"}, {11, "Eleven"}, {12, "Twelve"}, {13, "Thirteen"}, 
                                        {14, "Fourteen"}, 
                                        {15, "Fifteen"}, {16, "Sixteen"}, {17, "Seventeen"}, {18, "Eighteen"}, 
                                        {19, "Nineteen"}, {20, "Twenty"}, {30, "Thirty"}, {40, "Forty"}, 
                                        {50, "Fifty"}, {60, "Sixty"}, {70, "Seventy"}, {80, "Eighty"}, {90, "Ninety"}};
        
        const int thousand = (int) pow(10, 3);
        const int million = (int) pow(10, 6);
        const int billion = (int) pow(10, 9);
        
        if (num >= billion) {
            int quotient = num/billion;
            ret += units[quotient] + " Billion";
            num -= quotient * billion;
        }
        
        if (num >= million) {
            int quotient = num/million;
            if (!ret.empty())
                ret += " ";
            ret += helper(quotient, units, tens) + " Million";
            num -= quotient * million;
        }
        
        if (num >= thousand) {
            int quotient = num/thousand;
            if (!ret.empty())
                ret += " ";
            ret += helper(quotient, units, tens) + " Thousand";
            num -= quotient * thousand;
        }
        
        if (num > 0) {
            if (!ret.empty()) {
                ret += " ";
            }
            ret += helper(num, units, tens);
        }
        return ret;
    }
};
