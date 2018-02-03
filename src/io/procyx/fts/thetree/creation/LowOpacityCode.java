package io.procyx.fts.thetree.creation;

import javax.imageio.ImageIO;
import javax.swing.*;
import java.awt.image.BufferedImage;
import java.io.File;

public class LowOpacityCode {

    /**
     * PROGRAM 1:
     * Create a low opacity image of the initial code image.
     */
    public static void main(String[] args) throws Exception
    {
        // Choose the initial code image
        final JFileChooser chooser = new JFileChooser();
        chooser.setMultiSelectionEnabled(false);
        chooser.showOpenDialog(new JFrame());

        final BufferedImage in = ImageIO.read(chooser.getSelectedFile());
        // Result
        final BufferedImage code = new BufferedImage(256, 256, BufferedImage.TYPE_INT_ARGB);

        // Alpha value
        int alpha = 10;
        alpha %= 0xff;
        final int used = (alpha << 24) | 0x00ffffff;

        for(int y = 0; y < 256; y++)
            for(int x = 0; x < 256; x++)
            {
                final int rgb = in.getRGB(x, y);

                if (rgb == 0)
                    continue;

                // If pixel rgb != 0, applying alpha
                final int newcolor = rgb & used;
                code.setRGB(x, y, newcolor);
            }

        // Output
        final File out = new File(System.getProperty("user.home") + "/Desktop/low_opacity_code.png");
        ImageIO.write(code, "png", out);
    }
}
