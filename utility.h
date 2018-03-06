//File provided to the class
//file created by Ben

#ifndef UTILITY_H
#define UTILITY_H

#include "node1.h"
#include <iostream>

node *list1();

node *build_list(node::value_type values[], int number);

node *build_list(node::value_type values[]);

void print_list(node* head);

std::ostream & operator<<(std::ostream &str, const node* head);


#endif 