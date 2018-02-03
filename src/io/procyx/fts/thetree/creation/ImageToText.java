package io.procyx.fts.thetree.creation;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;

public class ImageToText {

    /**
     * PROGRAM 2:
     * Print RGB*2 text from the input image.
     */
    public static void main(String[] args) throws Exception
    {
        // Tree image with code
        final BufferedImage i2 = ImageIO.read(new File(System.getProperty("user.home") + "/Desktop/coded_tree.png"));

        for(int y = 0; y < 256; y++)
            for(int x = 0; x < 256; x++)
            {
                final int rgb = i2.getRGB(x, y);
                final int red = (rgb & 0x00ff0000) >> 16, green = (rgb & 0x0000ff00) >> 8, blue = rgb & 0x000000ff;

                // Mult red, green, blue by 2
                final int red1 = red * 2, green1 = green * 2, blue1 = blue * 2;

                // Print
                System.out.println(red1 + ";" + green1 + ";" + blue1 + ";");
            }
    }
}
