#include <image.h>
#include <cstddef>
#include <source.h>

Image::Image()
{
	this->pixel = new Pixel[1];
}

Image::Image(int width, int height)
{
	this->width  = width;
	this->height = height;
	
	this->pixel = new Pixel[width*height];
}

Image::Image(Image &img)
{
	this->height  = img.height;
	this->width   = img.width;
	this->maxVal  = img.maxVal;
	this->version = img.version;
	
	this->pixel = new Pixel[height*width];
}

Image::~Image()
{
	delete [] this->pixel;
}

void
Image::ResetSize(int width, int height)
{
	this->width  = width;
	this->height = height;
	if (pixel != NULL)
		delete [] pixel;
	this->pixel = new Pixel[width*height];
}

int
Image::GetWidth()
{
	return this->width;
}

int
Image::GetHeight()
{
	return this->height;
}

int
Image::GetMaxVal()
{
	return this->maxVal;
}

char*
Image::GetVersion()
{
	return this->version;
}

void
Image::SetWidth(int width)
{
	this->width = width;
}

void
Image::SetHeight(int height)
{
	this->height = height;
}

void
Image::SetMaxVal(int maxVal)
{
	this->maxVal = maxVal;
}

void
Image::SetVersion(char* version)
{
	this->version = version;
}

void
Image::Update()
{
	ownerPtr->Update();
}

void
Image::SetOwner(Source* InOwnerPtr)
{
	ownerPtr = InOwnerPtr;
}
