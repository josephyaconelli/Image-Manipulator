#ifndef PNMREADERCPP_H
#define PNMREADERCPP_H
#include <source.h>

class PNMreaderCPP: public Source
{
	private:
		char* filename;
	public:
		PNMreaderCPP(char*);
		virtual void Execute();
		virtual ~PNMreaderCPP();
		virtual void Update();
};

class PNMreader: public Source
{
	private:
		char* filename;
		
	public:
		PNMreader(char*);
		virtual void Execute();
		virtual ~PNMreader();
};


#endif

