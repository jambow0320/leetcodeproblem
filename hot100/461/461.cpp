class Solution {
public:
    int hammingDistance(int x, int y) {
        int hamDis = 0;
        for(int i = 0; i < 31; ++i)
            hamDis += ((x >> i) & 1) ^ ((y >> i) & 1);
        return hamDis;
    }
};