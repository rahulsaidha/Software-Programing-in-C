## Developer Manual

### Table of Content
---
- [Introduction](#Introduction)

- [Installation](#Installation)

- [Functionalities](Functionalities)

- [Input data requirements](Input-data-requirements)

- [Program flow](Program-flow)

- [Program division](Program-division)

- [Unit Testing](Unit-Testing)

- [More Information](#More-Information)

### Introduction

The purpose of this software is to show the implementation of a real-time controller of a vehicle.
For that, a simulator was implemented for emulating the behaviour of a vehicle passing commands to the controller and tracking its response.
The vehicle system performs the exchange of information between devices using a bus protocol. 

### Installation

1. Requirements:
 - Windows 10 or Unix;
 - Cygwin for compiling if in Windows;
 - GCC Compiler

2. Download:  
Copy the repository in your system.

3. Install:  
On Cygwin terminal or Unix point to the right directory and type:
	
  ```
  make compile
  ```

### Functionalities

The System is the part of the software that allows the exchange of information between devices in a real-time system. 
The Simulator is the part responsible for testing the System, emulating the behaviour of a vehicle.

### Input data requirements

The trajectory data should be a .csv file with the name: Trajectory.csv. The file should have a header with the following columns: Time, X, Y, Speed. Respectively the time, position in X and Y and maximum speed in the sector.   

### Program flow
![Diagram](https://github.com/PCoser/Software-Programing-in-C/blob/master/doc/Vehicle.jpeg)

* On the initialization, the input data is loaded, the variable of the vehicle are initialized. 
* On a continuous loop, the software swap between the Simulator and the System sub-routines.
* On the Simulator sub-routine, the time passed since the last call is computed in order to update the dynamic equations of the vehicle.
* On the Simulator sub-routine is called a function (driver_attitude) to read the information in the data and perform the actions in the vehicle.
* On the Simulator sub-routine is called a function (information_display) to show the current status on the simulator on the screen, also it stores this information in a file for posterior plotting.  
* On the System sub-routine, all the devices are called one at time. 
* The loop finishes when there is no more input on the data.

### Program division
The software is divided into Simulator and System, the following list shows how the functions are divided:  
Simulator:  
 - differential\_time.c  
 - driver\_attitude.c  
 - information\_display.c  
 - position\_integration.c  
 - vehicle\_angle.c  
 - vehicle\_velocity.c  

System:  
- brake\_actuator.c  
- brake\_pedal\_sensor.c  
- bus\_controller.c  
- controller.c  
- direction\_actuator.c  
- fuel\_actuator.c  
- gas\_pedal\_sensor.c  
- steering\_wheel\_sensor.c  
- wheel\_sensor.c   

### Unit Testing
The project has used a black-box testing strategy for unit testing. To see or modify the test cases open the main.c in the folder of the desired function on /test.
There is a unit test for each function, also an integrating test for the sub-routine System and one or the sub-routine Simulator.

To run all the unit tests:   
  ```
  make testing
  ```

To run individual unit test:
  ```
  ( cd test/System/<desired directory> && make )  
  or  
  ( cd test/Simulator/<desired directory> && make ) 
  ```
The log file will be stored inside the respective folder on /test.

### More information

For more details about the implementation refer [here](https://github.com/PCoser/Software-Programing-in-C/doc/Doxygen) the Doxygen documentation.