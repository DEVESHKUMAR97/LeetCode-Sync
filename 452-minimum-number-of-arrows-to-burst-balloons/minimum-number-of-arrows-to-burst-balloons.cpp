bool myComp(vector<int>& a, vector<int>& b) {
    return a[1] < b[1];
}
class Solution {
public:

    int findMinArrowShots(vector<vector<int>>& points) {
        sort(points.begin(), points.end(), myComp);

        int arrows = 1;
        int covered = points[0][1];
        for(int i = 1; i < points.size(); i++) {
            if(points[i][0] > covered) {
                arrows++;
                covered = points[i][1];
            }
        }
        return arrows;
    }
};