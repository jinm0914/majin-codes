#!/usr/bin/env python3
# -*- coding:utf-8 -*- 
from PyQt5 import QtCore, QtGui
import sys
from PyQt5.QtCore import QEventLoop, QTimer
from PyQt5.QtWidgets import QApplication, QMainWindow
  
from Ui_ControlBoard import Ui_MainWindow
 
class Mythread(QtCore.QThread):
    sinOut = QtCore.pyqtSignal(str)
    def __init__(self, parent=None,arg=None):
        super(Mythread, self).__init__(parent)
        self.working = True
        self.num = 0
        self.arg=arg

    def tail(self):
        f=open('myeasylogDefault.log')
        # 移动到文件的EOF最后
        f.seek(0,2) #************jinma
        while 1:
            # 读取文件中新的文本行
            line = f.readline()
            if not line:continue
            # yield 出每一行的数据
            yield line

    def grep(self,lines,search_text):
        for line in lines:
            if search_text in line:
                yield line
            
    def run(self):
        flog = self.tail()
        py_lines = self.grep(flog,'MAJIN')
        for line in py_lines:
            print(line)  
       
     
      
class EmittingStr(QtCore.QObject):
    textWritten = QtCore.pyqtSignal(str) #定义一个发送str的信号
    def write(self, text):
      self.textWritten.emit(str(text))
  
class ControlBoard(QMainWindow, Ui_MainWindow):
  def __init__(self):
    super(ControlBoard, self).__init__()
    self.setupUi(self)
    # 下面将输出重定向到textBrowser中
    sys.stdout = EmittingStr(textWritten=self.outputWritten)
    sys.stderr = EmittingStr(textWritten=self.outputWritten)
    print(sys.stdout)
  
    self.pushButton.clicked.connect(self.bClicked)
  
  def outputWritten(self, text):
    cursor = self.textBrowser.textCursor()
    cursor.movePosition(QtGui.QTextCursor.End)
    cursor.insertText(text)
    self.textBrowser.setTextCursor(cursor)
    self.textBrowser.ensureCursorVisible()
  
  def bClicked(self):
    self.textBrowser.clear()
   
  
if __name__ == "__main__":
  app = QApplication(sys.argv)
  win = ControlBoard()
  win.show()
  # 创建一个新的线程
  thread = Mythread(arg=win)
  thread.start()
  
  sys.exit(app.exec_())
