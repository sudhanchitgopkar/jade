jade:
	g++ -o run main.cpp -I include/ toolbox/line.cpp toolbox/2dTransform.cpp -L lib/ -l SDL2-2.0.0 -std=c++0x

randLines:
	g++ -o run implementations/randLines.cpp -I include/ toolbox/line.cpp toolbox/2dTransform.cpp -L lib/ -l SDL2-2.0.0 -std=c++0x

lineTester:
	g++ -o run implementations/lineTester.cpp -I include/ toolbox/line.cpp toolbox/2dTransform.cpp -L lib/ -l SDL2-2.0.0 -std=c++0x

randLineTester:
	g++ -o run implementations/randLineTester.cpp -I include/ toolbox/line.cpp toolbox/2dTransform.cpp -L lib/ -l SDL2-2.0.0 -std=c++0x
walk:
	g++ -o run implementations/walk.cpp -I include/ toolbox/line.cpp toolbox/2dTransform.cpp -L lib/ -l SDL2-2.0.0 -std=c++0x

clean:
	rm -f *.o run *~

# COMPILE COMMANDS
# g++ -c toolbox/2dTransform.cpp -I include/ toolbox/line.cpp -L lib/ -l SDL2-2.0.0 -std=c++0x -c
