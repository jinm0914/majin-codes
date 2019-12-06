#ubuntu shell

多终端，多任务
./1.sh &  #后台运行子脚本，当前窗口打印，还有fork()等方式

gnome-terminal --tab -e "./2.sh"; #开启新终端运行子脚本，新终端打印

sleep x 睡眠等待x秒

wait 等待之前的子进程结束，详情见 ：shell/README.md
