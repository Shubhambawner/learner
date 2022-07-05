class Solution
{
private:
    // private variable
    int a = 0;
    // private static variable
    static int b;
    // private static variable that has to be initiated in class body, has to be const
    static const int c = 5;

public:
    Solution(/* args */);
    int getA();
    int setA();
    int getB();
    int setB();
    ~Solution();
};

Solution::Solution(/* args */)
{
}

Solution::~Solution()
{
}

int Solution::setB(){
    
}