package io.procyx.fts.thetree.solution;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.File;

public class DeltaImage {

    /**
     * PROGRAM 3:
     * Create an image only composed of the differents pixels between both images.
     */
    public static void main(String[] args) throws Exception
    {
        // Tree.png
        final BufferedImage i1 = ImageIO.read(new File(System.getProperty("user.home") + "/Desktop/tree.png"));
        // Image form text
        final BufferedImage i2 = ImageIO.read(new File(System.getProperty("user.home") + "/Desktop/image_from_txt.png"));
        // Result
        final BufferedImage delta = new BufferedImage(256, 256, BufferedImage.TYPE_INT_ARGB);

        for(int y = 0; y < 256; y++)
            for(int x = 0; x < 256; x++)
            {
                final int rgb1 = i1.getRGB(x, y);
                final int rgb2 = i2.getRGB(x, y);

                final int red1 = (rgb1 & 0x00ff0000) >> 16, green1 = (rgb1 & 0x0000ff00) >> 8, blue1 = rgb1 & 0x000000ff;
                final int red2 = (rgb2 & 0x00ff0000) >> 16, green2 = (rgb2 & 0x0000ff00) >> 8, blue2 = rgb2 & 0x000000ff;

                final boolean same = red1 == red2 && green1 == green2 && blue1 == blue2;

                // Write pixel if 'result' is the pixel is not the same
                if(!same)
                    delta.setRGB(x, y, rgb1);
            }

        // Output
        final File out = new File(System.getProperty("user.home") + "/Desktop/delta.png");
        ImageIO.write(delta, "png", out);
    }
}
