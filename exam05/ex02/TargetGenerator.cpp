#include "TargetGenerator.hpp"

TargetGenerator::TargetGenerator()
{
}

TargetGenerator::~TargetGenerator()
{
}

void TargetGenerator::learnTargetType(ATarget *target)
{
    if (target == nullptr)
        return;
    ATarget *tmp = createTarget(target->getType());
    if (tmp == nullptr)
        m_targets.push_back(target);
    else
        delete tmp;
}

void TargetGenerator::forgetTargetType(const std::string &target_name)
{
    for (std::vector<ATarget *>::const_iterator it = m_targets.begin(); it != m_targets.end(); ++it)
    {
        if ((*it)->getType() == target_name)
        {
            m_targets.erase(it);
            return;
        }
    }
}

ATarget *TargetGenerator::createTarget(const std::string &target_name)
{
    for (std::vector<ATarget *>::const_iterator it = m_targets.begin(); it != m_targets.end(); ++it)
    {
        if ((*it)->getType() == target_name)
        {
            return (*it)->clone();
        }
    }
    return nullptr;
}
