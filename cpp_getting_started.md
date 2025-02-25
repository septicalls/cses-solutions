# C++ Getting Started

## Installing a C++ compiler
Make sure you have a C++ compiler like `g++` or `clang++`.
On Debian based distros (Ubuntu, Pop!_OS etc) you can get all necessary build tools using
```shell
# apt update
# apt install build-essential
```
If you're using some other linux distro you definitely know how to do that ¬‿¬

On Windows the standard way is to install Microsoft Visual C++ in Visual Studio Installer but it's too big. Better use WSL or MinGW

## An example C++ workflow

### Workflow
clone the repo
```shell
$ git clone https://github.com/YOUR_USERNAME/cses-repository
$ cd cses-repository
```

code the solution
```shell
$ vim missing_number.cpp
```
compile and run
```shell
$ g++ missing_number.cpp -o missing_number
$ ./missing_number
```

commit and push on successfull completion
```shell
$ git add missing_number.cpp
$ git commit -m "solve missing_number.cpp"
$ git push
```

You can redirect the input stream to read from a file instead of typing it again and again during each run with
```shell
$ ./missing_number < input.txt
```

Similarly you could redirect the output to a file and `diff` it with a file containing actual_output to check the correctness
```shell
$ ./missing_number < input.txt > output.txt
$ diff actual_output.txt output.txt
# or in a single command without a temporary file
$ ./missing_number < input.txt | diff - actual_output.txt
```
Do `.gitignore` your temporary input and output files

### An xmake based C++ workflow
manually passing compiler options to `g++` or `clang++` like below is too lengthy and messy
```shell
$ g++ -std=c++20 -Wall -Wextra -Wpedantic -Wshadow -g -fsanitize=address,undefined missing_number.cpp -o missing_number
```
> checkout [Diagnostic section of hackingcpp Beginner's Guide](https://hackingcpp.com/cpp/diagnostics.html) for more info on the above flags

Also you'll have to manually install and link other libraries you may use. If you want your code editor's LSP (Language Server Protocol) to pick up these extra compiler flags you'll have to create a `compile_commands.json` file (You can generate one with [Bear](https://github.com/rizsotto/Bear)). You could use a good old `Makefile` to wrap over all these build details but I personally find using a simple build tool like xmake much easier.

You can find the installation instructions for xmake [here](https://xmake.io/#/guide/installation)

To initialize a xmake project in the repo run
```shell
$ xmake create -l c++ -P .
```
Here's my xmake config file with flags and tools I commonly use,
> xmake.lua
```lua
add_rules("mode.debug", "mode.release")

set_languages("c++20") -- sets the compiler to use c++ 20
set_policy("build.sanitizer.address", true) -- links address sanitizer that helps you catch invalid memory usage, leaks etc early
set_policy("build.sanitizer.undefined", true) -- links undefined behavior sanitizer that helps you catch UBs like integer overflows, dereferencing null pointers etc
add_rules("plugin.compile_commands.autoupdate") -- automatically generates a `compile_command.json` for you
add_cxxflags("-Wall -Wextra -Wpedantic -Wshadow -g") -- enables stricter warnings. As a bonus due to generated `compile_command.json`, you're LSP will also report these warnings

-- add_requires("dbg-macro")
-- add_packages("dbg-macro")

for _, file in ipairs(os.files("src/*.cpp")) do
  local name = path.basename(file)

  target(name)
    set_kind("binary")
    add_files(file)
end
```
### Workflow
code the solution
```shell
$ vim src/missing_number.cpp
```

build and run
```shell
$ xmake && xmake run missing_number
```

### A better way to print STL classes like `std::vector` for debugging
You'll find yourself writing code to print vectors, deques etc for debugging. To save you time you could use this library [dbg-macro](https://github.com/sharkdp/dbg-macro)

install `dbg-macro` with xmake
```shell
$ xmake install dbg-macro
```

uncomment these lines in `xmake.lua`
```lua
add_requires("dbg-macro")
add_packages("dbg-macro")
```
you get the `dbg(...)` macro by `#include "dbg.h"`. Make sure to remove/comment these before you submit as it's for local debugging.

## Some resources on C++
- [hackingcpp Beginner's Guide](https://hackingcpp.com/cpp/beginners_guide.html)
- [cppreference](https://en.cppreference.com)
