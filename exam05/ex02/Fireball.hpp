#ifndef _FIREBALL_HPP_
#define _FIREBALL_HPP_

#include "ASpell.hpp"

class Fireball : public ASpell
{
  public:
    Fireball();
    ~Fireball();

    virtual ASpell *clone();
};

#endif // _FIREBALL_HPP_
