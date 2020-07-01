#include "thread_cache.h"

// 初始化pthread tls key
pthread_key_t g_tls_key = 0;
class ThreadLocalStorageInitializer
{
public:
	ThreadLocalStorageInitializer()
	{
		if(!g_tls_key)
		{
			pthread_create_key(&g_tls_key, NULL);
		}
	}
	~ThreadLocalStorageInitializer()
	{
		pthread_key_delete(g_tls_key);
		g_tls_key = 0;
	}
};
static ThreadLocalStorageInitializer g_tls_initializer;

ThreadCache* ThreadCache::get_cache(bool alloc_new)
{
	if(g_tls_key)
	{
		void* tcache = pthread_getspecific(g_tls_key);
		if(!tcache && alloc_new)
		{	
			tcache = tc_malloc(sizeof(ThreadCache));
			new (tcache) ThreadCache;//这行是什么作用
			pthread_setspecific(g_tls_key, tcache);

			m_queue_cnt++;
			m_thread_cache_queue.enqueue(tcache);
			return (ThreadCache*)tcache;
		}
	}
	return NULL;
}

void ThreadCache::trace_alloc(void* ptr, size_t size)
{
	//1.获取堆栈信息
	//2.计算堆栈的低位hash和高位hash
	//3.将两个hash保存起来
	return;
}