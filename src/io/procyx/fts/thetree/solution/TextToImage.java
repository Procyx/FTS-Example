package io.procyx.fts.thetree.solution;

import javax.imageio.ImageIO;
import java.awt.image.BufferedImage;
import java.io.BufferedReader;
import java.io.File;
import java.io.FileReader;

public class TextToImage {

    /**
     * PROGRAM 1:
     * Create an image from 'code.txt'
     */
    public static void main(String[] args) throws Exception
    {
        // Reader
        final BufferedReader reader = new BufferedReader(new FileReader(new File(System.getProperty("user.home") + "/Desktop/code.txt")));
        // Result image
        final BufferedImage result = new BufferedImage(256, 256, BufferedImage.TYPE_INT_ARGB);

        int x = 0, y = 0;

        String line;
        while ((line = reader.readLine()) != null)
        {
            final String[] splitted = line.split(";");

            // Values divided by 2 (decoded)
            final int rVal = Integer.valueOf(splitted[0]) / 2;
            final int gVal = Integer.valueOf(splitted[1]) / 2;
            final int bVal = Integer.valueOf(splitted[2]) / 2;

            // Setting result pixel
            result.setRGB(x, y, new java.awt.Color(rVal, gVal, bVal).getRGB());

            // Updated pixel coordinates
            x++;
            if(x >= 256)
            {
                y++;
                x = 0;
            }
        }

        // Output
        final File out = new File(System.getProperty("user.home") + "/Desktop/image_from_txt.png");
        ImageIO.write(result, "png", out);
    }
}
