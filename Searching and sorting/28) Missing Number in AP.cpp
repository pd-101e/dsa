class Solution{
public:
    int inSequence(int a, int b, int c){
        // code here
        if(c==0)
        {
            if(a==b)
            return 1;
            else return 0;
        }
        else {
            if((b-a)/c < 0)
            {
                return 0;
            }
            else {
                if((b-a)%c == 0)
                return 1;
                else return 0;
            }
        }
    }
};

// class Solution{
// public:
//     int inSequence(int A, int B, int C){
//         // code here
//         auto ans = (B - A + C)/C;
//         string com = "" ;
//         com = com + typeid(ans).name();
//         // cout<<typeid(ans).name();
//         // cout<<com;
       
//         if(com[0]== 'i')
//         {
//             return 1;
//         }
//         else return 0;
        
//     }
