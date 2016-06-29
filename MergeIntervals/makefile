objects = solution.o 
solution : $(objects) 
    gcc -o solution $(objects) -L C:/Program Files/Git/mingw64/lib/ -lstdc++ -std=c++11 -std=gnu++11
$(objects) : solution.cpp 
    gcc -c solution.cpp 
all : 
    ${MAKE} solution
.PHONY : clean 
clean : 
    -del solution.exe $(objects) 