# -*- coding: utf-8 -*-
"""
Created on Mon Apr 20 16:39:21 2020

@author: pedro
"""
import pandas as pd
import matplotlib.pyplot as plt

Results = pd.read_csv('log.csv')
Results.dropna(inplace=True)

Trajectory = pd.read_csv('data/Trajectory.csv')

fig, ax = plt.subplots(figsize=(10,8))  # Create a figure and an axes.
ax.plot(Results[['Time']], Results['Brake_pedal'])  # Plot some data on the axes.
ax.plot(Results[['Time']], Results['Brake_act'])  # Plot some data on the axes.
ax.set_xlabel('Time')  # Add an x-label to the axes.
ax.set_ylabel('%')  # Add a y-label to the axes.
ax.set_title("Brake Pedal")  # Add a title to the axes.
ax.legend()  # Add a legend.
#plt.savefig('Response Time'+version+png)

fig, ax = plt.subplots(figsize=(10,8))  # Create a figure and an axes.
ax.plot(Results[['Time']], Results['Gas_pedal'])  # Plot some data on the axes.
ax.plot(Results[['Time']], Results['Fuel_act'])  # Plot some data on the axes.
ax.set_xlabel('Time')  # Add an x-label to the axes.
ax.set_ylabel('%')  # Add a y-label to the axes.
ax.set_title("Gas Pedal")  # Add a title to the axes.
ax.legend()  # Add a legend.
#plt.savefig('Response Time'+version+png)

fig, ax = plt.subplots(figsize=(10,8))  # Create a figure and an axes.
ax.plot(Results[['Time']], Results['V_speed'])  # Plot some data on the axes.
ax.set_xlabel('Time')  # Add an x-label to the axes.
ax.set_ylabel('m/s')  # Add a y-label to the axes.
ax.set_title("Speed")  # Add a title to the axes.
ax.legend()  # Add a legend.
#plt.savefig('Response Time'+version+png)

fig, ax = plt.subplots(figsize=(10,8))  # Create a figure and an axes.
ax.plot(Results[['Time']], Results['X'])  # Plot some data on the axes.
ax.plot(Trajectory[['Time']], Trajectory['X'])  # Plot some data on the axes.
ax.set_xlabel('Time')  # Add an x-label to the axes.
ax.set_ylabel('m')  # Add a y-label to the axes.
ax.set_title("Trajectory in X")  # Add a title to the axes.
ax.legend()  # Add a legend.
#plt.savefig('Response Time'+version+png)

fig, ax = plt.subplots(figsize=(10,8))  # Create a figure and an axes.
ax.plot(Results[['Time']], Results['Y'])  # Plot some data on the axes.
ax.plot(Trajectory[['Time']], Trajectory['Y'])  # Plot some data on the axes.
ax.set_xlabel('Time')  # Add an x-label to the axes.
ax.set_ylabel('m')  # Add a y-label to the axes.
ax.set_title("Trajectory in Y")  # Add a title to the axes.
ax.legend()  # Add a legend.
#plt.savefig('Response Time'+version+png)


fig, ax = plt.subplots(figsize=(10,8))  # Create a figure and an axes.
ax.plot(Results[['Time']], Results['Steering_wheel'])  # Plot some data on the axes.
ax.plot(Results[['Time']], Results['Direction_act'])  # Plot some data on the axes.
ax.set_xlabel('Time')  # Add an x-label to the axes.
ax.set_ylabel('Radians')  # Add a y-label to the axes.
ax.set_title("Direction")  # Add a title to the axes.
ax.legend()  # Add a legend.
#plt.savefig('Response Time'+version+png)

fig, ax = plt.subplots(figsize=(10,8))  # Create a figure and an axes.
ax.plot(Results[['Time']], Results['V_angle'])  # Plot some data on the axes.
ax.plot(Results[['Time']], Results['Wheel_angle'])  # Plot some data on the axes.
ax.set_xlabel('Time')  # Add an x-label to the axes.
ax.set_ylabel('Radians')  # Add a y-label to the axes.
ax.set_title("Angle")  # Add a title to the axes.
ax.legend()  # Add a legend.
#plt.savefig('Response Time'+version+png)

fig, ax = plt.subplots(figsize=(10,8))  # Create a figure and an axes.
ax.plot(Results[['X']], Results['Y'])  # Plot some data on the axes.
ax.plot(Trajectory[['X']], Trajectory['Y'])  # Plot some data on the axes.
ax.set_xlabel('m')  # Add an x-label to the axes.
ax.set_ylabel('m')  # Add a y-label to the axes.
ax.set_title("Trajectory X - Y")  # Add a title to the axes.
ax.legend()  # Add a legend.
#plt.savefig('Response Time'+version+png)
