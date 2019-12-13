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
