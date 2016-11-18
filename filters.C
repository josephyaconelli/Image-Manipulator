#include <filters.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

//Helper Index Function
int
indP(int i, int j, int w){
		return (i*w + j);
}

void
Filter::Update()
{
	
	if(img1){
		img1->Update();
	}
	
	Execute();
}

void
Shrinker::Execute()
{
	int oldWidth  = img1->GetWidth();
	int oldHeight = img1->GetHeight();
	int newWidth  = oldWidth/2;
	int newHeight = oldHeight/2;

	img.ResetSize(newWidth, newHeight);
	img.SetMaxVal(img1->GetMaxVal());
	
	for(int i = 0; i < oldHeight; i+=2)
	{
		for(int j = 0; j < oldWidth; j+=2)
		{
			img.pixel[indP(i/2, j/2, newWidth)].r = 
				(img1->pixel[indP(i, j, oldWidth)].r
				+ img1->pixel[indP(i,j+1, oldWidth)].r
				+ img1->pixel[indP(i+1,j, oldWidth)].r
				+ img1->pixel[indP(i,j+1, oldWidth)].r)/4;
				
			img.pixel[indP(i/2, j/2, newWidth)].g = 
				(img1->pixel[indP(i, j, oldWidth)].g
				+ img1->pixel[indP(i,j+1, oldWidth)].g
				+ img1->pixel[indP(i+1,j, oldWidth)].g
				+ img1->pixel[indP(i,j+1, oldWidth)].g)/4;
				
			img.pixel[indP(i/2, j/2, newWidth)].b = 
				(img1->pixel[indP(i, j, oldWidth)].b
				+ img1->pixel[indP(i,j+1, oldWidth)].b
				+ img1->pixel[indP(i+1,j, oldWidth)].b
				+ img1->pixel[indP(i,j+1, oldWidth)].b)/4;
		}
	}
}


void
LRConcat::Execute()
{
	if(img1->GetWidth() != img2->GetWidth() || img1->GetHeight() != img2->GetHeight())
	{
		printf("Dimension Mismatch!");
		return;
	}
	img.SetMaxVal(img1->GetMaxVal());
	img.ResetSize(img1->GetWidth()*2, img1->GetHeight());
	
	for(int i = 0; i < img1->GetHeight(); i++)
	{
		memcpy(&(img.pixel[i*img.GetWidth()]), &(img1->pixel[i*img1->GetWidth()]), sizeof(Pixel)*img1->GetWidth());
		memcpy(&(img.pixel[i*img.GetWidth() + img1->GetWidth()]), &(img2->pixel[i*img1->GetWidth()]), sizeof(Pixel)*img1->GetWidth());
	}	
}

void
TBConcat::Execute()
{
	if(img1->GetWidth() != img2->GetWidth() || img1->GetHeight() != img2->GetHeight())
	{
		printf("Dimension Mismatch!");
		return;
	}
	img.SetMaxVal(img1->GetMaxVal());
	img.ResetSize(img1->GetWidth(), img1->GetHeight()*2);
	
	memcpy(img.pixel, img1->pixel, sizeof(Pixel)*img1->GetWidth()*img1->GetHeight());
	memcpy(&(img.pixel[img1->GetWidth()*img1->GetHeight()]), img2->pixel, sizeof(Pixel)*img2->GetWidth()*img2->GetHeight());
	
}

void
Blender::Execute()
{
	if(img1->GetWidth() != img2->GetWidth() || img1->GetHeight() != img2->GetHeight())
	{
		printf("Dimension Mismatch!");
		return;
	}
	
	img.SetMaxVal(img1->GetMaxVal());
	img.ResetSize(img1->GetWidth(), img1->GetHeight());
	
	for(int i = 0; i < img1->GetHeight(); i++)
	{
		for(int j = 0; j < img1->GetWidth(); j++)
		{
			img.pixel[indP(i,j,img1->GetWidth())].r = factor*img1->pixel[indP(i,j,img1->GetWidth())].r + (1 - factor)*img2->pixel[indP(i,j,img1->GetWidth())].r;
			img.pixel[indP(i,j,img1->GetWidth())].g = factor*img1->pixel[indP(i,j,img1->GetWidth())].g + (1 - factor)*img2->pixel[indP(i,j,img1->GetWidth())].g;
			img.pixel[indP(i,j,img1->GetWidth())].b = factor*img1->pixel[indP(i,j,img1->GetWidth())].b + (1 - factor)*img2->pixel[indP(i,j,img1->GetWidth())].b;

	
		}
	}	
}

void
Blender::SetFactor(float fact)
{
	factor = fact;
}
