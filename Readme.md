# **SOFTWARE CONTROLLER FOR VEHICLES**

## Carleton University

### Authors
[Pedro Coser](https://github.com/PCoser)
[Unnati Thakkar](https://github.com/unnati9979)

### Table of Content
---
- [Introduction](#Introduction)

- [Release](#Release)

- [Files Management](#Files-Management)

- [Steps to Run Simulation](#Steps-To-Run-Simulation) 

- [More Information](#More-Information)

### Introduction

The purpose of this software is to show the implementation of a real-time controller of a vehicle.
For that, a simulator was implemented for emulating the behaviour of a vehicle passing commands to the controller and tracking its response.
The vehicle system performs the exchange of information between devices using a bus protocol. 

### Release
1st stable release: Communication of all devices where implemented; Simulator with vehicle dynamic equations.

### Files Management

+ data [Here is the input data for the simulator]
Trajectory.csv  

+ doc [Here you will find the details of the software]

+ src [Here you will find the source code]
1. Simulator  
1.1. differential\_time.c  
1.2. driver\_attitude.c  
1.3. information\_display.c  
1.4. position\_integration.c  
1.5. vehicle\_angle.c  
1.6. vehicle\_velocity.c  

2. System  
2.1. brake\_actuator.c  
2.2. brake\_pedal\_sensor.c  
2.3. bus\_controller.c  
2.4. controller.c  
2.5. direction\_actuator.c  
2.6. fuel\_actuator.c  
2.7. gas\_pedal\_sensor.c  
2.8. steering\_wheel_sensor.c  
2.9. wheel\_sensor.c  

3. main.c

+ include [This folder contains the header files]
1. header.h
2. main.h

+ test [This folder contains unit tests for every source code]
1. Simulator  
1.1. differential\_time  
1.1.1. makefile  
1.1.2. main.c  
1.2. driver\_attitude  
1.2.1. makefile  
1.2.2. main.c  
1.3. information\_display  
1.3.1. makefile  
1.3.2. main.c  
1.4. position\_integration  
1.4.1. makefile  
1.4.2. main.c  
1.5. Simulator  
1.5.1. makefile  
1.5.2. main.c  
1.6. vehicle\_angle  
1.6.1. makefile  
1.6.2. main.c  
1.7. vehicle\_velocity  
1.7.1. makefile  
1.7.2. main.c  

2. System  
2.1. brake\_actuator.c  
2.1.1. makefile  
2.1.2. main.c  
2.2. brake\_pedal\_sensor.c  
2.2.1. makefile  
2.2.2. main.c  
2.3. bus\_controller.c  
2.3.1. makefile  
2.3.2. main.c  
2.4. controller.c  
2.4.1. makefile  
2.4.2. main.c  
2.5. direction\_actuator.c  
2.5.1. makefile  
2.5.2. main.c  
2.6. fuel\_actuator.c  
2.6.1. makefile  
2.6.2. main.c  
2.7. gas\_pedal\_sensor.c  
2.7.1. makefile  
2.7.2. main.c  
2.8. steering\_wheel_sensor.c  
2.8.1. makefile  
2.8.2. main.c  
2.9. wheel\_sensor.c  
2.9.1. makefile  
2.9.2. main.c  
2.10. System  
2.10.1. makefile     
2.10.2. main.c    

### Steps to Run Simulation

1. Requirements:
 - Windows 10 or Unix;
 - Cygwin for compiling if in Windows;
 - GCC Compiler

2. Download:  
Copy the repository in your system.

3. Install:  
On Cygwin terminal or Unix point to the right directory and type
	
  ```
  make compile
  ```

4. How to run:

  ```
  make run
  ```

5. Unit testing:
  ```
  make testing
  ```
  The log files will be stored in the folder /test.
  For more information refer the Developer's Manual [here](https://github.com/PCoser/Software-Programing-in-C/doc/Developer_manual.md)

### More Information

The user manual is available [here](https://github.com/PCoser/Software-Programing-in-C/blob/master/doc/User_manual.md)

The developer manual is available [here](https://github.com/PCoser/Software-Programing-in-C/blob/master/doc/Developer%20Manual.md)

For more details about the implementation refer [here](https://github.com/PCoser/Software-Programing-in-C/tree/master/doc/Doxygen) the Doxygen documentation.