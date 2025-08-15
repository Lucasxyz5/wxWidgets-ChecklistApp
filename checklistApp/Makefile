CXX = g++
CXXFLAGS = -std=c++20 `wx-config --cxxflags`
TARGET = Checklist
SRCS = checklist.cpp occurence.cpp

all: $(TARGET)

$(TARGET): $(SRCS)
	$(CXX) $(CXXFLAGS) -o $(TARGET) $(SRCS) `wx-config --libs`

clean:
	ls | grep -v "\." | grep -v -i makefile | xargs rm

run:
	./$(TARGET)

#g++ -std=c++17 helloworld.cpp -o testprogram `wx-config --cxxflags --libs`