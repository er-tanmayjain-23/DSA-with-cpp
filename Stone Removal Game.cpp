class Solution {
public:
    bool canAliceWin(int n) {
        int missing = 55 - n;  
        int unplayed = lround(sqrt(2 * missing));  
        return unplayed % 2 == 1; 
    }
};
