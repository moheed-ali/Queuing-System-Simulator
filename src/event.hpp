// event.hpp

#ifndef EVENT_HPP
#define EVENT_HPP

#include <iostream>
#include <queue>
#include <vector>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <random>
#include <limits>

class Message {
public:
    enum Type { SEND_MESSAGE, RECEIVE_MESSAGE, SELECT_MESSAGE, MESSAGE_DEPARTURE };

    int id;
    double timestamp;
    Type type;

    Message(int id, double timestamp, Type type);
};

class Gateway {
public:
    Gateway(double lambda, int capacity);

    double exponentialDistribution(double rate);

    void processArrival(double currentTime, std::vector<Message>& gateway, int& messagesInSystem, int& totalMessages, int& droppedMessages);

private:
    double lambda;    // Arrival rate
    int capacity;     // Maximum capacity of the gateway
};

class Client {
public:
    Client(double lambda);

    double exponentialDistribution(double rate);

    void processDeparture(double currentTime, std::vector<Message>& gateway, int& messagesInSystem, double& nextArrivalTime, int& totalMessages, int& droppedMessages, int& capacity);

private:
    double lambda;    // Departure rate
};

class Server {
public:
    Server(double mu, int numServers);

    double exponentialDistribution(double rate);

    void processSelection(double currentTime, std::vector<Message>& gateway, int& messagesInSystem, double& nextDepartureTime, int& totalMessages);

private:
    double mu;        // Service rate
    int numServers;   // Number of servers in the system
};

class Engine {
public:
    Engine(double lambda, double mu, int numServers, int capacity);

    double exponentialDistribution(double rate);

    void runSimulation(double simulationTime);
    double getAverageMessagesInSystem();

private:
    double averageMessagesInSystem;
    double lambda;    // Arrival rate
    double mu;        // Service rate
    int numServers;   // Number of servers in the system
    int capacity;     // Maximum capacity of the gateway
};

#endif  // EVENT_HPP
