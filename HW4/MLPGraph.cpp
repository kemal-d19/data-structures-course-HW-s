#include "MLPGraph.h"

// MLPGraph Class Implementation
MLPGraph::MLPGraph(std::vector<Neuron*> input_layer_neurons)
{
    this->input_layer_neurons = input_layer_neurons;
}

MLPGraph::~MLPGraph()
{

}

std::vector<Neuron*>& MLPGraph::get_input_layer_neurons()
{
    return input_layer_neurons; 
}

void MLPGraph::calculate_outputs()
{
    if (input_layer_neurons.begin()[0]->get_outgoing_edges().size() != 0){

        std::vector<std::pair<Neuron*, double> >* p = &input_layer_neurons.begin()[0]->get_outgoing_edges();
        int count = 0;
        while(p->size() != 0){
            for (int i = 0; i < p->size(); i++){
                double sum = p->begin()[i].first->get_bias();
                for (int j = 0; j < p->begin()[i].first->get_incoming_edges().size(); j++){
                    double input;
                    if (p->begin()[i].first->get_incoming_edges()[j].first->get_input() == -1){
                        input = p->begin()[i].first->get_incoming_edges()[j].first->get_output();
                    }
                    else {
                        input = p->begin()[i].first->get_incoming_edges()[j].first->get_input();
                    }
                    sum +=  input * p->begin()[i].first->get_incoming_edges()[j].second;
                }
                if (p->begin()[i].first->get_activation() == "linear"){
                    p->begin()[i].first->set_output(sum); 
                }
                else if (p->begin()[i].first->get_activation() == "relu"){
                    if (sum <= 0){
                        p->begin()[i].first->set_output(0);
                    }
                    else {
                        p->begin()[i].first->set_output(sum); 
                    }
                }
                else if (p->begin()[i].first->get_activation() == "sigmoid"){

                    double result = 1 / (1 + exp(-1 * sum));

                    p->begin()[i].first->set_output(result); 
                }
            }
            p = &p->begin()[0].first->get_outgoing_edges();
            count += 1;
        }
    }
}

int MLPGraph::count_layers()
{
    if (input_layer_neurons.begin()[0]->get_outgoing_edges().size() == 0){
        return 0;
    }

    std::vector<std::pair<Neuron*, double> >* p = &input_layer_neurons.begin()[0]->get_outgoing_edges();
    int count = 0;
    while(p->size() != 0){
        p = &p->begin()[0].first->get_outgoing_edges();
        count += 1;
    }
    return count;
}

int MLPGraph::count_neurons()
{
    int total_n = 0;
    total_n += input_layer_neurons.size();
    if (input_layer_neurons.begin()[0]->get_outgoing_edges().size() == 0){
        return total_n;;
    }

    std::vector<std::pair<Neuron*, double> >* p = &input_layer_neurons.begin()[0]->get_outgoing_edges();
    while(p->size() != 0){
        total_n += p->size();
        p = &p->begin()[0].first->get_outgoing_edges();
        
    }
    return total_n;
}

int MLPGraph::count_neurons_in_layer(int layer_num)
{
    if (input_layer_neurons.begin()[0]->get_outgoing_edges().size() == 0){
        return 0;
    }

    std::vector<std::pair<Neuron*, double> >* p = &input_layer_neurons.begin()[0]->get_outgoing_edges();
    int count = 1;
    while(p->size() != 0){

        if (count == layer_num){
            return p->size();
        }
        p = &p->begin()[0].first->get_outgoing_edges();
        count += 1;
    }
    return 0;
}

double MLPGraph::get_minimum_weight()
{
    if (input_layer_neurons.begin()[0]->get_outgoing_edges().size() == 0){
        return 0;
    }

    std::vector<std::pair<Neuron*, double> >* p = &input_layer_neurons.begin()[0]->get_outgoing_edges();
    double min_weight = p->begin()[0].second;
    while(p->size() != 0){
        for (int i = 0; i < p->size(); i++){
            if(p->begin()[i].second < min_weight){
                min_weight = p->begin()[i].second;
            }
        }
        p = &p->begin()[0].first->get_outgoing_edges();
    }
    return min_weight;
}

double MLPGraph::get_minimum_bias()
{
    if (input_layer_neurons.begin()[0]->get_outgoing_edges().size() == 0){
        return 0.0;
    }

    std::vector<std::pair<Neuron*, double> >* p = &input_layer_neurons.begin()[0]->get_outgoing_edges();

    double min_bias = p->begin()[0].first->get_bias();
    while(p->size() != 0){

        for (int i = 0; i < p->size(); i++){
            if (p->begin()[i].first->get_bias() < min_bias){
                min_bias = p->begin()[i].first->get_bias();
            }
        }

        p = &p->begin()[0].first->get_outgoing_edges();
    }
    return min_bias;
}

// IMPLEMENT THE HELPER FUNCTIONS YOU DEFINED IN MLPGraph.h HERE, IF NEEDED
