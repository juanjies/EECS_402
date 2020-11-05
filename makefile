ColorClass.o: ColorClass.cpp ColorClass.h
'\t'g++ -c ColorClass.cpp -o ColorClass.o

RowColumnClass.o: RowColumnClass.cpp RowColumnClass.h
'\t'g++ -c RowColumnClass.cpp -o RowColumnClass.o

ColorImageClass.o: ColorImageClass.cpp ColorImageClass.h
'\t'g++ -c ColorImageClass.cpp -o ColorImageClass.o

proj3.o: proj3.cpp
'\t'g++ -c proj3.cpp -o proj3.o

proj3.exe: proj3.o ColorClass.o ColorImageClass.o
'\t'g++ proj3.o ColorClass.o ColorImageClass.o -o proj3.exe