# Compiler
CC = g++
# Compiler flags
CFLAGS = -std=c++11 -Wall
# Source files
SRCS = new_new_operator.cpp init.cpp sum.cpp
# Object files
OBJS = $(SRCS:.cpp=.o)
# Executable name
TARGET = myprogram
# Build rule
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(TARGET)
# Object file rule
%.o: %.cpp
	$(CC) $(CFLAGS) -c $< -o $@
# Clean rule
clean:
	rm -f $(OBJS) $(TARGET)