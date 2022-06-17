#ifndef _A_TARGET_HPP_
#define _A_TARGET_HPP_

#include <iostream>

#include "ASpell.hpp"

class ASpell;

class ATarget
{
  protected:
    std::string m_type;

    ATarget();
    ATarget(const ATarget &src);
    ATarget &operator=(const ATarget &rhs);

  public:
    virtual ~ATarget();

    ATarget(const std::string &type);

    const std::string &getType() const;

    void getHitBySpell(const ASpell &spell) const;

    virtual ATarget *clone() = 0;
};

#endif // _A_TARGET_HPP_
