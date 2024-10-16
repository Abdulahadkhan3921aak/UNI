
#pragma once
#include "mamal.h"

class Dog : public Mammal
{
public:
    Dog();
    ~Dog();

    void Move() const override;
    void Speak() const override;
};
