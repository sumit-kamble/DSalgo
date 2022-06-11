class Solution {
public:
    int minOperations(vector<int>& nums, int x) {
        
        //arr = [1, 1, 4, 2, 3]  x = 5
        
        // remove min number of elements to reduce x to 0
        // sumTot = 11 total sum of array
        // sumTar = sumTot - x = 11 - 5 = 6
        
        // find subarray of max size of sum = sumTar
        // return size of arrSize - subarraySize
        
        int i,j, sumCurr = 0, sumTar = 0;  
        int len = 0;
        
        for(i = 0; i < nums.size(); i++){
            sumTar += nums[i];  // total sum of array
        }
        
        sumTar -= x;  // find subarray of sumTar of max size
        
        
		if(sumTar == 0){         
            return nums.size();
        }
// sliding window technique 
// i points to begining of subarray and j points to end of subarray 

		// sumTar is desired sum while sum1 is current sum
        
        i = 0;
        for(j = 0; j < nums.size(); j++)
        {
            sumCurr += nums[j];
			
            while(i < nums.size() && sumCurr > sumTar) // if sum of current subaaray is greater than desired sum
                sumCurr-=nums[i++];
				
            if(sumCurr == sumTar)  // if sum of current subarray is equal to desired sum then update length
                len = max(len, j-i+1); // we want subarray  with maximum length 
        }
        if(!len)        // No subarray found with desired sum .
            return -1;
        return nums.size()-len;
    }
};