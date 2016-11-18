#ifndef PNMWRITERCPP_H
#define PNMWRITERCPP_H
#include <sink.h>

class PNMwriterCPP: public Sink
{
	public:
		void Write(char*);
};

class PNMwriter: public Sink
{
	public:
		void Write(char*);
};

#endif
