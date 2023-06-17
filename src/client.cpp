// client.cpp

#include "event.hpp"

Client::Client(double lambda) : lambda(lambda) {}

// Constructor for the Client class.
// Initializes the departure rate (lambda).

// Parameters:
// - lambda: The departure rate of messages from the client.

double Client::exponentialDistribution(double rate) {
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

void Client::processDeparture(double currentTime, std::vector<Message>& gateway, int& messagesInSystem, double& nextArrivalTime, int& totalMessages, int& droppedMessages, int& capacity) {
    if (messagesInSystem > 0) {
        Message departureMessage(totalMessages, currentTime, Message::MESSAGE_DEPARTURE);
        gateway.push_back(departureMessage);
        messagesInSystem--;

        if (messagesInSystem < capacity) {
            Message selectMessage(totalMessages + 1, currentTime, Message::SELECT_MESSAGE);
            gateway.push_back(selectMessage);
            nextArrivalTime = currentTime + exponentialDistribution(lambda);
        }
    }
}

// Processes the departure of a message from the gateway by the client.
// If there are messages in the gateway, a departure message is added to the gateway,
// and if the number of messages falls below the capacity, a select message is added
// to the gateway and nextArrivalTime is updated.

// Parameters:
// - currentTime: The current simulation time.
// - gateway: Reference to the vector representing the gateway.
// - messagesInSystem: Reference to the count of messages currently in the gateway.
// - nextArrivalTime: Reference to the time of the next message arrival to the gateway.
// - totalMessages: Reference to the total count of messages arrived in the system.
// - droppedMessages: Reference to the count of messages dropped due to the gateway being full.
// - capacity: The maximum capacity of the gateway.
