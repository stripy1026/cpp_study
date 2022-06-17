#ifndef _FWOOSH_HPP_
#define _FWOOSH_HPP_

#include "ASpell.hpp"

class Fwoosh : public ASpell
{
  public:
    Fwoosh();
    ~Fwoosh();

    virtual ASpell *clone();
};

#endif // _FWOOSH_HPP_
