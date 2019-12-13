# majin-ubuntu
终端操作

常用工具 tmux 
安装：sudo apt-get install tmux

参考网址：
http://www.ruanyifeng.com/blog/2019/10/tmux.html

tmux ls　　#显示会话列表
 
tmux new -s mysession　　#创建名为mysession的会话
 
tmux a -t mysession　　#连接指定会话
 
tmux a　　连接上一个会话
 
tmux kill-session　　#关闭上次打开的会话
 
tmux kill-session -t virtualdesk　　#关闭会话virtualdesk
 
tmux kill-server　　关闭所有会话
