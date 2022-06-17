#include "SpellBook.hpp"

SpellBook::SpellBook()
{
}

SpellBook::~SpellBook()
{
}

void SpellBook::learnSpell(ASpell *spell)
{
    if (spell == nullptr)
        return;
    ASpell *tmp = createSpell(spell->getName());
    if (tmp == nullptr)
        m_spells.push_back(spell);
    else
        delete tmp;
}

void SpellBook::forgetSpell(const std::string &spell_name)
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

ASpell *SpellBook::createSpell(const std::string &spell_name)
{
    for (std::vector<ASpell *>::const_iterator it = m_spells.begin(); it != m_spells.end(); ++it)
    {
        if ((*it)->getName() == spell_name)
        {
            return (*it)->clone();
        }
    }
    return nullptr;
}
