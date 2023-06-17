// event.cpp

#include "event.hpp"
#include <iostream>
#include <fstream>

int main() {
    double lambda, mu, simulationTime;
    int numServers, capacity;

    // Open the output file and write the header
    std::ofstream outputFile("simulation_results.csv");
    if (outputFile.is_open()) {
        outputFile << "lambda,Mu,Number of Servers,System Capacity,Simulation Time,Total Messages,Dropped Messages,Avg Messages in System,Avg Messages in Queue,Average Waiting Time in Queue,Avg System Time\n"; // Write the header line to the file
        outputFile.close(); // Close the file
    } 
    else {
        std::cout << "Unable to open the file." << std::endl;
    }

      //For MM1
    lambda = 4.0;
    mu = 8.0;
    simulationTime = 100.0;
    numServers = 1;
    capacity = 100;
        
    std::cout << "\nSimulation Type M/M/1\n";
    Engine engineMM1_4(lambda, mu, numServers, capacity);
    engineMM1_4.runSimulation(simulationTime);


    lambda = 6.0;
    Engine engineMM1_6(lambda, mu, numServers, capacity);
    engineMM1_6.runSimulation(simulationTime);

    lambda = 8.0;
    Engine engineMM1_8(lambda, mu, numServers, capacity);
    engineMM1_8.runSimulation(simulationTime);
        

    lambda = 12.0;
    Engine engineMM1_12(lambda, mu, numServers, capacity);
    engineMM1_12.runSimulation(simulationTime);

    //For M/M/1/4
    lambda = 4.0;
    mu = 8.0;
    simulationTime = 100.0;
    numServers = 1;
    capacity = 4;

    std::cout << "\nSimulation Type M/M/1/4\n";
    Engine engineMM14_4(lambda, mu, numServers, capacity);
    engineMM14_4.runSimulation(simulationTime);

    lambda = 6.0;
    Engine engineMM14_6(lambda, mu, numServers, capacity);
    engineMM14_6.runSimulation(simulationTime);

    lambda = 8.0;
    Engine engineMM14_8(lambda, mu, numServers, capacity);
    engineMM14_8.runSimulation(simulationTime);

    lambda = 12.0;
    Engine engineMM14_12(lambda, mu, numServers, capacity);
    engineMM14_12.runSimulation(simulationTime);


    //For M/M/1/8
    lambda = 4.0;
    mu = 8.0;
    simulationTime = 100.0;
    numServers = 1;
    capacity = 8;

    std::cout << "\nSimulation Type M/M/1/8\n";
    Engine engineMM18_4(lambda, mu, numServers, capacity);
    engineMM18_4.runSimulation(simulationTime);

    lambda = 6.0;
    Engine engineMM18_6(lambda, mu, numServers, capacity);
    engineMM18_6.runSimulation(simulationTime);

    lambda = 8.0;
    Engine engineMM18_8(lambda, mu, numServers, capacity);
    engineMM18_8.runSimulation(simulationTime);

    lambda = 12.0;
    Engine engineMM18_12(lambda, mu, numServers, capacity);
    engineMM18_12.runSimulation(simulationTime);

    //For M/M/3/4
    lambda = 4.0;
    mu = 8.0;
    simulationTime = 100.0;
    numServers = 3;
    capacity = 4;

    std::cout << "\nSimulation Type M/M/1/8\n";
    Engine engineMM34_4(lambda, mu, numServers, capacity);
    engineMM34_4.runSimulation(simulationTime);

    lambda = 6.0;
    Engine engineMM34_6(lambda, mu, numServers, capacity);
    engineMM34_6.runSimulation(simulationTime);

    lambda = 8.0;
    Engine engineMM34_8(lambda, mu, numServers, capacity);
    engineMM34_8.runSimulation(simulationTime);

    lambda = 12.0;
    Engine engineMM34_12(lambda, mu, numServers, capacity);
    engineMM34_12.runSimulation(simulationTime); 

    // Add user input option if needed

    /*
    std::cout << "Enter the arrival rate (lambda): ";
    std::cin >> lambda;

    std::cout << "Enter the service rate (mu): ";
    std::cin >> mu;

    std::cout << "Enter the number of servers: ";
    std::cin >> numServers;

    std::cout << "Enter the system capacity: ";
    std::cin >> capacity;

    std::cout << "Enter the simulation time (in seconds): ";
    std::cin >> simulationTime;
    */   
    return 0;
}
