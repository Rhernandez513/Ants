#include <string>

using namespace Ants;

Ant::Ant(std::string color_, std::string hierarchy_, int attackpower_)
{
    color = color_;
    hierarchy = hierarchy_;
    attackpower = attackpower_;
    dead = false;
    joined = false;
    location = NULL;
    joiner = "";
};

Ant::~Ant(){ };

/**VARIOUS GETTERS AND SETTERS I THOUGHT USEFUL**/
Ant::TableNode * GetLocation() { return location; }

std::string Ant::GetColor(){ return color; }
std::string Ant::GetHierarchy() { return hierarchy; }
std::string Ant::GetJoiner() { return joiner; }

bool Ant::GetJoined() { return joined; }

int Ant::GetAttackPower() { return attackpower; }

bool Ant::IsDead();

void Ant::SetLocation (Tablenode * new_location);
void Ant::Turn ();
};

