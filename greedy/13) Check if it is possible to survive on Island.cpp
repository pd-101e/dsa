class Solution{
public:
    int minimumDays(int s, int n, int m){
        // code here
        int x =s / 7;// number of days we can not buy food
        int y =  s - x ;// number of days we can buy food
        int sm = s*m ;// total  food req
        int days = sm/n; // kitne dys chalega food buy kia hua
        if(sm%n != 0) days++;
        if(days <= y) 
        {
            return days;
        }
        else {
            return -1;
        }
        
    }
};
