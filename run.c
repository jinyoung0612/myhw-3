#include <sys/types.h>
#include <limits.h>

#include "run.h"
#include "util.h"

void *base = 0;

p_meta find_meta(p_meta *last, size_t size) {
  p_meta index = base;
  p_meta result = base;

  p_meta tmp=base;
  p_meta tsize=base;
  switch(fit_flag){
    case FIRST_FIT:
    {
	    while(index){
		    if(index->free==1 && index->size >= size){
			    result=index;
			    break;
		    }
		   index=index->next;
		    
	    }

      //FIRST FIT CODE
    }
    break;

    case BEST_FIT:
    {
      //BEST_FIT CODE

	    if(index){
		 tsize=index->size; 
		    
	    }
	    while(index){
		    if(index->free==1 && index->size >=size &&index->size <tsize){
		    
			    tmp=index;
			    tsize=tmp->size;
			    break;
		    }
		    index=index->next;

	    }
	    result=tmp;

    }
    break;

    case WORST_FIT:
    {
      //WORST_FIT CODE
	    if(index){
		   tsize=index->size;
	    }
	    while(index){

		    if(index->free==1&&index->size>=size&& index->size<tsize){
		    
			    tmp=index;
			    tsize=tmp->size;
			    break;
		    }

		    index=index->next;
	    }
	    result=tmp;
    }

    break;
  }
  
  return result;
}

void *m_malloc(size_t size) {

}

void m_free(void *ptr) {

}

void*
m_realloc(void* ptr, size_t size)
{

}
