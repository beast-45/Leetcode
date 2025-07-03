class Solution {
public:
    int n;
    vector<int> segmentTree;
    void buildSegmentTree(int i , int l , int r , vector<int> &nums){
        if(l == r){
            segmentTree[i] = l;
            return;
        }
        int mid = l+(r-l)/2;
        buildSegmentTree(2*i+1,l,mid,nums);
        buildSegmentTree(2*i+2,mid+1,r,nums);
        int leftMaxIndex = segmentTree[2*i+1] , rightMaxIndex = segmentTree[2*i+2];
        segmentTree[i] = (nums[leftMaxIndex] >= nums[rightMaxIndex]) ? leftMaxIndex : rightMaxIndex;
    }
    int querySegmentTree(int start , int end , int i , int l , int r , vector<int> &heights){
        if(l>end || r<start){
            return -1;
        }
        if(l>=start && r<=end){
            return segmentTree[i]; 
        }
        int mid = l+(r-l)/2;
        int leftIndex = querySegmentTree(start,end,2*i+1,l,mid,heights);
        int rightIndex = querySegmentTree(start,end,2*i+2,mid+1,r,heights);
        if(leftIndex == -1) return rightIndex;
        if(rightIndex == -1) return leftIndex;
        return heights[leftIndex] >= heights[rightIndex] ? leftIndex : rightIndex;
    }
    int rangeMIQ(int start , int end , vector<int> &heights){
        return querySegmentTree(start,end,0,0,n-1,heights);
    }
    vector<int> leftmostBuildingQueries(vector<int>& heights, vector<vector<int>>& queries) {
        n = heights.size();
        segmentTree.resize(4*n);
        buildSegmentTree(0,0,n-1,heights);

        vector<int> result;
        for(auto &query : queries){
            int start = query[0] , end = query[1];
            if(start == end){
                result.push_back(start);
                continue;
            }
            if(start < end && heights[start] < heights[end]){
                result.push_back(end);
                continue;
            }
            if(end < start && heights[end] < heights[start]){
                result.push_back(start);
                continue;
            }
            int maxIndex = max(start,end);
            int l = maxIndex+1 , r = n-1;
            int resultIndex = -1;
            while(l <= r){
                int mid = l+(r-l)/2;
                int index = rangeMIQ(l,mid,heights);
                if(index != -1 &&  heights[index] > max(heights[start], heights[end])){
                    resultIndex = index;
                    r = mid-1;
                }else{
                    l = mid+1;
                }
            }
            result.push_back(resultIndex);
        }
        return result;
    }
};