#include "ASpell.hpp"

ASpell::~ASpell()
{
}

ASpell::ASpell(const std::string &name, const std::string &effects) : m_name(name), m_effects(effects)
{
}

const std::string &ASpell::getName() const
{
    return m_name;
}

const std::string &ASpell::getEffects() const
{
    return m_effects;
}

void ASpell::launch(const ATarget &target) const
{
    target.getHitBySpell(*this);
}
