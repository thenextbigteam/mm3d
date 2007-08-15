#ifndef __RELEASE_PTR_H
#define __RELEASE_PTR_H

#include <stdlib.h>

template<typename T> class release_ptr
{
   public:
      release_ptr( T * pval = NULL )
         : m_pval( pval ) {}
      virtual ~release_ptr() { free_ptr(); }

      T * get() { return m_pval; }
      T * reset(T * newPval) { free_ptr(); return m_pval = newPval; }
      const T * get() const { return m_pval; }
      const T * reset(T * newPval) const { free_ptr(); return m_pval = newPval; }

      T & operator*() { return *m_pval; }
      T * operator->() { return m_pval; }
      const T & operator*() const { return *m_pval; }
      const T * operator->() const { return m_pval; }

      T * operator=(T* newPval) { return reset(newPval); }
      const T * operator=(T* newPval) const { return reset(newPval); }

      bool operator!() const { return m_pval == NULL; }
      bool isnull() const { return m_pval == NULL; }

   protected:
      void free_ptr() const { if (m_pval) m_pval->release(); m_pval = NULL; }

      mutable T * m_pval;
};

#endif // __RELEASE_PTR_H