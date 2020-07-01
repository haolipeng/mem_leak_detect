#include <stdio.h>
#include <stdint.h>
#include <tcmalloc.h>

struct IDENT_VALUE
{
	uint16_t _extra;
	uint32_t _safe;
};

#define RESERVED (sizeof(IDENT_VALUE))
#define USABLEPTR(PTR,LEN) ((void*)((uint8_t*)(PTR) + LEN))
#define IDENT_VALUE_PTR(PTR) ((uint8_t*)PTR - sizeof(IDENT_VALUE))

extern "C"
{
	void* malloc(size_t size)
	{
		void* ptr = tc_malloc(size + RESERVED);
		if(ptr)
		{
			//每次申请内存时预留位置，保存管理信息
			ptr = USABLEPTR(ptr,RESERVED);
			IDENT_VALUE* ident_val = IDENT_VALUE_PTR(ptr);
			ident_val->_extra = RESERVED;
			ident_val->_safe = 0xbebebebebebebebe;

			ThreadCache* heap = ThreadCache::get_cache(true);
			if(heap && heap->m_flags == TRACE_MASK_ALL_OU)
			{
				heap->m_flags |= TRACE_MASK_LOCAL_IN;
				heap->trace_alloc(ptr, size);
				heap->m_flags &= ~TRACE_MASK_LOCAL_IN;
			}
		}
	}
}
