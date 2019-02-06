@echo off
g++ -pg test_gprof.cpp -o app
rem g++ -pg 0032.cpp -o app
app.exe
gprof -b app.exe gmon.out