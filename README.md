# ex4
second milestone of Advanced Programming course project.

coding by Eldad Horvitz and Nizan Mandelblit
## Getting Statred

#### GitHub
GitHub link of the project:

* [GithHub Project](https://github.com/NizanMandelblit/ex4).
#### Contributors
* [Nizan Mandelblit](https://github.com/NizanMandelblit)
* [Eldad Horvitz](https://github.com/EldadHorvitz)

#### Prerequisites
in order to properly run the project, the follwoing will need to be provided by the user:
* port number that will given in the command prompt.
* a client server to run the matrix test.
#### Run Command
the expected command line is to be:
```
  g++ -std=c++14 *.cpp -Wall -Wextra -Wshadow -Wnon-virtual-dtor -pedantic -o a.out -pthread
```

## Introduction
#### Goal

The goal of this project is to apply different search algorithms, based on different inputs.

#### Compoistion
we used template classes in order to allow separation between the implementation to the algorithm.