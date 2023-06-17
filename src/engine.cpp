// engine.cpp

#include "event.hpp"
#include <fstream>

Engine::Engine(double lambda, double mu, int numServers, int capacity)
    : lambda(lambda), mu(mu), numServers(numServers), capacity(capacity) {}

// Constructor for the Engine class.
// Initializes the arrival rate (lambda), service rate (mu), number of servers, and capacity.

// Parameters:
// - lambda: The arrival rate of messages.
// - mu: The service rate of the servers.
// - numServers: The number of servers in the system.
// - capacity: The maximum capacity of the gateway.

double Engine::exponentialDistribution(double rate) {
    std::random_device rd;
    std::mt19937 gen(rd());
    std::exponential_distribution<double> dist(rate);

    double u;
    do {
        u = dist(gen);
    } while (u == 0.0);

    return -log(u) / rate;
}

// Generates a random value from an exponential distribution.

// Parameters:
// - rate: The rate parameter of the exponential distribution.

void Engine::runSimulation(double simulationTime) {

    double currentTime = 0.0;
    double nextArrivalTime = exponentialDistribution(lambda);
    double nextDepartureTime = std::numeric_limits<double>::infinity();

    std::vector<Message> gateway;

    int messagesInSystem = 0;
    int totalMessages = 0;
    int droppedMessages = 0;

    Client clientObj(lambda);
    Gateway gatewayObj(lambda, capacity);
    Server serverObj(mu, numServers);

    while (currentTime < simulationTime) {
        if (nextArrivalTime < nextDepartureTime) {
            currentTime = nextArrivalTime;

            clientObj.processDeparture(currentTime, gateway, messagesInSystem, nextArrivalTime, totalMessages, droppedMessages, capacity);

            nextArrivalTime = currentTime + exponentialDistribution(lambda);
        } else {
            currentTime = nextDepartureTime;

            if (messagesInSystem >= numServers) {
                Message departureMessage(totalMessages++, currentTime, Message::MESSAGE_DEPARTURE);
                gateway.push_back(departureMessage);

                nextDepartureTime = currentTime + exponentialDistribution(mu);
            } else {
                nextDepartureTime = std::numeric_limits<double>::infinity();
            }
        }

        gatewayObj.processArrival(currentTime, gateway, messagesInSystem, totalMessages, droppedMessages);
        serverObj.processSelection(currentTime, gateway, messagesInSystem, nextDepartureTime, totalMessages);
    }

    // Calculate metrics
    double averageMessagesInSystem = static_cast<double>(totalMessages) / simulationTime;
    double averageMessagesInQueue = averageMessagesInSystem - static_cast<double>(numServers) / mu;

    double averageWaitingTime = averageMessagesInQueue / lambda;
    double averageSystemTime = averageMessagesInSystem / lambda;

    std::cout << "Simulation Results:" << std::endl;
    std::cout << "===================" << std::endl;
    std::cout << "Lambda (Arrival Rate): " << lambda << " messages per second" << std::endl;
    std::cout << "Mu (Service Rate): " << mu << " messages per second" << std::endl;
    std::cout << "Number of Servers: " << numServers << std::endl;
    std::cout << "System Capacity: " << capacity << " messages" << std::endl;
    std::cout << "Simulation Time: " << simulationTime << " seconds" << std::endl;
    std::cout << "-------------------" << std::endl;
    std::cout << "Total Messages: " << totalMessages << std::endl;
    std::cout << "Dropped Messages: " << droppedMessages << std::endl;
    std::cout << "Average Messages in System: " << averageMessagesInSystem << std::endl;
    std::cout << "Average Messages in Queue: " << averageMessagesInQueue << std::endl;
    std::cout << "Average Waiting Time For a Queue: " << averageWaitingTime << " seconds" << std::endl;
    std::cout << "Average System Time: " << averageSystemTime << " seconds" << std::endl;

    // Save the simulation results to a file (simulation_results.csv)
    std::ofstream outputFile("simulation_results.csv", std::ios::app);
    if (outputFile.is_open()) {
        outputFile << lambda << "," << mu << "," << numServers << "," << capacity << "," << simulationTime << ","; // Write the line to the file
        outputFile << totalMessages  << "," << droppedMessages  << "," << averageMessagesInSystem  << "," << averageMessagesInQueue  << "," << averageWaitingTime  << "," <<  averageSystemTime << "\n";
        outputFile.close();
    }
    else{
        std::cout<<"Error\n";
    }
}

// Runs the simulation for the specified duration (simulationTime).

// Parameters:
// - simulationTime: The duration of the simulation in seconds.

double Engine::getAverageMessagesInSystem() {
    return averageMessagesInSystem;
}

// Returns the average number of messages in the system obtained from the simulation.

