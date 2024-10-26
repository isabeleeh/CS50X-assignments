#include "helpers.h"

#include <math.h>
#include <stdio.h>

int main(void)
{
    int height = 3;
    int width = 3;
    RGBTRIPLE image[height][width];
    image[0][0].rgbtBlue = 0;
    image[0][0].rgbtGreen = 10;
    image[0][0].rgbtRed = 25;

    image[0][1].rgbtBlue = 0;
    image[0][1].rgbtGreen = 10;
    image[0][1].rgbtRed = 30;

    image[0][2].rgbtBlue = 40;
    image[0][2].rgbtGreen = 60;
    image[0][2].rgbtRed = 80;

    image[1][0].rgbtBlue = 20;
    image[1][0].rgbtGreen = 30;
    image[1][0].rgbtRed = 90;

    image[1][1].rgbtBlue = 30;
    image[1][1].rgbtGreen = 40;
    image[1][1].rgbtRed = 100;

    image[1][2].rgbtBlue = 80;
    image[1][2].rgbtGreen = 70;
    image[1][2].rgbtRed = 90;

    image[2][0].rgbtBlue = 20;
    image[2][0].rgbtGreen = 20;
    image[2][0].rgbtRed = 40;

    image[2][1].rgbtBlue = 30;
    image[2][1].rgbtGreen = 10;
    image[2][1].rgbtRed = 30;

    image[2][2].rgbtBlue = 50;
    image[2][2].rgbtGreen = 40;
    image[2][2].rgbtRed = 10;

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

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            printf("%i ", image[i][j].rgbtBlue);
            printf("%i ", image[i][j].rgbtGreen);
            printf("%i ", image[i][j].rgbtRed);
            printf("\n");
        }
    }
}