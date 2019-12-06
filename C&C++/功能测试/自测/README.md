# majin-C&C++

功能测试：主要用于函数，可执行程序的多用例测试，开源库有gtest等

编译：

g++ main.cpp -I include -L . -lgtest -lpthread -o main -std=c++11 -Wfatal-errors

g++ test.cpp -o test -std=c++11

逻辑：

运行main，调用shell->test,返回程序test执行结果，在main中进行测试结果正确性，用于对test程序进行多测试用例测试
