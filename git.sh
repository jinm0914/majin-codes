#!/bin/bash
echo " $0 $1 $2 $# ";
if [ "-h" = "$1" ]; then  
    echo "上传 :push + \"更新内容\" ||  下载 : pull";
    exit;
elif [ "push" = $1 ]; then 
    if [ -n "$2" ]; then 
        `git add .`;
        `git commit -m $2`;
        `git push -u origin master`;
    else 
        echo "请输入更新内容";    
    fi

elif [ "pull" = $1 ];then
    `git pull`;
else
    echo "error !!!"
fi

