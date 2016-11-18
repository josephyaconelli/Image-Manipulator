#include <source.h>

Source::Source()
{
	img.SetOwner(this);
}

Image*
Source::GetOutput()
{
	return &img;
}

void
Source::Update()
{
		Execute();
}
