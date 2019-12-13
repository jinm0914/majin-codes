#include<iostream>
using namespace std; 
#include<gtest/gtest.h>

int Abs2(int x)
{
     return x > 0 ? x : -x;
}

int Abs(int x)
{
     return Abs2(x);
}

TEST(IsAbsTest,HandlerTrueReturn)
{
    ASSERT_TRUE(Abs(1) == 1) << "Abs(1)=1";  //ASSERT_TRUE期待结果是true,operator<<输出一些自定义的信息
    ASSERT_TRUE(Abs(-1) == 2) << "Abs(-1)=1";
    ASSERT_FALSE(Abs(-2) == -2);  //期待结果是false
    ASSERT_EQ(Abs(1),Abs(-1));
    ASSERT_NE(Abs(-1),0);
    ASSERT_LT(Abs(-1),2);
    ASSERT_GT(Abs(-1),0);
    ASSERT_LE(Abs(-1),2);
    ASSERT_GE(Abs(-1),0);
}

int newResult(int s){
    FILE *stream;//
    char buffer[12];
    memset(buffer,'0',sizeof(buffer));
    char str[30];
    memset(str,'0',sizeof(str));
    sprintf(str,"./test.sh %d\0",s);
    //cout<<"bash  "<<str<<endl;
    stream = popen(str,"r");
    fgets(buffer,sizeof(buffer),stream);
    //cout<<"result  "<<buffer<<endl;
    return atoi(buffer);
}
TEST(IsAbsTest,majin)
{
    ASSERT_EQ(newResult(-5),5);
    ASSERT_EQ(newResult(0),0);
    //ASSERT_EQ(newResult(-10),100);
    ASSERT_EQ(newResult(5),50);  
}
TEST(IsAbsTest,majin2)
{
    ASSERT_EQ(newResult(-5),5);
    ASSERT_EQ(newResult(0),0);
    ASSERT_EQ(newResult(-10),100); 
}
int main(int argc, char **argv) {  
 std::cout << "Running main() from gtest_main.cc\n";  
 testing::InitGoogleTest(&argc, argv);  
 return RUN_ALL_TESTS();  
} 
