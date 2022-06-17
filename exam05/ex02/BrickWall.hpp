#ifndef _BRICKWALL_HPP_
#define _BRICKWALL_HPP_

#include "ATarget.hpp"

class BrickWall : public ATarget
{
  public:
    BrickWall();
    ~BrickWall();

    virtual ATarget *clone();
};

#endif // _BRICKWALL_HPP_
