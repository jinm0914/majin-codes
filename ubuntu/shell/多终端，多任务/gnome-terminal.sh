#!/bin/bash
gnome-terminal --tab -e "echo ss" #执行结束后退出终端

sleep 2 #等待2s,可以用于程序启动顺序

gnome-terminal --window --tab --window --tab --tab #打开两个，第一个两个tab，第二个3个tab

gnome-terminal -e 'bash -c "ls; exec bash"' #执行结束后不退出终端

gnome-terminal -x bash -c "ls; exec bash"  # x 执行一次


