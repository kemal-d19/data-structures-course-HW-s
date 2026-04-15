#ifndef MLP_GRAPH_H
#define MLP_GRAPH_H

#include "Neuron.h"

class MLPGraph {
private:
    std::vector<Neuron*> input_layer_neurons; // Only stores input layer neurons

public:
    // Constructor and destructor
    MLPGraph(std::vector<Neuron*> input_layer_neurons);
    ~MLPGraph();

    // Getters
    std::vector<Neuron*>& get_input_layer_neurons();

    // Functionality
    void calculate_outputs(); // Calculates outputs for all neurons, stores them on instance variable named "output" on Neuron class
    int count_layers(); // Counts total number of layers, do not count the input layer
    int count_neurons(); // Counts total number of neurons
    int count_neurons_in_layer(int layer_num); // Counts neurons in a specific layer
    double get_minimum_weight(); // Finds the smallest edge weight
    double get_minimum_bias(); // Finds the smallest bias (input layer excluded)
    
    // DEFINE HELPER FUNCTIONS HERE IF NEEDED
};

#endif