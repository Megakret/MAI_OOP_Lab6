#include <NPCs/NPC.hpp>

#include <cmath>

namespace npcs {
float Distance(Point a, Point b) {
  return std::sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
NPC::NPC(const std::string &name, Point location)
    : location_(location), name_(name) {}
std::string_view NPC::GetName() const { return std::string_view(name_); }
Point NPC::GetCoords() const { return location_; }
NPC::~NPC() {}
}; // namespace npcs
