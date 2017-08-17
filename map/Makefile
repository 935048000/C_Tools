#Makefile

TARGET := maptest
RM := rm

CC := gcc

MK := make

SRCS :=  map.c maptest.c

OBJS := $(subst .c,.o,$(SRCS))


$(TARGET): $(OBJS)
	$(CC) $(OBJS) -o $@

default: 
	$(MK) $(TARGET)

clean: 
	$(RM) $(OBJS) $(TARGET)
