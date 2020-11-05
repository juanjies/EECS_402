ColorClass.o: ColorClass.cpp ColorClass.h
'\t'g++ -c ColorClass.cpp -o ColorClass.o

RowColumnClass.o: RowColumnClass.cpp RowColumnClass.h
'\t'g++ -c RowColumnClass.cpp -o RowColumnClass.o

ColorImageClass.o: ColorClass.h ColorImageClass.cpp ColorImageClass.h
'\t'g++ -c ColorImageClass.cpp -o ColorImageClass.o

proj3.o: proj3.cpp constants.h ColorClass.h ColorImageClass.h
'\t'g++ -c proj3.cpp -o proj3.o

proj3.exe: proj3.o ColorClass.o ColorImageClass.o
'\t'g++ proj3.o RowColumnClass.o ColorClass.o ColorImageClass.o -o proj3.exe

clean:
'\t'rm -rf proj3.o RowColumnClass.o ColorClass.o ColorImageClass.o proj3.exe