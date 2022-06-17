#ifndef _A_SPELL_HPP_
#define _A_SPELL_HPP_

#include <string>

#include "ATarget.hpp"

class ATarget;

class ASpell
{
  private:
    ASpell();
    ASpell(const ASpell &src);
    ASpell &operator=(const ASpell &rhs);

  protected:
    std::string m_name;
    std::string m_effects;

  public:
    ~ASpell();

    ASpell(const std::string &name, const std::string &effects);

    const std::string &getName() const;
    const std::string &getEffects() const;

    void launch(const ATarget &target) const;

    virtual ASpell *clone() = 0;
};

#endif // _A_SPELL_HPP_
