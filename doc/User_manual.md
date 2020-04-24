## User Manual

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

### How to use this software
The Simulation can be performed typing on the Unix/Cygwin console:  

  ```  
  make run  
  ```  

The results are shown on the screen. A log.csv file is created and this information can be plotted using a spreadsheet.
Another option to generate plots is using a python script (show_results.py) provided with the software. If Python 3.7 is installed in your system, call it typing:  

 ```
 python show_results.py
 ```  

Then, the plots are saved in .png images in the folder /data.

To use other data: Copy file with the trajectory in the folder /data.   

The trajectory data should be a .csv file with the name: Trajectory.csv. The file should have a header with the following columns: Time, X, Y, Speed. Respectively the time, position in X and Y and maximum speed in the sector.