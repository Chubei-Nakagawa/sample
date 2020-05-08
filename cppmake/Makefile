TARGET := sample
CC := gcc
CPPFLAGS := -std=c++2a
LDFLAGS := -lstdc++
FILES = sample.cpp info_unix.cpp
ifeq ($(OS),Windows_NT)
	FILES += info_windows.cpp
endif
#ifeq ($(OS),linux-gnu)
#	FILES += info_linux.cpp
#endif

all: $(TARGET)

$(TARGET): $(FILES)
	$(CC) $(CPPFLAGS) $(FILES) -o $(TARGET) $(LDFLAGS)

.PHONY: clean
clean:
ifeq ($(OS),Windows_NT)
	rm $(TARGET).exe
else
	rm $(TARGET)
endif

.PHONY: run
run:
	./$(TARGET)

