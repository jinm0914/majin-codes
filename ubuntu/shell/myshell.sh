#!/bin/bash
echo " $0 $1 $# ";
mkdir -p mydate;
for((i=1;i<=$1;i++)); do
    echo "print(\"my name is python mypy$i\")" >mydate/mypy$i.py;
    `chmod +x mydate/mypy$i.py`;
done

for((j=1;j<=$2;j++)); do
    echo "print(\"my name is txt txt$j\")" >mydate/txt$j.txt;
done

project_path=$(cd `dirname $0`; pwd)
echo $project_path
for file in `find $project_path/mydate | grep .py`;
do
 echo $file
 python $file;
done

if [ -n "$1" ]; then
    num=$1
else
    num=0
fi
for((k=$num;k<=11;k++)); do
    echo $k
    case $k in
        0)  echo '你选择了 0'
        1)  echo '你选择了 1'
        ;;
        2)  echo '你选择了 2'
        ;;
        3)  echo '你选择了 3'
        ;;
        4)  echo '你选择了 4'
        ;;
        *)  echo '你没有输入 1 到 4 之间的数字'
        ;;
    esac
done

