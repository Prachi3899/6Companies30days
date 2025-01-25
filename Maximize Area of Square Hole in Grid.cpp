class Solution {
public:
    int maximizeSquareHoleArea(int n, int m, vector<int>& num1, vector<int>& num2) {
          
            sort(num1.begin(),num1.end());
            sort(num2.begin(),num2.end());
              
               int ver_count=1;
               int max_vcount=1;
                for(int i=0;i<num1.size()-1;i++){
                        if(num1[i]+1==num1[i+1]) ver_count++;
                         else {
                            ver_count=1;
                         }
                            max_vcount= max(max_vcount,ver_count);
                         
                  }
                     
               int hor_count=1;
               int max_hcount=1;   
                      for(int i=0;i<num2.size()-1;i++){
                        if(num2[i]+1==num2[i+1]) hor_count++;
                         else {
                            hor_count=1;
                         }
                            max_hcount=max(max_hcount,hor_count);
                         
                  }
                      int ans=min(max_vcount,max_hcount)+1;
                      return ans*ans;
    }
};