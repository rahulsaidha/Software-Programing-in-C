# -*- coding: utf-8 -*-
"""
Created on Mon Apr 20 16:39:21 2020

@author: pedro
"""
import pandas as pd
import matplotlib.pyplot as plt

Results = pd.read_csv('data/log.csv')
Results.dropna(inplace=True)
png = '.png'

Trajectory = pd.read_csv('data/Trajectory.csv')

fig, ax = plt.subplots(figsize=(10,8))  # Create a figure and an axes.
ax.plot(Results[['Time']], Results['Brake_pedal'])  # Plot some data on the axes.
ax.plot(Results[['Time']], Results['Brake_act'])  # Plot some data on the axes.
ax.set_xlabel('Time (s)')  # Add an x-label to the axes.
ax.set_ylabel('Action (%)')  # Add a y-label to the axes.
ax.set_title("Brake Pedal activation")  # Add a title to the axes.
ax.legend(('Pedal', 'Actuator')) # Add a legend.
plt.savefig('data/Brake_Pedal_activation'+png)

fig, ax = plt.subplots(figsize=(10,8))  # Create a figure and an axes.
ax.plot(Results[['Time']], Results['Gas_pedal'])  # Plot some data on the axes.
ax.plot(Results[['Time']], Results['Fuel_act'])  # Plot some data on the axes.
ax.set_xlabel('Time (s)')  # Add an x-label to the axes.
ax.set_ylabel('Action (%)')  # Add a y-label to the axes.
ax.set_title("Gas Pedal Activation")  # Add a title to the axes.
ax.legend(('Pedal', 'Actuator')) # Add a legend.
plt.savefig('data/Gas_Pedal_activation'+png)

fig, ax = plt.subplots(figsize=(10,8))  # Create a figure and an axes.
ax.plot(Results[['Time']], Results['V_speed'])  # Plot some data on the axes.
ax.set_xlabel('Time (s)')  # Add an x-label to the axes.
ax.set_ylabel('Speed (m/s)')  # Add a y-label to the axes.
ax.set_title("Speed")  # Add a title to the axes.
ax.legend("Speed") # Add a legend.
plt.savefig('data/Speed'+png)

fig, ax = plt.subplots(figsize=(10,8))  # Create a figure and an axes.
ax.plot(Results[['Time']], Results['X'])  # Plot some data on the axes.
ax.plot(Trajectory[['Time']], Trajectory['X'])  # Plot some data on the axes.
ax.set_xlabel('Time (s)')  # Add an x-label to the axes.
ax.set_ylabel('Distance (m)')  # Add a y-label to the axes.
ax.set_title("Trajectory in X")  # Add a title to the axes.
ax.legend(('Planned', 'Executed'))  # Add a legend.
plt.savefig('data/Trajectory_in_X'+png)

fig, ax = plt.subplots(figsize=(10,8))  # Create a figure and an axes.
ax.plot(Results[['Time']], Results['Y'])  # Plot some data on the axes.
ax.plot(Trajectory[['Time']], Trajectory['Y'])  # Plot some data on the axes.
ax.set_xlabel('Time (s)')  # Add an x-label to the axes.
ax.set_ylabel('Distance (m)')  # Add a y-label to the axes.
ax.set_title("Trajectory in Y")  # Add a title to the axes.
ax.legend(('Planned', 'Executed'))  # Add a legend.
plt.savefig('data/Trajectory_in_Y'+png)

fig, ax = plt.subplots(figsize=(10,8))  # Create a figure and an axes.
ax.plot(Results[['Time']], Results['Steering_wheel'])  # Plot some data on the axes.
ax.plot(Results[['Time']], Results['Direction_act'])  # Plot some data on the axes.
ax.set_xlabel('Time (s)')  # Add an x-label to the axes.
ax.set_ylabel('Action (%)')  # Add a y-label to the axes.
ax.set_title("Direction")  # Add a title to the axes.
ax.legend(('Steering Wheel', 'Direction Actuator'))  # Add a legend.
plt.savefig('data/Direction'+png)

fig, ax = plt.subplots(figsize=(10,8))  # Create a figure and an axes.
ax.plot(Results[['Time']], Results['V_angle'])  # Plot some data on the axes.
ax.plot(Results[['Time']], Results['Wheel_angle'])  # Plot some data on the axes.
ax.set_xlabel('Time (s)')  # Add an x-label to the axes.
ax.set_ylabel('Angle (rad)')  # Add a y-label to the axes.
ax.set_title("Angle of the vehicle")  # Add a title to the axes.
ax.legend(('Vehicle Angle', 'Wheels Angle'))  # Add a legend.
plt.savefig('data/Angle of the vehicle'+png)

fig, ax = plt.subplots(figsize=(10,8))  # Create a figure and an axes.
ax.plot(Results[['X']], Results['Y'])  # Plot some data on the axes.
ax.plot(Trajectory[['X']], Trajectory['Y'])  # Plot some data on the axes.
ax.set_xlabel('Distance in X (m)')  # Add an x-label to the axes.
ax.set_ylabel('Distance in Y (m)')  # Add a y-label to the axes.
ax.set_title("Trajectory X - Y")  # Add a title to the axes.
ax.legend(('Planned', 'Executed'))  # Add a legend.
plt.savefig('data/Trajectory_X_Y'+png)
