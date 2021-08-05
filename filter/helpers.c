#include "helpers.h"
#include <math.h>

// Convert image to grayscale
void grayscale(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int gray = round((image[i][j].rgbtBlue + image[i][j].rgbtGreen + image[i][j].rgbtRed)/3.0);

            image[i][j].rgbtBlue = gray;

            image[i][j].rgbtGreen = gray;

            image[i][j].rgbtRed = gray;

        }
    }

    return;
}

// Convert image to sepia
void sepia(int height, int width, RGBTRIPLE image[height][width])
{

    for (int i = 0; i < height; i++)
    {
        for (int j = 0; j < width; j++)
        {
            int sepiaRed = round(.393 * image[i][j].rgbtRed + .769 * image[i][j].rgbtGreen + .189 * image[i][j].rgbtBlue);

            int sepiaGreen = round(.349 * image[i][j].rgbtRed + .686 * image[i][j].rgbtGreen + .168 * image[i][j].rgbtBlue);

            int sepiaBlue = round(.272 * image[i][j].rgbtRed + .534 * image[i][j].rgbtGreen + .131 * image[i][j].rgbtBlue);

            if (sepiaRed > 255)
            {
                sepiaRed = 255;
            }


            if (sepiaGreen > 255)
            {
                sepiaGreen = 255;
            }

            if (sepiaBlue > 255)
            {
                sepiaBlue = 255;
            }

            image[i][j].rgbtRed = sepiaRed;
            image[i][j].rgbtGreen = sepiaGreen;
            image[i][j].rgbtBlue = sepiaBlue;

        }
    }


    return;
}

// Reflect image horizontally
void reflect(int height, int width, RGBTRIPLE image[height][width])
{
 for (int i = 0; i < height; i++)
 {
     for (int j = 0; j < width / 2; j++)
     {
         int tempRed = image[i][j].rgbtRed;
         image[i][j].rgbtRed = image[i][width - (j + 1)].rgbtRed;
         image[i][width - (j + 1)].rgbtRed = tempRed;

         int tempGreen = image[i][j].rgbtGreen;
         image[i][j].rgbtGreen = image[i][width - (j + 1)].rgbtGreen;
         image[i][width - (j + 1)].rgbtGreen = tempGreen;

         int tempBlue = image[i][j].rgbtBlue;
         image[i][j].rgbtBlue = image[i][width - (j + 1)].rgbtBlue;
         image[i][width - (j + 1)].rgbtBlue = tempBlue;
     }
 }

    return;
}

// Blur image
void blur(int height, int width, RGBTRIPLE image[height][width])
{

  int sumRed;
  int sumGreen;
  int sumBlue;
  float count;
  RGBTRIPLE temp [height][width];

   for(int i = 0; i < height; i++)
   {
       for(int j = 0; j < width; j++)
       {
         sumRed = 0;
         sumGreen = 0;
         sumBlue = 0;
         count = 0.00;

         for(int k = -1; k < 2; k++)
         {
             for(int l = -1; l < 2; l++)
             {
                 if((i+k) < 0 || (j+l) < 0 || (i+k) > (height-1) || (j+l) > (width -1))
                 {
                     continue;
                 }


                 sumRed += image[i+k][j+l].rgbtRed;
                 sumGreen += image[i+k][j+l].rgbtGreen;
                 sumBlue += image[i+k][j+l].rgbtBlue;
                 count++;



                 temp[i][j].rgbtRed = round(sumRed/count);
                 temp[i][j].rgbtGreen = round(sumGreen/count);
                 temp[i][j].rgbtBlue = round(sumBlue/count);
             }
         }

       }

   }
  for(int i = 0; i < height; i++)
  {
      for(int j = 0; j < width; j++)
      {
          image[i][j].rgbtRed = temp[i][j].rgbtRed;
          image[i][j].rgbtGreen = temp[i][j].rgbtGreen;
          image[i][j].rgbtBlue = temp[i][j].rgbtBlue;
      }
  }





   return;
}
