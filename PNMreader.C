#include <PNMreader.h>
#include <cstring>
#include <iostream>
#include <fstream>
#include <iomanip>
#include <stdlib.h>

//constructor
PNMreaderCPP::PNMreaderCPP(char* fname)
{
	printf("file name: %s\nlength:%d\n", fname, (int) strlen(fname));
	filename = new char[(int) strlen(fname) + 1];
	strcpy(filename, fname);
}

//deconstructor
PNMreaderCPP::~PNMreaderCPP()
{
	printf("destructing pnmreadercpp");
	delete [] filename;
}

void
PNMreaderCPP::Execute()
{
	
	//open file
	std::ifstream file_in;
	file_in.open(filename, std::ios_base::binary);
	
	//check if file opened properly
	if(file_in.is_open()){
		//Continue on
		printf("File Open!\n");
	}else{
		//exit program with failure
		printf("Couldn't open file\n");
		exit(EXIT_FAILURE);
	}

	/* START Read Header */
	
	//initialize buffers and values for header
	char version[3];
	char dimensionBuff[32];
	char maxValBuff[32];
	int width, height, maxVal;
	
	//read version
	file_in >> version;
	
	//read width and height
	file_in >> width;
	file_in >> height;
	
	//read max value
	file_in >> maxVal;
	
	//print out values read
	printf("Width: %d, Height: %d, maxVal %d, Version: %s\n", width, height, maxVal, version);
	
	
	//Set initial params for image
	img.SetVersion(version);
	img.ResetSize(width,height);
	img.SetMaxVal(maxVal);
	printf("Width: %d, Height: %d, maxVal %d, Version: %s\n", img.GetWidth(), img.GetHeight(), img.GetMaxVal(), img.GetVersion());

	/* END Read Header */

	//move past new	 line to beginning of body content
	file_in.seekg(1, file_in.cur);
			
	/* START Read Body */
	
	//initialize counters
	int i, j;
		
		
	//loop rows
	for(i = 0; i < img.GetHeight(); i++)
	{
		//loop through elements in row
		for(j = 0; j < img.GetWidth(); j++)
		{
			//set RGB values for image at row j, column i
			file_in >> std::noskipws >> std::setw(sizeof(char)) >> img.pixel[i*img.GetWidth() + j].r;
			file_in >> std::noskipws >> std::setw(sizeof(char)) >> img.pixel[i*img.GetWidth() + j].g;
			file_in >> std::noskipws >> std::setw(sizeof(char)) >> img.pixel[i*img.GetWidth() + j].b;
		}
	}
	
	//close file connection
	file_in.close();
}

void
PNMreaderCPP::Update()
{
	printf("read");
	this->Execute();
}


//constructor
PNMreader::PNMreader(char* fname)
{
	filename = new char[1024];
	strcpy(filename, fname);
}

//deconstructor
PNMreader::~PNMreader()
{
	delete [] filename;
}

void
PNMreader::Execute()
{
	FILE *file_in = fopen(filename, "rb");

	/* START Read Header */
	
	char buffer[sizeof(int)*3 + sizeof(char)*6];
	memset(buffer, 0, sizeof(int)*3 + sizeof(char)*6);
	fread(buffer, sizeof(char), 17, file_in);
	char version[2];
	int width, height, maxVal;
	sscanf(buffer, "%s\n%d %d\n%d\n", version, &width, &height, &maxVal);
	printf("Width: %d, Height: %d, maxVal %d, Version: %s\n", width, height, maxVal, version);

	//Create Image. Set initial params.
	//img = new Image();

	img.SetVersion(version);
	img.ResetSize(width,height);
	img.SetMaxVal(maxVal);
	printf("Width: %d, Height: %d, maxVal %d, Version: %s\n", img.GetWidth(), img.GetHeight(), img.GetMaxVal(), img.GetVersion());
	/* END Read Header */
	
	
	
	printf("VERSION STR: %s\n",img.GetVersion());
	
	/* START Read Body */
	
	fseek(file_in, sizeof(char)*17, SEEK_SET);
	unsigned char rgbBuffer[sizeof(unsigned char)*3];
	int i, j;
	unsigned char curChar;

	for(i = 0; i < img.GetHeight(); i++)
	{
		for(j = 0; j < img.GetWidth(); j++)
		{
			img.pixel[i*img.GetWidth() + j].r = fgetc(file_in);
			img.pixel[i*img.GetWidth() + j].g = fgetc(file_in);
			img.pixel[i*img.GetWidth() + j].b = fgetc(file_in);
			
		
	
		}
	}
	fclose(file_in);
}
