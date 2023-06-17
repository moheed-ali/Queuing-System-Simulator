// message.cpp

#include "event.hpp"

Message::Message(int id, double timestamp, Type type)
    : id(id), timestamp(timestamp), type(type) {}

// Constructor for the Message class.
// Initializes the member variables with the provided values.

// Parameters:
// - id: The ID of the message.
// - timestamp: The timestamp of the message.
// - type: The type of the message (SEND_MESSAGE, RECEIVE_MESSAGE, SELECT_MESSAGE, MESSAGE_DEPARTURE).
