#ifndef NEURON_H
#define NEURON_H

#include <vector>
#include <climits>
#include <cmath>
#include <iostream>

class MLPGraph;

class Neuron {
private:
    double bias; // Bias of the neuron
    double input; // Input value (only used for input neurons, otherwise -1.0)
    double output; // Output after applying activation function
    std::string activation; // Activation function name ("relu", "sigmoid", "linear")
    std::vector<std::pair<Neuron*, double> > incoming_edges; // Pairs of source neuron and weight
    std::vector<std::pair<Neuron*, double> > outgoing_edges; // Pairs of destination neuron and weight

public:
    // Constructor
    Neuron(double bias = 0.0, double input = 1.0, const std::string& activation = "linear");
    
    // destructor
    ~Neuron();

    // Getters and setters
    double get_bias() const;
    void set_bias(double bias);

    double get_input() const;
    void set_input(double input);

    double get_output() const;
    void set_output(double output);

    const std::string& get_activation() const;
    void set_activation(const std::string& activation);

    std::vector<std::pair<Neuron*, double> >& get_incoming_edges();
    std::vector<std::pair<Neuron*, double> >& get_outgoing_edges();
 
    void add_incoming_edge(Neuron* source, double weight);
    void add_outgoing_edge(Neuron* destination, double weight);
    
    // DEFINE HELPER FUNCTIONS HERE IF NEEDED

    friend class MLPGraph;
};

#endif