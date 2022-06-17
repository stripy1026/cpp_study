#ifndef _WARLOCK_HPP_
#define _WARLOCK_HPP_

#include <iostream>

class Warlock
{
  private:
    std::string m_name;
    std::string m_title;

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
};

#endif // _WARLOCK_HPP_