class Solution {
public:
    vector<vector<int>> merge(vector<vector<int>>& intervals) {
        
vector<vector<int>> solution;
        vector<int> start;
        vector<int> end;

        for (int i = 0; i < intervals.size(); i++) {
            start.push_back(intervals[i][0]);
            end.push_back(intervals[i][1]);
        }
        sort(start.begin(), start.end());
        sort(end.begin(), end.end());
        
        // Build the vectors one at a time but compare starting and ending indexes.
        // When start[i] is less than or equal to end[pointerTwo] we are currently in
        // a merged vector so we skip ahead to the next ending index. 
        
        // When start[i] is greater than end[pointerTwo], we are at the start of a new
        // vector so we push the ending index into v, push v into the solution, and 
        // start building the next vector.
        
        vector<int> v;
        int condition = 0;
        int pointerTwo = 0;
        
        for (int i = 0; i < start.size(); i++) {
            if (i == 0) {
                v.push_back(start[i]);
                continue;
            }            
            if (start[i] <= end[pointerTwo]) {
                pointerTwo++;
                continue;
            }
            if (start[i] > end[pointerTwo]) {
                v.push_back(end[pointerTwo]);
                solution.push_back(v);
                v.clear();
                v.push_back(start[i]);
                pointerTwo++;
                continue;
            }     
        }
        v.push_back(end[pointerTwo]);
        solution.push_back(v);
        return solution;
    }
};