TARGET := sample
CC := gcc
LDFLAGS := -lstdc++

all: sample

sample: sample.cpp sample_unix.cpp
	$(CC) sample.cpp sample_unix.cpp -o $(TARGET) $(LDFLAGS)

.PHONY: clean
clean:
ifeq ($(OS),Windows_NT)
	rm $(TARGET).exe
else
	rm $(TARGET)
endif

