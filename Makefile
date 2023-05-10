#Compile and link the application
all: main

#run the application
run: main
	./main

#link main.o and student.o to executable main
main: main.o Student.o DomesticStudent.o Istudent.o ToeflScore.o ILinkedList.o DLinkedList.o
	g++ -g -o main main.o Student.o DomesticStudent.o Istudent.o ToeflScore.o ILinkedList.o DLinkedList.o

#compile the main.cpp to main.o
main.o: main.cpp
	g++ -g -c main.cpp

#compile the Student.cpp to Student.o
Student.o: Student.cpp
	g++ -g -c Student.cpp

#compile the DomesticStudent.cpp to DomesticStudent.o
DomesticStudent.o: DomesticStudent.cpp
	g++ -g -c DomesticStudent.cpp

#compile the Istudent.cpp to Istudent.o
Istudent.o: Istudent.cpp
	g++ -g -c Istudent.cpp

#compile the ToeflScore.cpp to ToeflScore.o
ToeflScore.o: ToeflScore.cpp
	g++ -g -c ToeflScore.cpp

#compile the ILinkedList.cpp to ILinkedList.o
ILinkedList.o: ILinkedList.cpp
	g++ -g -c ILinkedList.cpp

#compile the DLinkedList.cpp to DLinkedList.o
DLinkedList.o: DLinkedList.cpp
	g++ -g -c DLinkedList.cpp

#remove built files
clean:
	rm -rf main main.o Student.o DomesticStudent.o Istudent.o ToeflScore.o ILinkedList.o DLinkedList.o *~
