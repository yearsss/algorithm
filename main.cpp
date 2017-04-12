

#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <iomanip>

using namespace std;

/*
class Solution {
public:
    int countRangeSum(vector<int>& nums, int lower, int upper) {
        
    }
    
    int countRange(vector<int> nums,int start,int end,int lower,int upper){
        if(end-start>1){
            int mid = (end-start)/2 + start;
            int preCnt=countRange(nums, start, mid, lower, upper);
            int sufCnt=countRange(nums, mid, end, lower, upper);
            vector<int> sum1(mid-start),sum2(end-mid);
            int sum=0;
            for(int i=mid-1;i>0;i--){
                sum+=nums[i];
                sum1[i]=sum;
            }sum=0;
            for(int i=mid;i<end;i++){
                sum+=nums[i];
                sum2[i]=sum;
            }
            sort(sum1.begin(),sum1.end());
            sort(sum2.begin(),sum2.end());
            for(int i=start;i<mid;i++){
                int cnt = binSearch(sum2,mid,end,lower-sum1[idx],upper-sum1[idx]);
            }
        }
    }
    int binSearch(vector<int> sum,int start,int end,int lower,int upper){
        int high=end,low=start;
        while(low<high){
            int mid=(end-start)/2+start;
            if(sum[mid]<upper) low=mid;
            else if(sum[mid]>upper) high=mid;
            else
        }
        
    }
};
*/

//寻找第一个下标等于key
int binSearch_first(vector<int>& nums, int key){
    int low=0,high=nums.size()-1;
    while(low<high){
        int mid = (high-low)/2+low;
        if(nums[mid]<key) low=mid+1;
        else high=mid;
    }
    if(nums[high]==key) return high;
    else return -1;
}

int binSearch_last(vector<int>& nums, int key){
    int low = 0,high=nums.size()-1;
    while(low<high-1){
        int mid=(high-low)/2+low;
        if(nums[mid]<=key) low=mid;
        else high=mid;
    }
    
    if(nums[high]==key) return high;
    else if(nums[low]==key) return low;
    else return -1;
}

int binSearch_le(vector<int> nums,int key){
    int low=0,high=nums.size()-1;
    while(low<high-1){
        int mid=(high-low)/2+low;
        if(nums[mid]>=key)high=mid-1;
        else low=mid;
    }
    if(nums[high]<key) return high;
    else if(nums[low]<key) return low;
    else return -1;

}

int binSearch_ge(vector<int> nums,int key){
    int low=0,high=nums.size()-1;
    while(low<high-1){
        int mid=(high-low)/2+low;
        if(nums[mid]>key) high=mid;
        else low=mid+1;
    }
    if(nums[low]>key) return low;
    else if(nums[high]>key) return high;
    else return -1;
}



int main(){
    
    vector<int> nums={1,2,3,4,4,5,5,6,6,6,6,8};
    cout<<binSearch_ge(nums, 3)<<endl;
  
    return 0;
}








