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
    m_spell_book.learnSpell(spell);
}

void Warlock::forgetSpell(const std::string &spell_name)
{
    m_spell_book.forgetSpell(spell_name);
}

void Warlock::launchSpell(const std::string &spell_name, const ATarget &target)
{
    ASpell *spell = m_spell_book.createSpell(spell_name);
    if (spell == nullptr)
        return;
    spell->launch(target);
    delete spell;
}
