CXX=g++
OPT=-O0
BINARY=a.out
CODEDIRS = .
INCDIRS = .
# generate files that encode make rules for the .h dependencies
DEPFLAGS=-MP -MD

# Warning 
WARNINGS_FLAGS = -Wall -Wno-reorder -Wno-unused-parameter -Wextra -Wno-sign-compare

# automatically add the -I onto each include directory
CXXFLAGS= $(WARNINGS_FLAGS) -g $(foreach D,$(INCDIRS), -I$(D)) $(OPT) $(DEPFLAGS)
# to generate exactly -I. -I./include/

#for-style iteration (foreach) and regular expression completions (wildcard)
CPPFILES= $(foreach D,$(CODEDIRS),$(wildcard $(D)/*.cpp))

#regular expression replacement
OBJECTS=$(patsubst %.cpp,%.o,$(CPPFILES))

#regular expression replacement for generated .d files for .h files
DEPFILES=$(patsubst %.cpp,%.d,$(CPPFILES))

# Target:DEPENDENCY
all: $(BINARY)
	@echo "Binary generated..."

$(BINARY): $(OBJECTS)
	$(CXX) -o $@ $^
	@echo "Linking..."
	
# regular expression where % is a wild card (anything.o) depends on (anything.cpp)
# kinda forEach
%.o:%.cpp
	@echo "Compiling...$^"
	$(CXX) $(CXXFLAGS) -c -o $@ $^

clean:
	@echo "clean up..."
	rm -rf $(OBJECTS) $(DEPFILES)
	@git status

git-commit:$(clean)
	@echo pushing...
	@git add .
	@git commit -m $(lastword $(CURDIR))
	@git push

run:$(all)
	@echo "removing dependencies..."
	@rm -rf $(OBJECTS) $(DEPFILES)
	@echo "running code..."
	./$(BINARY)
	@echo $(mkfile_path)