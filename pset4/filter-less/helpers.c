#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    // loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // average rbg and apply it
            int avg = (int) round(
                ((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0));
            image[i][j].rgbtBlue = avg;
            image[i][j].rgbtGreen = avg;
            image[i][j].rgbtRed = avg;
        }
    }
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{
    // loop over all pixels
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // get the values for rgb sepia and assign them accordingly
            int sRed = (int) round(image[i][j].rgbtBlue * .189 + image[i][j].rgbtGreen * .769 +
                                   image[i][j].rgbtRed * .393);
            if (sRed > 255)
                sRed = 255;

            int sGreen = (int) round(image[i][j].rgbtBlue * .168 + image[i][j].rgbtGreen * .686 +
                                     image[i][j].rgbtRed * .349);
            if (sGreen > 255)
                sGreen = 255;

            int sBlue = (int) round(image[i][j].rgbtBlue * .131 + image[i][j].rgbtGreen * .534 +
                                    image[i][j].rgbtRed * 0.272);
            if (sBlue > 255)
                sBlue = 255;
            image[i][j].rgbtRed = sRed;
            image[i][j].rgbtGreen = sGreen;
            image[i][j].rgbtBlue = sBlue;
        }
    }
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    // trying another way of assigning values
    RGBTRIPLE rgb;

    // loop over half the rows (already moving 2 pixels)
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width / 2; j++)
        {
            // store and reassign values accordingly
            rgb = image[i][j];
            image[i][j] = image[i][width - j - 1];
            image[i][width - j - 1] = rgb;
        }
    }
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    // copy image to not affect blurring of other pixels
    RGBTRIPLE copy[height][width];
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            // variables to store the rgb values of neighboring pixels and the total pixels added
            copy[i][j] = image[i][j];
        }
    }
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int aRed = 0, aGreen = 0, aBlue = 0;
            int divide = 0;

            // iterate over each neighboring pixels in a 3x3
            for (int bi = -1; bi < 2; bi++)
            {
                for (int bj = -1; bj < 2; bj++)
                {
                    int ii = bi + i;
                    int jj = bj + j;

                    // check if that pixel exists, so it doesn't not go out of bounds
                    if (ii >= 0 && ii < height && jj >= 0 && jj < width)
                    {
                        aRed += copy[ii][jj].rgbtRed;
                        aGreen += copy[ii][jj].rgbtGreen;
                        aBlue += copy[ii][jj].rgbtBlue;
                        divide++;
                    }
                }
            }
            // properly assign the blurred values to each pixel on image
            image[i][j].rgbtRed = (int) round((float) aRed / divide);
            image[i][j].rgbtGreen = (int) round((float) aGreen / divide);
            image[i][j].rgbtBlue = (int) round((float) aBlue / divide);
        }
    }
}
