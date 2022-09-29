g++ -c -o script/number.o NumLib/num.cpp
ar rcs script/libNumber.a script/number.o

g++ -c -fpic -o script/vector.o Dll/vector.cpp -B static -lNumber
g++ -shared -o script/libvector.so script/vector.o

export LD_LIBRARY_PATH="script"
g++ -o script/a.out Test/main.cpp -B dynamic -L script -lvector  -B static -L script -lNumber

./script/a.out

export LD_LIBRARY_PATH=""
