CXX = g++-13
CXXFLAGS = -std=c++23
TARGETS = adaptors alg1 alg2 findif rangesort normalsort

all: $(TARGETS)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

run-%: %
	./$<

clean:
	rm -f $(TARGETS)
