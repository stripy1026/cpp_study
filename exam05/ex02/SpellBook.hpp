#ifndef _SPELLBOOK_HPP_
#define _SPELLBOOK_HPP_

#include <vector>

#include "ASpell.hpp"

class SpellBook
{
  private:
    std::vector<ASpell *> m_spells;

    SpellBook(const SpellBook &src);
    SpellBook &operator=(const SpellBook &rhs);

  public:
    SpellBook();
    ~SpellBook();

    void learnSpell(ASpell *spell);
    void forgetSpell(const std::string &spell_name);
    ASpell *createSpell(const std::string &spell_name);
};

#endif // _SPELLBOOK_HPP_
