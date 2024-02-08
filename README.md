# Build your portfolio project (Week 2): MVP Complete
# Plan
1. [Requirements](#Requirements)
2. [Installation](#Installation)
3. [Compilation](#Compilation)
4. [Use](#Use)
## Requirements
The run this project and get a overview of my maze project. You need first to have ``SDL2`` install in your computer, you will need also ``gcc`` and ``make`` to make the compilation of the project more easy.
## Installation
On linux you can install ``gcc`` by `sudo apt-get install build-essential` after that we need to install `sdl2` by following this guide [Install SDL2 on linux](https://lazyfoo.net/tutorials/SDL/01_hello_SDL/linux/index.php). And finally we need to have `make` install on linux `sudo apt install make`.
## Comiplation
To compile this project we need to use gcc and also link the sdl lib to our project. To make the things easy we have create a [Makefile](./README.md) to avoid running the command by ourself.
On this file we have a target ``all`` allow us to build all our `*.c` files to `.o` files.
****
After that we need to run the [prog](./prog) file to see the render of our project.
![render](./assets/renderr.png)
## Use
To move the player you just need to press to the key `w` or `s` and also use `a` or `d` to change the direction.