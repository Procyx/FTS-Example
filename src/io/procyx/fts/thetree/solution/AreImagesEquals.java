package io.procyx.fts.thetree.solution;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;

public class AreImagesEquals {

    /**
     * PROGRAM 2:
     * Check if 'image_from_txt.png' is equals (pixel per pixel) to 'tree.png'
     */
    public static void main(String[] args) throws Exception
    {
        // Tree.png
        final BufferedImage i1 = ImageIO.read(new File(System.getProperty("user.home") + "/Desktop/tree.png"));
        // Image from txt
        final BufferedImage i2 = ImageIO.read(new File(System.getProperty("user.home") + "/Desktop/image_from_txt.png"));

        for(int y = 0; y < 256; y++)
            for(int x = 0; x < 256; x++)
            {
                final int rgb1 = i1.getRGB(x, y);
                final int rgb2 = i2.getRGB(x, y);

                final int red1 = (rgb1 & 0x00ff0000) >> 16, green1 = (rgb1 & 0x0000ff00) >> 8, blue1 = rgb1 & 0x000000ff;
                final int red2 = (rgb2 & 0x00ff0000) >> 16, green2 = (rgb2 & 0x0000ff00) >> 8, blue2 = rgb2 & 0x000000ff;

                final boolean same1 = red1 == red2 && green1 == green2 && blue1 == blue2;

                // Exist if a pixel is different
                if(!same1)
                {
                    System.out.println("Images are not equals!");
                    System.exit(0);
                }
            }

        System.out.println("Images are equals!");
    }
}
