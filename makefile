all: proj3.exe

ColorClass.o: ColorClass.cpp ColorClass.h
	g++ -c ColorClass.cpp -o ColorClass.o

RowColumnClass.o: RowColumnClass.cpp RowColumnClass.h
	g++ -c RowColumnClass.cpp -o RowColumnClass.o

ColorImageClass.o: ColorImageClass.cpp ColorClass.h ColorImageClass.h \
                   RowColumnClass.h
	g++ -c ColorImageClass.cpp -o ColorImageClass.o

proj3.o: proj3.cpp constants.h ColorClass.h ColorImageClass.h
	g++ -c proj3.cpp -o proj3.o

proj3.exe: proj3.o ColorClass.o ColorImageClass.o RowColumnClass.o
	g++ proj3.o RowColumnClass.o ColorClass.o ColorImageClass.o -o proj3.exe

clean:
	rm -rf proj3.o RowColumnClass.o ColorClass.o ColorImageClass.o proj3.exe