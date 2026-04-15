#include "Neuron.h"

// Constructor
Neuron::Neuron(double bias, double input, const std::string& activation)
{
    this->bias = bias;         
    this->input = input;        
    this->activation = activation; 
    // std::vector<std::pair<Neuron*, double> >* incoming_edges;
    // std::vector<std::pair<Neuron*, double> >* outgoing_edges; 
}

Neuron::~Neuron()
{

}

// Getters and setters
double Neuron::get_bias() const
{
    return bias;
}

void Neuron::set_bias(double bias)
{
    this->bias = bias;
}

double Neuron::get_input() const
{
    return input;
}

void Neuron::set_input(double input)
{
    this->input = input;
}

double Neuron::get_output() const
{
    return output;
}

void Neuron::set_output(double output)
{
    this->output = output;
}

const std::string& Neuron::get_activation() const
{
    return activation;
}

void Neuron::set_activation(const std::string& activation)
{
    this->activation = activation;
}

std::vector<std::pair<Neuron*, double> >& Neuron::get_incoming_edges()
{
    return incoming_edges;
}

std::vector<std::pair<Neuron*, double> >& Neuron::get_outgoing_edges()
{
    return outgoing_edges;
}

void Neuron::add_incoming_edge(Neuron* source, double weight)
{
    std::pair<Neuron*, double> new_pair(source, weight);
    incoming_edges.push_back(new_pair);
}

void Neuron::add_outgoing_edge(Neuron* destination, double weight)
{
    std::pair<Neuron*, double> new_pair(destination, weight);
    outgoing_edges.push_back(new_pair);
}

// IMPLEMENT THE HELPER FUNCTIONS YOU DEFINED IN Neuron.h HERE, IF NEEDED
