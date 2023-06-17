# Queuing_System_Simulator

This project is a simulation program that models a queuing system. It simulates the flow of messages through a system consisting of clients, gateways, and servers.This simulator models a queuing system using the M/M/1 and M/M/1/k queueing models. It simulates the arrival and departure of messages in the system, calculates various performance metrics such as average waiting time and average system time, and saves the simulation results to a CSV file.

M/M/1 represents a single-server queueing system with Poisson arrivals and exponential service times, while M/M/1/k represents a single-server queueing system with limited capacity. The simulator allows for varying arrival rates (lambda), service rates (mu), number of servers, and system capacity.

Limitations:

The simulator assumes that the arrival and service processes follow exponential distributions, which may not always accurately represent real-world scenarios.
It does not consider factors such as priority scheduling, preemptive scheduling, or multiple queues.
The simulator assumes that there is no correlation between the arrival and service times of messages.
It does not take into account external factors that may impact the queueing system, such as network delays or packet loss.
The simulation results may vary based on the selected simulation time and random number generation.
The simulator does not provide real-time visualization or interactive features for analysis.
It's important to carefully consider these limitations and assess whether the simulator meets the specific requirements and assumptions of your particular queuing system scenario. The simulation is implemented in C++.

## Project Structure

The project structure is organized as follows:

- **obj**: This directory contains the compiled object files generated during the build process.
- **src**: This directory contains the source code files of the simulation program.
  - client.cpp: Contains the implementation of the Client class.
  - engine.cpp: Contains the implementation of the Engine class.
  - event.cpp: Contains the implementation of the main simulation logic.
  - event.hpp: Contains the header file defining the Event class.
  - gateway.cpp: Contains the implementation of the Gateway class.
  - message.cpp: Contains the implementation of the Message class.
  - server.cpp: Contains the implementation of the Server class.
- **Makefile**: The Makefile used to compile and build the simulation program.
- **plot_graphs.py**: A Python script that plots graphs using the simulation results.
- **simulation_results.csv**: A CSV file that stores the results of the simulation runs.
- **README.md**: This file, providing an overview of the project and its structure.

## Getting Started

To compile and run the simulation program, follow these steps:

1. Make sure you have a compatible C++ compiler installed.
2. Open a terminal and navigate to the project directory.
3. Run the command `make` to build the simulation program.
4. After successful compilation, execute the generated `simulation` executable.

## Plotting Graphs

To visualize the simulation results, you can use the `plot_graphs.py` script. This script reads the `simulation_results.csv` file, performs data analysis, and plots graphs using libraries such as pandas, matplotlib, and seaborn.

To run the script, make sure you have Python installed. Then, run the command `python plot_graphs.py` in the project directory. The graphs will be displayed on the screen.

## Contributing

Contributions to this project are welcome. If you find any issues or have ideas for improvements, please open an issue or submit a pull request.

