//--- Q: 1007. Minimum Domino Rotations For Equal Row

//--- method 1: one pass, find cnt for the first domino
class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int n = tops.size(), tsame = 1, bsame = 1;
        int tcnt1 = 0, tcnt2 = 0, bcnt1 = 0, bcnt2 = 0;
        for (int i = 0; i < n; ++i) {
            tsame &= tops[i] == tops[0] || bottoms[i] == tops[0];
            bsame &= tops[i] == bottoms[0] || bottoms[i] == bottoms[0];
            if (!tsame && !bsame) {
                return -1;
            }
            tcnt1 += tops[0] == tops[i];
            tcnt2 += tops[0] == bottoms[i];
            bcnt1 += bottoms[0] == tops[i];
            bcnt2 += bottoms[0] == bottoms[i];
        }
        return min(n-max(tcnt1, tcnt2), n-max(bcnt1, bcnt2));
    }
};