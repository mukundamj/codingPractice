CXX=g++
CPPFLAGS=-std=c++11
ODIR=obj

arrayUtil: main.o ArrayUtil.o
	@echo "Linking $<"
	$(CXX) $(CPPFLAGS) -o $@ main.o ArrayUtil.o

main.o: main.cpp ArrayUtil.h
	@echo "Compiling $<"
	$(CXX) $(CPPFLAGS) -c -o $@ $<

ArrayUtil.o: ArrayUtil.cpp ArrayUtil.h
	@echo "Compiling $<"
	$(CXX) $(CPPFLAGS) -c -o $@ $<

.PHONY: clean

clean:
	rm *.o
