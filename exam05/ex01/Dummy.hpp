#ifndef _DUMMY_HPP_
#define _DUMMY_HPP_

#include "ATarget.hpp"

class Dummy : public ATarget
{
	public:
	Dummy();
	~Dummy();

	virtual ATarget *clone();
};

#endif // _DUMMY_HPP_
