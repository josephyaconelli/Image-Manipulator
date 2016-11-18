#ifndef SOURCE_H
#define SOURCE_H
#include <image.h>

class Source {
	protected:
		Image img;
	public:
		virtual void Execute()=0;
		virtual void Update();
		Image* GetOutput();
		Source(void);
};



#endif
