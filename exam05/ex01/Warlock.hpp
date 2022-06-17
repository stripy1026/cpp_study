#ifndef _WARLOCK_HPP_
#define _WARLOCK_HPP_

#include <iostream>
#include <vector>

#include "ASpell.hpp"
#include "ATarget.hpp"

class Warlock
{
  private:
    std::string m_name;
    std::string m_title;
    std::vector<ASpell *> m_spells;

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
    void launchSpell(const std::string &spell_name, const ATarget &target) const;
};

#endif // _WARLOCK_HPP_