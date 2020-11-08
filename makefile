all: proj3.exe

ColorClass.o: ColorClass.cpp ColorClass.h
	g++ -c ColorClass.cpp -o ColorClass.o

RowColumnClass.o: RowColumnClass.cpp RowColumnClass.h
	g++ -c RowColumnClass.cpp -o RowColumnClass.o

ColorImageClass.o: ColorImageClass.cpp ColorClass.h ColorImageClass.h \
                   RowColumnClass.h
	g++ -c ColorImageClass.cpp -o ColorImageClass.o

showMenu.o: showMenu.cpp showMenu.h 
	g++ -c showMenu.cpp -o showMenu.o

annotateRect.o: annotateRect.cpp annotateRect.h constants.h \
								RowColumnClass.h selectColor.h ColorClass.h \
								ColorImageClass.h
	g++ -c annotateRect.cpp -o annotateRect.o

selectColor.o: selectColor.cpp selectColor.h ColorClass.h constants.h
	g++ -c selectColor.cpp -o selectColor.o

selectFill.o: selectFill.cpp selectFill.h constants.h
	g++ -c selectFill.cpp -o selectFill.o

proj3.o: proj3.cpp constants.h ColorClass.h ColorImageClass.h \
				 RowColumnClass.h showMenu.h annotateRect.h \
				 selectColor.h selectFill.h
	g++ -c proj3.cpp -o proj3.o

proj3.exe: ColorClass.o RowColumnClass.o ColorImageClass.o \
					 proj3.o showMenu.o annotateRect.o selectColor.o \
					 selectFill.o
	g++ ColorClass.o RowColumnClass.o ColorImageClass.o \
			proj3.o showMenu.o annotateRect.o selectColor.o \
			selectFill.o -o proj3.exe

clean:
	rm -rf ColorClass.o RowColumnClass.o ColorImageClass.o \
			proj3.o showMenu.o annotateRect.o selectColor.o \
			selectFill.o proj3.exe