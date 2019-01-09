#ifndef VIRTUAL_ENABLE_SHARED_FROM_THIS_H
#define VIRTUAL_ENABLE_SHARED_FROM_THIS_H

#include <memory>

class virtual_enable_shared_from_this_base: public std::enable_shared_from_this<virtual_enable_shared_from_this_base>
{
public:
   virtual ~virtual_enable_shared_from_this_base() {}
};

template<typename T>
class virtual_enable_shared_from_this: virtual public virtual_enable_shared_from_this_base
{
public:
   std::shared_ptr<T> shared_from_this()
   {
      return std::dynamic_pointer_cast<T>(virtual_enable_shared_from_this_base::shared_from_this());
   }
};
#endif // VIRTUAL_ENABLE_SHARED_FROM_THIS_H
