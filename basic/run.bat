@echo off

:loop
   echo %%x
   python gen.py > input
   ac.exe < input > ac
   wa.exe < input > wa
   fc ac wa 
if not errorlevel 1 goto loop