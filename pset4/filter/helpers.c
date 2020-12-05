#include "helpers.h"
#include <math.h>
// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            float red = image[i][j].rgbtRed;
            float blue = image[i][j].rgbtBlue;
            float green = image[i][j].rgbtGreen;

            int avg = round((red + blue + green) / 3.0);
            image[i][j].rgbtRed = image[i][j].rgbtBlue = image[i][j].rgbtGreen = avg;
        }
    }
    return;
}

int limit(int RGB)
{
    if (RGB > 255)
    {
        RGB = 255;
    }
    return RGB;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int red = image[i][j].rgbtRed;
            int blue = image[i][j].rgbtBlue;
            int green = image[i][j].rgbtGreen;

            int sepiaRed = limit(round(.393 * red + .769 * green + .189 * blue));
            int sepiaGreen = limit(round(.349 * red + .686 * green + .168 * blue));
            int sepiaBlue = limit(round(.272 * red + .534 * green + .131 * blue));

            // if(sepiaRed > 255)
            // {
            //     sepiaRed = 255;
            // }

            // if(sepiaGreen > 255)
            // {
            //     sepiaGreen = 255;
            // }

            // if(sepiaBlue > 255)
            // {
            //     sepiaBlue = 255;
            // }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtBlue = sepiaBlue;
            image[i][j].rgbtGreen = sepiaGreen;
        }
    }

    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE arr[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            arr[i][width - (j + 1)] = image[i][j];
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j] = arr[i][j];
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

	RGBTRIPLE img[height][width];
	float red;
	float green;
	float blue;

	//create a copy of original image to save original pixel values
	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			img[i][j].rgbtRed = image[i][j].rgbtRed;
			img[i][j].rgbtGreen = image[i][j].rgbtGreen;
			img[i][j].rgbtBlue = image[i][j].rgbtBlue;


		}
	}

	for (int i = 0; i < height; i++)
	{
		for (int j = 0; j < width; j++)
		{
			//if the pixel is on the top left edge
			if (j == 0 && i == 0)
			{
				red = (float)(img[i][j].rgbtRed + img[i][j + 1].rgbtRed + img[i + 1][j].rgbtRed + img[i + 1][j + 1].rgbtRed) / 4;

				green = (float)(img[i][j].rgbtGreen + img[i][j + 1].rgbtGreen + img[i + 1][j].rgbtGreen + img[i + 1][j + 1].rgbtGreen) / 4;

				blue = (float)(img[i][j].rgbtBlue + img[i][j + 1].rgbtBlue + img[i + 1][j].rgbtBlue + img[i + 1][j+1].rgbtBlue) / 4;
				red = round(red);
				blue = round(blue);
				green = round(green);

				image[i][j].rgbtRed = red;
				image[i][j].rgbtGreen = green;
				image[i][j].rgbtBlue = blue;
			}

			//if the pixel is on the lower left edge
			else if (j == 0 && i == (height - 1))
			{
				red =(float)(img[i - 1][j].rgbtRed + img[i - 1][j + 1].rgbtRed + img[i][j].rgbtRed + img[i][j + 1].rgbtRed) / 4;

				green = (float)(img[i - 1][j].rgbtGreen + img[i - 1][j + 1].rgbtGreen + img[i][j].rgbtGreen + img[i][j + 1].rgbtGreen) / 4;

				blue = (float)(img[i - 1][j].rgbtBlue + img[i - 1][j + 1].rgbtBlue + img[i][j].rgbtBlue + img[i][j + 1].rgbtBlue) / 4;


				red = round(red);
				green = round(green);
				blue = round(blue);

				image[i][j].rgbtRed = red;
				image[i][j].rgbtGreen = green;
                image[i][j].rgbtBlue = blue;
			}

			//if the pixel is on top Right
			else if (i == 0 && j == (width - 1))
			{
				red = (float)(img[i][j - 1].rgbtRed + img[i][j].rgbtRed + img[i + 1][j - 1].rgbtRed + img[i + 1][j].rgbtRed)/ 4;

				green = (float)(img[i][j - 1].rgbtGreen + img[i][j].rgbtGreen + img[i + 1][j - 1].rgbtGreen + img[i + 1][j].rgbtGreen) / 4;

				blue = (float)(img[i][j - 1].rgbtBlue + img[i][j].rgbtBlue + img[i + 1][j - 1].rgbtBlue + img[i + 1][j].rgbtBlue) / 4;

				red = round(red);
				green = round(green);
				blue = round(blue);

				image[i][j].rgbtRed = red;
				image[i][j].rgbtGreen = green;
                image[i][j].rgbtBlue = blue;
			}

			//if the pixel is on lower right
			else if(i == (height - 1) && j == (width - 1))
			{
				red = (float)(img[i - 1][j -1 ].rgbtRed + img[i - 1][j].rgbtRed + img[i][j - 1].rgbtRed + img[i][j].rgbtRed) / 4;

		 		blue = (float)(img[i - 1][j - 1].rgbtBlue + img[i - 1][j].rgbtBlue + img[i][j - 1].rgbtBlue + img[i][j].rgbtBlue) / 4;

				green = (float)(img[i - 1][j - 1].rgbtGreen + img[i - 1][j].rgbtGreen + img[i][j - 1].rgbtGreen + img[i][j].rgbtGreen) / 4;

	            red = round(red);
				green = round(green);
				blue = round(blue);

				image[i][j].rgbtRed = red;
				image[i][j].rgbtGreen = green;
                image[i][j].rgbtBlue = blue;
			}
       //if the pixel is on left side

			else if (j == 0 && (i > 0 && i < height - 1))
			{
				red = (float)(img[i - 1][j].rgbtRed + img[i - 1][j + 1].rgbtRed + img[i][j].rgbtRed + img[i][j + 1].rgbtRed + img[i + 1][j].rgbtRed + img[i + 1][j + 1].rgbtRed) / 6;

				green = (float)(img[i - 1][j].rgbtGreen + img[i - 1][j + 1].rgbtGreen + img[i][j].rgbtGreen + img[i][j + 1].rgbtGreen + img[i + 1][j].rgbtGreen + img[i + 1][j + 1].rgbtGreen) / 6;

				blue = (float)(img[i - 1][j].rgbtBlue + img[i - 1][j + 1].rgbtBlue + img[i][j].rgbtBlue + img[i][j + 1].rgbtBlue + img[i + 1][j].rgbtBlue + img[i + 1][j + 1].rgbtBlue) / 6;

				red = round(red);
				green = round(green);
				blue = round(blue);

				image[i][j].rgbtRed = red;
				image[i][j].rgbtGreen = green;
                image[i][j].rgbtBlue = blue;
			}
      //if the pixel is on right side
			else if (j == (width - 1) && (i > 0 && i < height - 1))
			{
				red = (float)(img[i - 1][j - 1].rgbtRed + img[i - 1][j].rgbtRed + img[i][j - 1].rgbtRed + img[i][j].rgbtRed + img[i + 1][j - 1].rgbtRed + img[i + 1][j].rgbtRed) / 6;

				green = (float)(img[i - 1][j - 1].rgbtGreen + img[i - 1][j].rgbtGreen + img[i][j - 1].rgbtGreen + img[i][j].rgbtGreen + img[i + 1][j - 1].rgbtGreen + img[i + 1][j].rgbtGreen) / 6;

				blue = (float)(img[i - 1][j - 1].rgbtBlue + img[i - 1][j].rgbtBlue + img[i][j - 1].rgbtBlue + img[i][j].rgbtBlue + img[i + 1][j - 1].rgbtBlue + img[i + 1][j].rgbtBlue) / 6;

				red = round(red);
				green = round(green);
				blue = round(blue);

				image[i][j].rgbtRed = red;
				image[i][j].rgbtGreen = green;
                image[i][j].rgbtBlue = blue;
			}
       //if the pixel is on upper side
			else if (i == 0 && (j > 0 &&  j < width - 1))
			{
				red = (float)(img[i][j - 1].rgbtRed + img[i][j].rgbtRed + img[i][j + 1].rgbtRed + img[i + 1][j - 1].rgbtRed + img[i + 1][j].rgbtRed + img[i + 1][j + 1].rgbtRed) / 6;

			    green = (float)(img[i][j - 1].rgbtGreen + img[i][j].rgbtGreen + img[i][j + 1].rgbtGreen + img[i + 1][j - 1].rgbtGreen + img[i + 1][j].rgbtGreen + img[i + 1][j + 1].rgbtGreen) / 6;

				blue = (float)(img[i][j - 1].rgbtBlue + img[i][j].rgbtBlue + img[i][j + 1].rgbtBlue + img[i + 1][j - 1].rgbtBlue + img[i + 1][j].rgbtBlue + img[i + 1][j + 1].rgbtBlue) / 6;

				red = round(red);
				green = round(green);
				blue = round(blue);

				image[i][j].rgbtRed = red;
				image[i][j].rgbtGreen = green;
                image[i][j].rgbtBlue = blue;
			}
       //if the pixel is on lower side
			else if  (i == height - 1 && (j > 0 && j < width - 1))
			{
				red = (float)(img[i - 1][j - 1].rgbtRed + img[i - 1][j].rgbtRed + img[i - 1][j + 1].rgbtRed + img[i][j - 1].rgbtRed + img[i][j].rgbtRed + img[i][j + 1].rgbtRed) / 6;

				green = (float)(img[i - 1][j - 1].rgbtGreen + img[i - 1][j].rgbtGreen + img[i - 1][j + 1].rgbtGreen + img[i][j - 1].rgbtGreen + img[i][j].rgbtGreen + img[i][j + 1].rgbtGreen) / 6;

				blue = (float)(img[i - 1][j - 1].rgbtBlue + img[i - 1][j].rgbtBlue + img[i - 1][j + 1].rgbtBlue + img[i][j - 1].rgbtBlue + img[i][j].rgbtBlue + img[i][j + 1].rgbtBlue) / 6;

				red = round(red);
				green = round(green);
				blue = round(blue);

				image[i][j].rgbtRed = red;
				image[i][j].rgbtGreen = green;
                image[i][j].rgbtBlue = blue;
			}
      //if the pixel is on the middle and can form a 3x3 grid
			else
			{
				red = (float)(img[i - 1][j - 1].rgbtRed + img[i - 1][j].rgbtRed + img[i - 1][j + 1].rgbtRed + img[i][j - 1].rgbtRed + img[i][j].rgbtRed + img[i][j + 1].rgbtRed + img[i + 1][j - 1].rgbtRed + img[i + 1][j].rgbtRed + img[i + 1][j + 1].rgbtRed) / 9;

				green = (float)(img[i - 1][j - 1].rgbtGreen + img[i - 1][j].rgbtGreen + img[i - 1][j + 1].rgbtGreen + img[i][j - 1].rgbtGreen + img[i][j].rgbtGreen + img[i][j + 1].rgbtGreen + img[i + 1][j - 1].rgbtGreen + img[i + 1][j].rgbtGreen + img[i + 1][j + 1].rgbtGreen) / 9;

				blue = (float)(img[i - 1][j - 1].rgbtBlue + img[i - 1][j].rgbtBlue + img[i - 1][j + 1].rgbtBlue + img[i][j - 1].rgbtBlue + img[i][j].rgbtBlue + img[i][j + 1].rgbtBlue + img[i + 1][j - 1].rgbtBlue + img[i + 1][j].rgbtBlue + img[i + 1][j + 1].rgbtBlue) / 9;

				red = round(red);
				green = round(green);
				blue = round(blue);

				image[i][j].rgbtRed = red;
				image[i][j].rgbtGreen = green;
                image[i][j].rgbtBlue = blue;
			}
		}
	}
    return;
}
