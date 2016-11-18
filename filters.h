#ifndef FILTERS_H
#define FILTERS_H
#include <source.h>
#include <sink.h>

class Filter : public Source, public Sink
{
	protected:
		virtual void Update();
};

class Shrinker : public Filter
{
	public:
		virtual void Execute();
};

class LRConcat : public Filter
{
	public:
		virtual void Execute();	
};

class TBConcat : public Filter
{
	public:
		virtual void Execute();
};


class Blender : public Filter
{
	private:
		float factor;
	public:
		virtual void Execute();
		void SetFactor(float);
};

#endif
