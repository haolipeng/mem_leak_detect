#ifndef MEMORY_LEAK_THREAD_CACHE_H
#define MEMORY_LEAK_THREAD_CACHE_H
#include <atomic>
#include <stdint.h>

#include "concurrentqueue.h"

typedef std::atomic<uint64_t> atomic_uint64_t;
#define MAX_DEPTH (16)

//TODO:
enum
{
	TRACE_MASK_ALL_OU       = 0x00,
    TRACE_MASK_GLOBAL_IN    = 0x01,
    TRACE_MASK_LOCAL_IN     = 0x02,
};

struct STACK_VALUE
{
	uint64_t _type:8;
	uint64_t _stack_cnt:56;
	uint64_t _ident[2];
	void* _stacks[MAX_DEPTH];
};

class ThreadCache
{
public:
	ThreadCache() 
	{
		m_flags = 0;
		m_queue_cnt = 0;
	}
	~ThreadCache() {}
public:
	static ThreadCache* get_cache(bool alloc_new);
	void trace_alloc(void* ptr, size_t size);

public:
	atomic_uint64_t m_queue_cnt;
	moodycamel::ConcurrentQueue<ThreadCache*> m_thread_cache_queue;
	uint64_t    m_flags;
};

#endif