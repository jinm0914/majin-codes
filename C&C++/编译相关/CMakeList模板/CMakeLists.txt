# 指定CMake的最低编译版本
cmake_minimum_required(VERSION 3.9)

# 指定一个名字
project(sumo_Traci)

# 设定编译参数
# 编译标准 -std= xx
set(CMAKE_CXX_STANDARD 11)
# 显示编译颜色
set(CMAKE_COLOR_MAKEFILE ON) 
# 指定 so的生成目录lib
set(LIBRARY_OUTPUT_PATH ${PROJECT_SOURCE_DIR}/lib)
# 设置二进制文件目录
set(BIN_DESTINATION ${PROJECT_SOURCE_DIR}/bin)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${BIN_DESTINATION})
# 添加-g编译选项,具体含义见README.md
add_definitions("-Wall -Wfatal-errors -Wunused -Wundef -g")

# 设定源码列表 两种方式: 1、指定文件；2、使用*.c *.cpp 搜索全部编译源文件
# 1、设定源码列表.cpp
# set(SOURCE_FILES src/mytest.cpp src/socket.cpp src/storage.cpp src/TraCIAPI.cpp)


#2、搜集src目录下所有的.cpp文件(源文件)
# SOURCE_FILES代表src目录下所有的源文件
# 设定所有源码列表 ：aux_source_directory(<dir> <variable>)
# AUX_SOURCE_DIRECTORY(${PROJECT_SOURCE_DIR}/src,SRC_LIST)
FILE(GLOB SOURCE_FILES_CPP "${PROJECT_SOURCE_DIR}/src/*.cpp")
FILE(GLOB SOURCE_FILES_C "${PROJECT_SOURCE_DIR}/src/*.c")
 
 
# 设定头文件路径
include_directories(include)
#include_directories("路径1"  “路径2”...)
 
 
# 设定链接库的路径（一般使用第三方非系统目录下的库）
#link_directories(build)
#link_directories("路径1"  “路径2”...)

# 打印
message(STATUS "SOURCE_FILES:" ${SOURCE_FILES_CPP} ${SOURCE_FILES_C})

# 添加子目录,作用相当于进入子目录里面，展开子目录的CMakeLists.txt
# 同时执行，子目录中的CMakeLists.txt一般是编译成一个库，作为一个模块
# 在父目录中可以直接引用子目录生成的库
#add_subdirectory(math)
 
# 生成动/静态库
#add_library(    动/静态链接库名称      SHARED/STATIC(可选，默认STATIC)      源码列表    )
# 可以单独生成多个模块
 
# 指定生成静态库
#add_library(math STATIC ${SRC_LIST_CPP} ${SRC_LIST_C})
# 指定生成动态库
#add_library(math SHARED ${SRC_LIST_CPP} ${SRC_LIST_C})

#包含外部库 -I -L
include_directories(lib/izlog/nclude)
link_directories(lib/zlog/lib)
#link_libraries(zlog)  ??????

#查找外部库，若没有，则将NO_DEFAULT_PATH赋值给zlog_LIB 
find_library (zlog_LIB zlog lib/ NO_DEFAULT_PATH)
#打印
message(STATUS "LIB_FILES:" ${zlog_LIB})

#生成可执行文件
add_executable(mytest ${SOURCE_FILES_CPP} ${SOURCE_FILES_C})
#比如：add_executable(  hello_world    ${SOURCE_FILES}  )

# 将第三方的库链接到可执行文件（可选）(-lptread -lxx)
target_link_libraries(mytest zlog -lpthread)









