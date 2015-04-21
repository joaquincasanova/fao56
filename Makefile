EXEC = fao56
SRC = fao56.cpp
INC_DIR = 
LIB_DIR =
LDLIBS =
CC = g++
CFLAGS = -Wall
LFLAGS = #-L$(LIB_DIR) $(LDLIBS)
IFLAGS = #-I$(INC_DIR)
OBJS = $(SRC:%.cpp=%.o)

all:$(EXEC)

$(EXEC) : $(OBJS)
	$(CC) $(OBJS) $(LFLAGS) -o $(EXEC)

$(OBJS) : $(SRC)
	$(CC) $(CFLAGS) $(IFLAGS) -c $(SRC)

clean:
	rm $(OBJS) *~
