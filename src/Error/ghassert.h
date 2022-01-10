#ifndef _GHRENDR_GHASSERT_H_
#define _GHRENDR_GHASSERT_H_

#ifndef NDEBUG
#	define GH_ASSERT(exp, msg) __GH_ASSERT(#exp, exp, __FILE__, __LINE__, msg)
#else
#	define GH_ASSERT(exp, msg)
#endif

void __GH_ASSERT(const char* expr_str, bool expr, const char* file, int line, const char* msg);


#endif