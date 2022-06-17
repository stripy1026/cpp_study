#ifndef _WARLOCK_HPP_
#define _WARLOCK_HPP_

#include <iostream>

#include "ATarget.hpp"
#include "SpellBook.hpp"

class Warlock
{
  private:
    std::string m_name;
    std::string m_title;
    SpellBook m_spell_book;

    Warlock();
    Warlock(const Warlock &src);
    Warlock &operator=(const Warlock &rhs);

  public:
    ~Warlock();

    Warlock(const std::string &name, const std::string &title);

    const std::string &getName() const;
    const std::string &getTitle() const;

    void setTitle(const std::string &title);

    void introduce() const;

    void learnSpell(ASpell *spell);
    void forgetSpell(const std::string &spell_name);
    void launchSpell(const std::string &spell_name, const ATarget &target);
};

#endif // _WARLOCK_HPP_