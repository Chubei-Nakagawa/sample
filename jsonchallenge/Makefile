TARGET := jsontest
CC := gcc
CPPFLAGS := -std=c++2a
LDFLAGS := -lstdc++
FILES := anyjson.cpp


all: jsontest

jsontest: $(FILES)
	$(CC) $(CPPFLAGS) $(FILES) -o $(TARGET) $(LDFLAGS)

.PHONY: clean
clean:
ifeq ($(OS),Windows_NT)
	rm $(TARGET).exe
else
	rm $(TARGET)
endif

.PHONY: run
	./$(TARGET)

