// server.cpp

#include "event.hpp"

Server::Server(double mu, int numServers) : mu(mu), numServers(numServers) {}

// Constructor for the Server class.
// Initializes the service rate (mu) and the number of servers in the system.

// Parameters:
// - mu: The service rate of the servers.
// - numServers: The number of servers in the system.

double Server::exponentialDistribution(double rate) {
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

void Server::processSelection(double currentTime, std::vector<Message>& gateway, int& messagesInSystem, double& nextDepartureTime, int& totalMessages) {
    if (messagesInSystem >= numServers) {
        Message departureMessage(totalMessages++, currentTime, Message::MESSAGE_DEPARTURE);
        gateway.push_back(departureMessage);

        nextDepartureTime = currentTime + exponentialDistribution(mu);
    } else {
        nextDepartureTime = std::numeric_limits<double>::infinity();
    }
}

// Processes the selection of a message for service from the gateway.
// If there are enough messages in the gateway to match the number of servers,
// a departure message is added to the gateway and the nextDepartureTime is updated.
// Otherwise, nextDepartureTime is set to infinity.

// Parameters:
// - currentTime: The current simulation time.
// - gateway: Reference to the vector representing the gateway.
// - messagesInSystem: Reference to the count of messages currently in the gateway.
// - nextDepartureTime: Reference to the time of the next departure from the gateway.
// - totalMessages: Reference to the total count of messages arrived in the system.
