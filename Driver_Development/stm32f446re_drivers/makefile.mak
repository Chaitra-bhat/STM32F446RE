CC=arm-none-eabi-gcc
MACH=cortex-m4
CFLAGS= -Wall -O0 -IInc -IMCAL/GPIO_drivers/Inc -ISWC/LED/Inc -ISWC/Button/Inc

TARGET = stm32f446re_drivers
SRCS = $(wildcard *.c) $(wildcard */*.c) $(wildcard *.h)
OBJS = $(SRCS:.c=.o)

all: $(TARGET)

$(TARGET): $(OBJS)
	$(CC) $(LDFLAGS) -o $@ $(OBJS)
	
%.o: %.c
	$(CC) $(CFLAGS) -c -o $@ $<
	
clean:
	    rm -rf *.o *.elf