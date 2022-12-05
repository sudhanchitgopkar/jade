jade:
	g++ -o run main.cpp -I include/ toolbox/line.cpp -L lib/ -l SDL2-2.0.0 

randLines:
	g++ -o run implementations/randLines.cpp -I include/ toolbox/line.cpp -L lib/ -l SDL2-2.0.0 

lineTester:
	g++ -o run implementations/lineTester.cpp -I include/ toolbox/line.cpp -L lib/ -l SDL2-2.0.0

randLineTester:
	g++ -o run implementations/randLineTester.cpp -I include/ toolbox/line.cpp -L lib/ -l SDL2-2.0.0
walk:
	g++ -o run implementations/walk.cpp -I include/ toolbox/line.cpp -L lib/ -l SDL2-2.0.0

clean:
	rm -f *.o run *~
