# File Structurizer
A simple file manager with graphical user interface for managing your storage.
## Development
### Building - Prequesites
   * __Qt 5__ (5.15.1 tested) - [Get Qt from qt.io]("https://www.qt.io/download")
   * __CMake__ (3.19.0 tested, 3.1 minimum required) - [Get CMake from cmake.org]("https://cmake.org/download/")
   * a compiler of your choice (supported by CMake)

### Project setup
---
Start by retrieving the installation directory of your Qt version with the appropriate
compiler you want to build the project with:

```Bash
#E.g.
C:/Qt/5.15.1/msvc2019
```
Set the variable `Qt5InstallPath` inside `cmake/cmake.prjconf` and remove any other directory which
might be there.

---
Create an empty build directory for easier management of files created by CMake. Maintaining a seperate
directory for your builds makes it easier to delete intermediate or output files. In the project setup
is also a source code filter for supported IDE's when the created project files share not the same root with the repositories root.
```Bash
mkdir build
```
---
Run `cmake` to generate the project. Always select the `root`-directory of the repository as your source path.
The build path may differ (but it is recommended to stay inside the repository).
```Bash
#Switch to /build
cd build
#Create project with cmake
cmake -S ../ -B .
```
---
### Building

To build the project you have to choose a way which is supported by your compiler. For example run `make` when you created Makefiles or open a `*.sln`-file when creating a Visual Studio project. Alternatively you always have the option to use cmake to build the project with your chosen compiler.
```Bash
#Switch to /build
cd build
#Build using cmake
cmake --build .
```
The generated binary files will always be in `<BUILD_DIRECTORY>/bin`. Remember that `BUILD_DIRECTORY` is the build directory you set with `-B`.
