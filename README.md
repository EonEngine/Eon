# Eon
[![Build Status](https://travis-ci.org/icebit/Eon.svg?branch=master)](https://travis-ci.org/icebit/Eon)

Eon is an open-source game engine.

# Building

Eon has only been tested on Linux as of now, but it should be able to generate Visual Studio projects using CMake.

### Prerequisites

To build Eon on "*nix", you will need the following dependencies:

* `OpenGL` (this should be pre-installed on most systems)
* `SOIL`
* `GLFW3`
* `pkg-config`

On Ubuntu, these can be installed by running

`apt-get install libsoil-dev libglfw3-dev`

Once you have installed these, navigate to the root project directory and run

`make run`

This will build Eon and run the Sandbox test. To run Eon's tests, execute

`make test`
