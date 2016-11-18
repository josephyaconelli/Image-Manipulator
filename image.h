#ifndef IMAGE_H
#define IMAGE_H

struct Pixel
{
	unsigned char r;
	unsigned char g;
	unsigned char b;
};

class Source;

class Image
{
	private:
		int width;
		int height;
		int maxVal;
		char* version;
	public:
		Source *ownerPtr;
		Pixel *pixel;
		void ResetSize(int width, int height);
		int GetWidth();
		int GetHeight();
		int GetMaxVal();
		char* GetVersion();
		void SetWidth(int);
		void SetHeight(int);
		void SetMaxVal(int);
		void SetVersion(char*);
		void SetOwner(Source*);
		void Update();
		Image();
		Image(int width, int height);
		Image(Image &img);
		~Image();
};
#endif
