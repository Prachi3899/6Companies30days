class Solution {
public:

    bool isValid(long long divisor1, long long divisor2, long long uniqueCnt1, long long uniqueCnt2, long long mid)
    {
        long long div1 = mid/divisor1;
        long long div2 = mid/divisor2;
        long long notDiv1 = mid - div1;
        long long notDiv2 = mid - div2;
        long long notDiv12 = mid - (mid / lcm(divisor1, divisor2));

        if(notDiv1 >= uniqueCnt1 && notDiv2 >= uniqueCnt2 && notDiv12 >= uniqueCnt1+uniqueCnt2)
            return true;
        
        return false;
    }

    int minimizeSet(int divisor1, int divisor2, int uniqueCnt1, int uniqueCnt2) {
        long long res = INT_MAX;
        long long l = 1;
        long long h = INT_MAX;

        while(l <= h)
        {
            long long mid = l + (h-l)/2;

            if(isValid(divisor1, divisor2, uniqueCnt1, uniqueCnt2, mid))
            {
                res = min(res, mid);
                h = mid-1;
            }
            else
                l = mid+1;
        }

        return res;
    }
};