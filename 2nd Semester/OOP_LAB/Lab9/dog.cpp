#include "dog.h"
#include <iostream>

Dog::Dog()
{
    std::cout << "Dog constructor..." << std::endl;
}

Dog::~Dog()
{
    std::cout << "Dog destructor..." << std::endl;
}

void Dog::Move() const
{
    std::cout << "Dog moves on four legs!" << std::endl;
}

void Dog::Speak() const
{
    std::cout << "Woof! Woof!" << std::endl;
}
