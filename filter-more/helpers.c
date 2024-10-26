#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int ave = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed) / 3.0);
            image[i][j].rgbtBlue = ave;
            image[i][j].rgbtGreen = ave;
            image[i][j].rgbtRed = ave;
        }
    }
    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < round(width / 2); j++)
        {
            RGBTRIPLE temp = image[i][j];
            image[i][j] = image[i][(width - 1 - j)];
            image[i][(width - 1 - j)] = temp;
        }
    }
    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumBlue = 0;
            int sumGreen = 0;
            int sumRed = 0;
            int count = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    if (((i + k) < 0) || ((i + k) >= height))
                    {
                        continue;
                    }

                    if (((j + l) < 0) || ((j + l) >= width))
                    {
                        continue;
                    }

                    sumBlue += image[i + k][j + l].rgbtBlue;
                    sumGreen += image[i + k][j + l].rgbtGreen;
                    sumRed += image[i + k][j + l].rgbtRed;
                    count++;
                }
            }

            temp[i][j].rgbtBlue = round(sumBlue / (count / 1.0));
            temp[i][j].rgbtGreen = round(sumGreen / (count / 1.0));
            temp[i][j].rgbtRed = round(sumRed / (count / 1.0));
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }

    return;
}

// Detect edges
void edges(int height, int width, RGBTRIPLE image[height][width])
{
    RGBTRIPLE temp[height][width];
    int weightX[3][3] = {{-1, 0, 1}, {-2, 0, 2}, {-1, 0, 1}};
    int weightY[3][3] = {{-1, -2, -1}, {0, 0, 0}, {1, 2, 1}};

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sumBluex = 0;
            int sumGreenx = 0;
            int sumRedx = 0;

            int sumBluey = 0;
            int sumGreeny = 0;
            int sumRedy = 0;

            for (int k = -1; k < 2; k++)
            {
                for (int l = -1; l < 2; l++)
                {
                    // handle the edges of the image.
                    if ((i + k) < 0 || (i + k) >= height)
                    {
                        continue;
                    }

                    if ((j + l) < 0 || (j + l) >= width)
                    {
                        continue;
                    }

                    sumBluex += image[i + k][j + l].rgbtBlue * weightX[k + 1][l + 1];
                    sumGreenx += image[i + k][j + l].rgbtGreen * weightX[k + 1][l + 1];
                    sumRedx += image[i + k][j + l].rgbtRed * weightX[k + 1][l + 1];

                    sumBluey += image[i + k][j + l].rgbtBlue * weightY[k + 1][l + 1];
                    sumGreeny += image[i + k][j + l].rgbtGreen * weightY[k + 1][l + 1];
                    sumRedy += image[i + k][j + l].rgbtRed * weightY[k + 1][l + 1];
                }
            }

            //square root of Gx * Gx + Gy * Gy
            int blue = round(sqrt(sumBluex * sumBluex + sumBluey * sumBluey));
            int green = round(sqrt(sumGreenx * sumGreenx + sumGreeny * sumGreeny));
            int red = round(sqrt(sumRedx * sumRedx + sumRedy * sumRedy));

            //need to get the RGB values capped in 255. ?:
            temp[i][j].rgbtBlue = (blue > 255) ? 255 : blue;
            temp[i][j].rgbtGreen = (green > 255) ? 255 : green;
            temp[i][j].rgbtRed = (red > 255) ? 255 : red;
        }
    }

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
            image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
            image[i][j].rgbtRed = temp[i][j].rgbtRed;
        }
    }
    return;
}
