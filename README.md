# AMS Board Code Version 4
The repositry stores a simplified version of the AMS code based on usage either Arduino or Teensu 2.0.

Main implementation of the AMS check routine is stored within AMS_Test folder.

libs directory contains usefull libraries, most likely used to set and debug board if necessary.

Run to produce main.hex file:
```
make
```
Use teensy.exe to start the loader and select the .hex file compiled. Then enter programming mode by pressing a single button existed on the Teensy. Click Flash, followed by reboot.

On Linux machine run this to use consile loader:
```
make build
```

## AMS_Test Old Re;ay trigger code.
AMS_Test.c also contains code for triggering the relays on the old ways of original AMS designed by Alistair.