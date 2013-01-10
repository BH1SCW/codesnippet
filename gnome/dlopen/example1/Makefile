# This file is part of the C++ dlopen mini HOWTO. You can find the complete
# HOWTO and/or updated versions at
# http://www.isotton.com/howtos/C++-dlopen-mini-HOWTO/
#
# Copyright 2002-2006 Aaron Isotton <aaron@isotton.com>
# Licensed under the GNU GPL.

example1: main.cpp hello.so
	$(CXX) $(CXXFLAGS) `pkg-config gtk+-2.0 --cflags --libs` -o example1 main.cpp -ldl

hello.so: hello.cpp
	$(CXX) $(CXXFLAGS) -fPIC -shared  `pkg-config gtk+-2.0 --cflags --libs` -o hello.so hello.cpp

clean:
	rm -f example1 hello.so

.PHONY: clean
