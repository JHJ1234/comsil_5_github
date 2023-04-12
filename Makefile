.SURFFIXES : .cpp .o
CXX=g++
CPPFLAGS=-g -std=c++14
HEDRS=LinkedList.h Stack.h
SRCS=main.cpp
OBJS=$(SRCS:.cpp=.o)
TARGET=a.out

all : $(TARGET)

$(TARGET) : $(OBJS) $(HEDRS)
	$(CXX) $(CPPFLAGS) -o $@ $(OBJS)

clean :
	rm -rf $(OBJS) $(TARGET)