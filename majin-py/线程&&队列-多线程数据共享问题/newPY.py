#!/usr/bin/python3
import threading
    """
    FIFO（先入先出)队列Queue
    LIFO（后入先出）队列LifoQueue
    优先级队列 PriorityQueue
    """
from queue import Queue
from time import *


def thread_job(q):
    print('This is a thread of %s' % threading.current_thread())                   
    while True:
        if q.empty() :
            continue
        s_t = time.time()
        n_t = q.get(False) ##q.get_nowait()
       # print(2,s_t, q.get(False), q.get(False))
        print("majin  thread_job ",s_t-n_t[0],s_t,n_t[0])   
              
def run():
    """execute the main loop"""
    q = Queue()##q = Queue(3) 设置队列最大长度 小于或者等于0，队列大小没有限制
    t = threading.Thread(target=thread_job, args=(q,), name= "sss" )
    t.start()

    while True:
    
        s_t = time.time()
        
        if q.full():
            q.queue.clear() 
        q.put_nowait([s_t,1,[5,6],'string'])  
        print(1,s_t)
        
        time.sleep(1)
        
    sys.stdout.flush()
if __name__ == "__main__":
    run()
