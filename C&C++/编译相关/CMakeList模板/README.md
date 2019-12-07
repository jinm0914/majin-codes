# majin-C&C++
编译相关

-I 头文件 .表示当前文件
-L 库文件 .表示当前文件
例：-I ../include -L .

-w    		*关闭编译时的警告
-Wall 		*允许编译提供的所有有用的报警信息
-Wextra 		*编译后显示所有警告，比-Wall 详细
-Wfatal-errors 	*表示当发生第一个错误的时候停止编译
-Wunused 	*声明变量未使用，后过滤扩展，例：声明变量：-Wunused-variable；声明参数：-Wunused-parameter等
-Werror 		把所有的告警信息转化为错误信息，并在告警发生时终止编译过
-Wundef 		显示宏未定义的警告信息

-pedantic 	允许发出ANSI/ISO C标准列出的全部警告信息
-pedantic-errors 	允许发出ANSI/ISO C标准所列的全部错误信息

cmake中一些预定义变量

PROJECT_SOURCE_DIR 工程的根目录
PROJECT_BINARY_DIR 运行cmake命令的目录,通常是${PROJECT_SOURCE_DIR}/build
CMAKE_INCLUDE_PATH 环境变量,非cmake变量
CMAKE_LIBRARY_PATH 环境变量
CMAKE_CURRENT_SOURCE_DIR 当前处理的CMakeLists.txt所在的路径
CMAKE_CURRENT_BINARY_DIR target编译目录 
使用ADD_SURDIRECTORY(src bin)可以更改此变量的值 
SET(EXECUTABLE_OUTPUT_PATH <新路径>)并不会对此变量有影响,只是改变了最终目标文件的存储路径
CMAKE_CURRENT_LIST_FILE 输出调用这个变量的CMakeLists.txt的完整路径
CMAKE_CURRENT_LIST_LINE 输出这个变量所在的行
CMAKE_MODULE_PATH 定义自己的cmake模块所在的路径 
SET(CMAKE_MODULE_PATH ${PROJECT_SOURCE_DIR}/cmake),然后可以用INCLUDE命令来调用自己的模块
EXECUTABLE_OUTPUT_PATH 重新定义目标二进制可执行文件的存放位置
LIBRARY_OUTPUT_PATH 重新定义目标链接库文件的存放位置
PROJECT_NAME 返回通过PROJECT指令定义的项目名称
CMAKE_ALLOW_LOOSE_LOOP_CONSTRUCTS 用来控制IF ELSE语句的书写方式
