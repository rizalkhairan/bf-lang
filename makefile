# Compiler and Linker
CC = gcc
LD = gcc

CFLAGS = -Isrc -Wall -Wextra -g
LDFLAGS =

# Directories
SRCDIR = src
OBJDIR = obj
BINDIR = .

# Executable name
EXECUTABLE = bf

# Source and dependency
SOURCES := $(wildcard $(SRCDIR)/*.c)
OBJECTS := $(patsubst $(SRCDIR)/%.c,$(OBJDIR)/%.o,$(SOURCES))

DEPS := $(OBJECTS:.o=.d)

all: $(BINDIR)/$(EXECUTABLE)

$(BINDIR)/$(EXECUTABLE): $(OBJECTS)
	@echo "Linking..."
	@mkdir -p $(BINDIR)
	$(LD) $(LDFLAGS) $^ -o $@
	@echo "Build finished: $(BINDIR)/$(EXECUTABLE)"

$(OBJDIR)/%.o: $(SRCDIR)/%.c
	@echo "Compiling $<..."
	@mkdir -p $(OBJDIR)
	$(CC) $(CFLAGS) -MMD -MP -c $< -o $@

-include $(DEPS)

.PHONY: all clean

clean:
	@echo "Cleaning project..."
	rm -rf $(OBJDIR) $(BINDIR)
	@echo "Done."