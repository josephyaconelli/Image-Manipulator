#include <PNMwriter.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>

void
PNMwriterCPP::Write(char* filename)
{
	//initialize counters
	int i, j;

	//open file
	std::ofstream file_out;
	file_out.open(filename, std::ios_base::binary | std::ofstream::trunc);
	
	//print info
	printf("Ver:P6\nDimensions:%d %d\nMaxVal:%d\n",
			img1->GetWidth(),
			img1->GetHeight(),	
			img1->GetMaxVal());
	
	//write image header
	file_out << "P6"
			 << '\n'
			 << img1->GetWidth()
			 << " "
			 << img1->GetHeight()
			 << '\n'
			 << img1->GetMaxVal()
			 << '\n';

	//write image body
	for(i = 0; i < img1->GetHeight(); i++)
	{
		for(j = 0; j < img1->GetWidth(); j++)
		{
			file_out << img1->pixel[i*img1->GetWidth() + j].r
					 << img1->pixel[i*img1->GetWidth() + j].g
					 << img1->pixel[i*img1->GetWidth() + j].b;
		}
	}
	
	file_out.close();
	
}


void
PNMwriter::Write(char* filename)
{
	int i, j;
	unsigned char point[3];
	FILE *file_out = fopen(filename, "ab+");
	
	
	printf("Ver:P6\nDimensions:%d %d\nMaxVal:%d\n",
			img1->GetWidth(),
			img1->GetHeight(),	
			img1->GetMaxVal());
	
	fprintf(file_out,"P6\n%d %d\n%d\n",
			img1->GetWidth(),
			img1->GetHeight(),	
			img1->GetMaxVal());
			
	for(i = 0; i < img1->GetHeight(); i++)
	{
		for(j = 0; j < img1->GetWidth(); j++)
		{
			point[0] = img1->pixel[i*img1->GetWidth() + j].r;
			point[1] = img1->pixel[i*img1->GetWidth() + j].g;
			point[2] = img1->pixel[i*img1->GetWidth() + j].b;

			fwrite(point, sizeof(unsigned char), 3, file_out);
		}
	}
	fclose(file_out);
}
