# 注意程序只检测新增的日志信息！
#当程序运行时，若warn.log文件中末尾有新增一行，且该一行包含python,该行就会被打印出来
#若打开warn.log时，末尾已经有了一行包含python，该行不会被打印，因为上面是f.seek(0,2)移动到了文件EOF处
#故，上面程序实现了tail -f warn.log | grep 'python'的功能，动态实时检测warn.log中是否新增现了
#新的行，且该行包含python

def tail(f):
    # 移动到文件的EOF最后
    f.seek(0,2) #************jinma
    while 1:
        # 读取文件中新的文本行
        line = f.readline()
        if not line:continue
        # yield 出每一行的数据
        yield line

def grep(lines,search_text):
    for line in lines:
        if search_text in line:
            yield line

if __name__ == '__main__':
    flog = tail(open('log.log'))
    py_lines = grep(flog,'python')
    for line in py_lines:
        print(line)
