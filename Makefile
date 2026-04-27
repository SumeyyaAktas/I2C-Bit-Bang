CC := arm-none-eabi-gcc
CFLAGS := -mcpu=arm926ej-s \
           -nostdlib        \
           -nostartfiles    \
           -ffreestanding   \
           -fno-builtin     \
           -Wall            \
           -Wextra          \
           -O0 -g           \
           -Iinclude

LDFLAGS := -T linker.ld -nostdlib

C_SRC := $(shell find . -name "*.c")
S_SRC := $(shell find . -name "*.s")
C_OBJ := $(patsubst ./%.c, build/%.o, $(C_SRC))
S_OBJ := $(patsubst ./%.s, build/%.o, $(S_SRC))
OBJ := $(C_OBJ) $(S_OBJ)
TARGET := build/i2c.elf

all: $(TARGET)

build/%.o: %.c
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

build/%.o: %.s
	@mkdir -p $(dir $@)
	$(CC) $(CFLAGS) -c $< -o $@

$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(LDFLAGS) -o $@ $^

run: $(TARGET)
	qemu-system-arm -M versatilepb \
		-kernel $(TARGET) \
		-nographic

debug: $(TARGET)
	qemu-system-arm -M versatilepb \
		-kernel $(TARGET) \
		-nographic \
		-s -S

clean: 
	rm -rf build/

.PHONY: all run debug clean