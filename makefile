all:
      g++ -std=c++17 reproducer.cpp -o reproducer

clean:
      $(RM) reproducer
