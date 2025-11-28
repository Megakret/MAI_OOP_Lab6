#pragma once

#include <fight_system/fight_visitors/fight_visitor.hpp>
#include <string>

namespace npcs {
struct Point {
  int x;
  int y;
	friend bool operator==(const Point& p1, const Point& p2){
		return p1.x == p2.x && p1.y == p2.y;
	}
};

class NPC {
public:
  NPC(const std::string &name, Point location);
  Point GetCoords() const;
  std::string_view GetName() const;
  // Returns true if the instance won
  virtual bool Fight(const NPC &opponent) = 0;
  virtual bool AcceptFight(
      const fight_system::fight_visitors::FightVisitor &initiator_visitor) = 0;
	virtual ~NPC();

private:
  Point location_;
  std::string name_;
};
} // namespace npcs
