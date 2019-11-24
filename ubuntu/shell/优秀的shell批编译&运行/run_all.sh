## Runs all the build binaries from bin/ folder

find bin/ -name '*.cpp.bin' -exec sh ./run.sh ./{} \; #改了run.sh
#find bin/ -name '*.cpp.bin' -exec sh ./run.sh ./{} \;
