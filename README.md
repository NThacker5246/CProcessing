# CProcessing
CProcessing is an environment for running Processing sketches written in C++.

Dependies:
1. SFML
2. OpenCL

Installing libs using ucrt64 (m2sys, windows)
```
pacman -S mingw-w64-ucrt-x86_64-sfml
```

Compile:
```
git clone "https://github.com/NThacker5246/CProcessing.git"
cd CProcessing
g++ -I./include main.cpp -o main.exe ./*.dll
./main.exe
```

Documentation will be written on release
