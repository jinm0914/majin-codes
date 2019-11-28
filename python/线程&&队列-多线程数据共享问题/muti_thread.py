#多线程经典案例：生产者和消费者  创建一个队列。，使用线程进行生产数据到队列和消费队列中的数据

from threading import current_thread,Thread

import time

import random

from queue import Queue

queue = Queue(5)  #创建一个长度为5的队列

class  ProducerThread(Thread):

	def  run(self):

		name = current_thread().getName()  #获取线程名称

		global queue

		while True:

			num = random.uniform(1.1,5.4)

			queue.put(num)   #往队列里写入数据

			print("ProducerThread",num,queue.qsize())

			t = random.uniform(0.1,0.9)

			time.sleep(t)

class  ConsumerThread(Thread):
	def run (self):

		name = current_thread().getName()

		global queue

		while True:
			if not queue.empty():

				num = queue.get()

				print("ConsumerThread",num,queue.qsize())

				queue.task_done()

				t = random.uniform(0.1,0.9)

				time.sleep(t)

p1 = ProducerThread(name = 'p1')

# p1.run()    #单独运行run方法，会把主进程当成一个线程来看，执行的代码空间在MainThread主线程中，

p1.start()   #执行start方法，python会创建一个新线程，叫 Thread-1 然后再去调用run()来运行

c1 = ConsumerThread(name = 'c1')

c1.start()

c1.join()
p1.join()
