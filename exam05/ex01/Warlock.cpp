#include "Warlock.hpp"

Warlock::~Warlock()
{
    std::cout << m_name << ": My job here is done!" << std::endl;
}

Warlock::Warlock(const std::string &name, const std::string &title) : m_name(name), m_title(title)
{
    std::cout << m_name << ": This looks like another boring day." << std::endl;
}

const std::string &Warlock::getName() const
{
    return m_name;
}

const std::string &Warlock::getTitle() const
{
    return m_title;
}

void Warlock::setTitle(const std::string &title)
{
    m_title = title;
}

void Warlock::introduce() const
{
    std::cout << m_name << ": I am " << m_name << ", " << m_title << "!" << std::endl;
}

void Warlock::learnSpell(ASpell *spell)
{
    if (spell == nullptr)
        return;
    m_spells.push_back(spell);
}

void Warlock::forgetSpell(const std::string &spell_name)
{
    for (std::vector<ASpell *>::const_iterator it = m_spells.begin(); it != m_spells.end(); ++it)
    {
        if ((*it)->getName() == spell_name)
        {
            m_spells.erase(it);
            return;
        }
    }
}

void Warlock::launchSpell(const std::string &spell_name, const ATarget &target) const
{
    for (std::vector<ASpell *>::const_iterator it = m_spells.begin(); it != m_spells.end(); ++it)
    {
        if ((*it)->getName() == spell_name)
        {
            (*it)->launch(target);
            return;
        }
    }
}
