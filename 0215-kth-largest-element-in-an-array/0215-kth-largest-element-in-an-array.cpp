class Solution {
public:
    void heapify(vector<int>& nums,int x,int i){
        int largest=i;
        int left=2*i+1;
        int right=2*i+2;
        if(left<x&&nums[largest]<nums[left])
        largest=left;
        if(right<x&&nums[largest]<nums[right])
        largest=right;
        if(largest!=i){
            swap(nums[largest],nums[i]);
            heapify(nums,x,largest);
        }  

    }
    void buildheap(vector<int>& nums){
        for(int i=(nums.size()-2)/2;i>=0;i--){
            heapify(nums,nums.size(),i);
        }
    }
    int findKthLargest(vector<int>& nums, int k) {
        buildheap(nums);
        for(int i=nums.size()-1;i>=1;i--){
            swap(nums[i],nums[0]);
            heapify(nums,i,0);
        }
        return nums[nums.size()-k];
    }
};