#include "MLPGraph.h"
#include <iostream>
#include <iomanip>

using namespace std;

int main()
{
    /*
    Figure 1 in the homework description
    Input layer: 1.8 0.6
    Layer 1 biases: 0.3 0.7 0.2 
    Layer 2 biases: 0.4
    */
    
    Neuron *input_1 = new Neuron(0.0, 1.8, "linear");
    Neuron *input_2 = new Neuron(0.0, 0.6, "linear");
    
    Neuron *layer_1_neuron_1 = new Neuron(0.3, -1.0, "relu");
    Neuron *layer_1_neuron_2 = new Neuron(0.2, -1.0, "relu");
    Neuron *layer_1_neuron_3 = new Neuron(0.7, -1.0, "relu");
    
    Neuron *layer_2_neuron_1 = new Neuron(0.4, -1.0, "sigmoid");
    
    input_1 -> add_outgoing_edge(layer_1_neuron_1, 0.2);
    input_1 -> add_outgoing_edge(layer_1_neuron_2, 0.1);
    input_1 -> add_outgoing_edge(layer_1_neuron_3, 0.0);
    
    input_2 -> add_outgoing_edge(layer_1_neuron_1, 0.3);
    input_2 -> add_outgoing_edge(layer_1_neuron_2, 0.3);
    input_2 -> add_outgoing_edge(layer_1_neuron_3, 0.2);
    
    layer_1_neuron_1 -> add_outgoing_edge(layer_2_neuron_1, 0.4);
    layer_1_neuron_2 -> add_outgoing_edge(layer_2_neuron_1, 0.7);
    layer_1_neuron_3 -> add_outgoing_edge(layer_2_neuron_1, 0.2);
    
    layer_2_neuron_1 -> add_incoming_edge(layer_1_neuron_1, 0.4);
    layer_2_neuron_1 -> add_incoming_edge(layer_1_neuron_2, 0.7);
    layer_2_neuron_1 -> add_incoming_edge(layer_1_neuron_3, 0.2);
    
    layer_1_neuron_1 -> add_incoming_edge(input_1, 0.2);
    layer_1_neuron_1 -> add_incoming_edge(input_2, 0.3);
    
    layer_1_neuron_2 -> add_incoming_edge(input_1, 0.1);
    layer_1_neuron_2 -> add_incoming_edge(input_2, 0.3);
    
    layer_1_neuron_3 -> add_incoming_edge(input_1, 0.0);
    layer_1_neuron_3 -> add_incoming_edge(input_2, 0.2);
    
    vector<Neuron*> input_layer_neurons = {input_1, input_2};
    MLPGraph m(input_layer_neurons);
    
    cout<<fixed <<setprecision(2);
    
    cout << "Number of layers are: " << m.count_layers() << endl; // Reminder: Input layer is not counted
    cout << "Number of neurons are: " << m.count_neurons() << endl;
    cout << "Number of neurons in layer 1 are: " << m.count_neurons_in_layer(1) << endl;
    cout << "Number of neurons in layer 2 are: " << m.count_neurons_in_layer(2) << endl;
    cout << "Minimum weight in the network is: " << m.get_minimum_weight() << endl;
    cout << "Minimum bias in the network is: " << m.get_minimum_bias() << endl;
    
    m.calculate_outputs();
    cout<< "Output of first neuron in Layer 1: "<< (layer_1_neuron_1 -> get_output()) <<endl;
    cout<< "Output of second neuron in Layer 1: "<< (layer_1_neuron_2 -> get_output()) <<endl;
    cout<< "Output of third neuron in Layer 1: "<< (layer_1_neuron_3 -> get_output()) <<endl;
    
    cout<< "Output of first neuron in Layer 2: "<< (layer_2_neuron_1 -> get_output()) <<endl;
    return 0;
}