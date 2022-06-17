#ifndef _POLYMORPH_HPP_
#define _POLYMORPH_HPP_

#include "ASpell.hpp"

class Polymorph : public ASpell
{
  public:
    Polymorph();
    ~Polymorph();

    virtual ASpell *clone();
};

#endif // _POLYMORPH_HPP_
