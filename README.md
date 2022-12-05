
Jade is a lightweight graphics package written in C++ using SDL2.
---
### Usage

To begin using Jade, clone this repo using the below command
```console
$ git clone git@github.com:sudhanchitgopkar/jade.git
```
Begin by testing some pre-built `implementations` like a random walk, line tester, or random line generator. You can compile any pre-built implementation using:
```console
$ make [IMPLEMENTATION_NAME_HERE]
```
For example, the random walk implementation can be compiled simply by typing `make walk`.

To run compiled files, simply execute them using:
```console
$ ./run
```
**Note that currently, all compiled files are output as run. To edit this, change the output name in the `Makefile`.**

Building with Jade is simple. Use `main.cpp` as a template to set up your first project with ease, modifying the draw loop referenced in the code. Any code in `main` may be compiled using:
```console
$ make jade
```
and using the `./run` command earlier referenced.

To clean up your compiled binaries and autosave files, simply run:
```console
$ make clean
```
---
Jade is still in its early stages as a graphics package, and all contributions are welcome! Please submit a pull request to contribute, suggest features, or fix bugs. This repository owner and maintainer can be contacted [here](https://sudhan.dev).
