#ifndef _TARGET_GENERATOR_HPP_
#define _TARGET_GENERATOR_HPP_

#include <string>
#include <vector>

#include "ATarget.hpp"

class TargetGenerator
{
  private:
    std::vector<ATarget *> m_targets;

    TargetGenerator(const TargetGenerator &src);
    TargetGenerator &operator=(const TargetGenerator &rhs);

  public:
    TargetGenerator();
    ~TargetGenerator();

    void learnTargetType(ATarget *target);
    void forgetTargetType(const std::string &target_name);
    ATarget *createTarget(const std::string &target_name);
};

#endif // _TARGET_GENERATOR_HPP_
