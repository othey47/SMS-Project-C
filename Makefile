# Compiler and flags
CC = gcc
CFLAGS = -Wall -Wextra -std=c11 -Iinclude

# Project structure
SRCDIR = src
INCDIR = include
BUILDDIR = build
TARGET = SMS

# Source and object files
SRCS = $(wildcard $(SRCDIR)/*.c)
OBJS = $(patsubst $(SRCDIR)/%.c,$(BUILDDIR)/%.o,$(SRCS))

# Default rule
all: $(TARGET)

# Link object files into binary
$(TARGET): $(OBJS)
	$(CC) $(CFLAGS) -o $@ $(OBJS)

# Compile .c to .o inside build/
$(BUILDDIR)/%.o: $(SRCDIR)/%.c | $(BUILDDIR)
	$(CC) $(CFLAGS) -c $< -o $@

# Ensure build directory exists
$(BUILDDIR):
	mkdir -p $(BUILDDIR)

# Clean up
clean:
	rm -rf $(BUILDDIR) $(TARGET)

# Run program
run: $(TARGET)
	./$(TARGET)
