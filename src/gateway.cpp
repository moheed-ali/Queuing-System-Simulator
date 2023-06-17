// gateway.cpp

#include "event.hpp"

Gateway::Gateway(double lambda, int capacity) : lambda(lambda), capacity(capacity) {}

// Constructor for the Gateway class.
// Initializes the arrival rate (lambda) and capacity of the gateway.

// Parameters:
// - lambda: The arrival rate of messages to the gateway.
// - capacity: The maximum capacity of the gateway.

double Gateway::exponentialDistribution(double rate) {
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

void Gateway::processArrival(double currentTime, std::vector<Message>& gateway, int& messagesInSystem, int& totalMessages, int& droppedMessages) {
    if (messagesInSystem < capacity) {
        messagesInSystem++;
        totalMessages++;

        if (messagesInSystem == 1) {
            Message selectMessage(totalMessages, currentTime, Message::SELECT_MESSAGE);
            gateway.push_back(selectMessage);
        }
    } else {
        droppedMessages++;
    }
}

// Processes the arrival of a message to the gateway.
// If the gateway has capacity, the message is added to the gateway.
// If the gateway is full, the message is dropped.

// Parameters:
// - currentTime: The current simulation time.
// - gateway: Reference to the vector representing the gateway.
// - messagesInSystem: Reference to the count of messages currently in the gateway.
// - totalMessages: Reference to the total count of messages arrived in the system.
// - droppedMessages: Reference to the count of messages dropped due to the gateway being full.
