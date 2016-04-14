#ifndef _TCS_HEADER_H
#define _TCS_HEADER_H

namespace TCS
{
	const char *const LOCK_FILE = "/tmp/TCS";
	class CLock
	{
	public:
		static int getLock()
		{
			return(open(LOCK_FILE, O_CREAT | O_EXCL));
		}
		static int releaseLock()
		{
			return(unlink(LOCK_FILE));
		}
	private:
	
	};
}
#endif  // _TCS_HEADER_H
