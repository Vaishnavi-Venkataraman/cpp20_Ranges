CXX = g++-13
CXXFLAGS = -std=c++23
TARGETS = normalsort rangesort findif findlast alg1 alg2 adaptors projection insert_range assign_range append_range prepend_range

all: $(TARGETS)

%: %.cpp
	$(CXX) $(CXXFLAGS) -o $@ $<

run-%: %
	./$<

clear:
	rm -f $(TARGETS)
