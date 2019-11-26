exe = 		\
    config_muti-logger

all     :       $(exe)

$(exe)  :       %:%.cpp
	g++ -o $@ $^ easylogging++.cc -std=c++11 

clean	:
	rm -f press.log* *.o $(exe)

.PHONY : clean all
