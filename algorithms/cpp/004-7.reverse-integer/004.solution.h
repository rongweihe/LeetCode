class Solution {
public:
    int reverse(int x) {
         if(x==0) return 0;
        double s=0;
        int flag=1;
        if(x<0)
        {
            flag=-1;
            x*=-1;
        }
        while(x)
        {
            s=s*10+x%10;
            x/=10;
        }
        s*=flag;
        //puts("jjj");
      //  cout<<s<<endl;
        return (s>INT_MAX|| s< -INT_MAX) ?0:s;
    }
};
