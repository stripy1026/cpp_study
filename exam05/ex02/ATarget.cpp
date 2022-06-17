#include "ATarget.hpp"

ATarget::~ATarget()
{
}

ATarget::ATarget(const std::string &type) : m_type(type)
{
}

const std::string &ATarget::getType() const
{
    return m_type;
}

void ATarget::getHitBySpell(const ASpell &spell) const
{
    std::cout << m_type << " has been " << spell.getEffects() << "!" << std::endl;
}
