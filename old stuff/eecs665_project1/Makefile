CPP = g++ -std=c++11
C_FLAGS = -g -c
LINK = g++ -g
OBJS = main.o

main: $(OBJS) $(LOCAL_UTIL_LIBRARIES)
	$(LINK) -o main $(OBJS)

main.o: main.c++
	$(CPP) $(C_FLAGS) main.c++
